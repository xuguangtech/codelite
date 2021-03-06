#ifndef CLSTATUSBAR_H
#define CLSTATUSBAR_H

#include "wxCustomStatusBar.h" // Base class: wxCustomStatusBar
#include "codelite_exports.h"
#include <wx/bitmap.h>
#include "cl_command_event.h"

class IManager;
class WXDLLIMPEXP_SDK clStatusBar : public wxCustomStatusBar
{
    IManager* m_mgr;
    wxBitmap m_bmpBuild;
    wxBitmap m_bmpBuildError;
    wxBitmap m_bmpBuildWarnings;

protected:
    void OnPageChanged(wxCommandEvent& event);
    void OnThemeChanged(wxCommandEvent& event);
    void OnAllEditorsClosed(wxCommandEvent& event);
    void OnBuildStarted(clBuildEvent& event);
    void OnBuildEnded(clBuildEvent& event);
    void OnWorkspaceClosed(wxCommandEvent& event);
    void OnFieldClicked(clCommandEvent& event);

    void DoUpdateColour();
    void DoSetLinePosColumn(const wxString& message);

    void SetBuildBitmap(const wxBitmap& bmp, const wxString& tooltip);

public:
    clStatusBar(wxWindow* parent, IManager* mgr);
    virtual ~clStatusBar();

    /**
     * @brief clear all text fields from the status bar
     */
    void Clear();

    /**
     * @brief set a status bar message
     */
    void SetMessage(const wxString& message);
    
    /**
     * @brief set the whitespace information (Tabs vs Spaces)
     * @param whitespaceInfo
     */
    void SetWhitespaceInfo(const wxString& whitespaceInfo);
    
    /**
     * @brief update the language field
     */
    void SetLanguage(const wxString& lang);

    /**
     * @brief update the line / column / pos field
     */
    void SetLinePosColumn(const wxString& lineCol);

    /**
     * @brief start the animation
     * @param refreshRate refresh rate in milliseconds
     * @param tooltip set the tooltip for this field
     */
    void StartAnimation(long refreshRate, const wxString& tooltip);

    /**
     * @brief stop the animation
     */
    void StopAnimation();
};

#endif // CLSTATUSBAR_H
