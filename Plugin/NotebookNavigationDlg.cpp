#include "NotebookNavigationDlg.h"
#include <list>
#include "Notebook.h"
#include <algorithm>
#include "globals.h"
#include <wx/app.h>
#include <wx/dynarray.h>
#include <map>
#include <imanager.h>
#include "bitmap_loader.h"

struct TabData {
    wxString label;
    wxBitmap bmp;
    wxFileName filename;
    int index;
    bool isFile;

    TabData()
        : index(wxNOT_FOUND)
        , isFile(false)
    {
    }
};

NotebookNavigationDlg::NotebookNavigationDlg(wxWindow* parent, Notebook* book)
    : NotebookNavigationDlgBase(parent)
    , m_book(book)
    , m_selection(wxNOT_FOUND)
{
    clTab::Vec_t allTabs;
    clTabHistory::Ptr_t history = m_book->GetHistory();
    clGetManager()->GetAllTabs(allTabs);

    BitmapLoader::BitmapMap_t bmps = clGetManager()->GetStdIcons()->MakeStandardMimeMap();

    std::map<void*, clTab> tabsInfoMap;
    for(size_t i = 0; i < allTabs.size(); ++i) {
        tabsInfoMap.insert(std::make_pair((void*)allTabs.at(i).window, allTabs.at(i)));
    }

    const wxArrayPtrVoid& windows = history->GetHistory();
    // Populate the list
    for(size_t i = 0; i < windows.GetCount(); ++i) {
        int index = m_book->FindPage((wxWindow*)windows.Item(i));
        if(index != wxNOT_FOUND) {
            wxString label = m_book->GetPageText(index);
            wxBitmap bmp = m_book->GetPageBitmap(index);

            wxVector<wxVariant> cols;
            TabData* d = new TabData;
            d->bmp = bmp;
            d->label = label;
            d->index = index;

            // add extra info
            std::map<void*, clTab>::iterator iter = tabsInfoMap.find(windows.Item(i));
            if(iter != tabsInfoMap.end()) {
                d->isFile = iter->second.isFile;
                d->filename = iter->second.filename;
            }

            // Prepare the display item
            wxString text;
            if(d->isFile && d->filename.GetDirCount()) {
                wxFileName fn(d->filename.GetFullName());
                fn.AppendDir(d->filename.GetDirs().Last());
                text << fn.GetFullPath();
            } else {
                text << d->label;
            }

            // If the tab has a bitmap - use it
            // otherwise, try to assign one
            if(!d->bmp.IsOk()) {
                if(d->isFile) {
                    FileExtManager::FileType type =
                        FileExtManager::GetType(d->filename.GetFullName(), FileExtManager::TypeText);
                    if(bmps.count(type)) {
                        d->bmp = bmps.find(type)->second;
                    }
                }
            }

            cols.push_back(::MakeIconText(text, d->bmp));
            m_dvListCtrl->AppendItem(cols, (wxUIntPtr)d);
        }
    }

    if(m_dvListCtrl->GetItemCount() > 1) {
        m_dvListCtrl->Select(m_dvListCtrl->RowToItem(1));
    } else {
        m_dvListCtrl->Select(m_dvListCtrl->RowToItem(0));
    }
    m_dvListCtrl->SetFocus();
    wxTheApp->Bind(wxEVT_KEY_DOWN, &NotebookNavigationDlg::OnKeyDown, this);
    wxTheApp->Bind(wxEVT_KEY_UP, &NotebookNavigationDlg::OnKeyUp, this);
}

NotebookNavigationDlg::~NotebookNavigationDlg()
{
    for(int i = 0; i < m_dvListCtrl->GetItemCount(); ++i) {
        TabData* d = (TabData*)m_dvListCtrl->GetItemData(m_dvListCtrl->RowToItem(i));
        wxDELETE(d);
    }
    m_dvListCtrl->DeleteAllItems();
    wxTheApp->Unbind(wxEVT_KEY_DOWN, &NotebookNavigationDlg::OnKeyDown, this);
    wxTheApp->Unbind(wxEVT_KEY_UP, &NotebookNavigationDlg::OnKeyUp, this);
}

void NotebookNavigationDlg::CloseDialog()
{
    wxDataViewItem selection = m_dvListCtrl->GetSelection();
    if(selection.IsOk()) {
        TabData* d = (TabData*)m_dvListCtrl->GetItemData(selection);
        m_selection = d->index;
    }
    EndModal(wxID_OK);
}

void NotebookNavigationDlg::OnKeyDown(wxKeyEvent& event)
{
    if(event.GetKeyCode() == WXK_TAB && event.ControlDown() && event.ShiftDown()) {
        // Navigate Up
        wxDataViewItem item = m_dvListCtrl->GetSelection();
        if(item.IsOk()) {
            int row = m_dvListCtrl->ItemToRow(item);
            if(row > 0) {
                --row;
                item = m_dvListCtrl->RowToItem(row);
                m_dvListCtrl->Select(item);
                m_dvListCtrl->EnsureVisible(item);
                
            } else {
                // Select the last item
                row = m_dvListCtrl->GetItemCount() - 1;
                item = m_dvListCtrl->RowToItem(row);
                m_dvListCtrl->Select(item);
                m_dvListCtrl->EnsureVisible(item);
            }
        }
    } else if(event.GetKeyCode() == WXK_TAB && event.ControlDown()) {
        // Navigate Down
        wxDataViewItem item = m_dvListCtrl->GetSelection();
        if(item.IsOk()) {
            int row = m_dvListCtrl->ItemToRow(item);
            if(row < (m_dvListCtrl->GetItemCount() - 1)) {
                ++row;
                item = m_dvListCtrl->RowToItem(row);
                m_dvListCtrl->Select(item);
                m_dvListCtrl->EnsureVisible(item);
            } else {
                // Select the last item
                item = m_dvListCtrl->RowToItem(0);
                m_dvListCtrl->Select(item);
                m_dvListCtrl->EnsureVisible(item);
            }
        }

    } else {
        event.Skip();
    }
}

void NotebookNavigationDlg::OnKeyUp(wxKeyEvent& event)
{
    if(event.GetKeyCode() == WXK_CONTROL) {
        CloseDialog();
    } else {
        event.Skip();
    }
}
void NotebookNavigationDlg::OnItemActivated(wxDataViewEvent& event)
{
    event.Skip();
    CloseDialog();
}
