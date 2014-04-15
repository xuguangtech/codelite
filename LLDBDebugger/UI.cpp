//////////////////////////////////////////////////////////////////////
// This file was auto-generated by codelite's wxCrafter Plugin
// wxCrafter project file: UI.wxcp
// Do not modify this file by hand!
//////////////////////////////////////////////////////////////////////

#include "UI.h"


// Declare the bitmap loading function
extern void wxCrafternz79PnInitBitmapResources();

static bool bBitmapLoaded = false;


LLDBCallStackBase::LLDBCallStackBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer2 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer2);
    
    m_dvListCtrlBacktrace = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxDV_ROW_LINES|wxDV_SINGLE);
    
    boxSizer2->Add(m_dvListCtrlBacktrace, 1, wxALL|wxEXPAND, 2);
    
    m_dvListCtrlBacktrace->AppendTextColumn(_("#"), wxDATAVIEW_CELL_INERT, 40, wxALIGN_LEFT);
    m_dvListCtrlBacktrace->AppendTextColumn(_("Function"), wxDATAVIEW_CELL_INERT, 200, wxALIGN_LEFT);
    m_dvListCtrlBacktrace->AppendTextColumn(_("File"), wxDATAVIEW_CELL_INERT, 300, wxALIGN_LEFT);
    m_dvListCtrlBacktrace->AppendTextColumn(_("Line"), wxDATAVIEW_CELL_INERT, -2, wxALIGN_LEFT);
    
    SetSizeHints(500,300);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_dvListCtrlBacktrace->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(LLDBCallStackBase::OnItemActivated), NULL, this);
    
}

LLDBCallStackBase::~LLDBCallStackBase()
{
    m_dvListCtrlBacktrace->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(LLDBCallStackBase::OnItemActivated), NULL, this);
    
}

LLDBBreakpointsPaneBase::LLDBBreakpointsPaneBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer10 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer10);
    
    m_auibar = new wxAuiToolBar(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxAUI_TB_PLAIN_BACKGROUND|wxAUI_TB_DEFAULT_STYLE);
    m_auibar->SetToolBitmapSize(wxSize(16,16));
    
    boxSizer10->Add(m_auibar, 0, wxEXPAND, 5);
    
    m_auibar->AddTool(wxID_NEW, _("New breakpoint"), wxArtProvider::GetBitmap(wxART_PLUS, wxART_TOOLBAR, wxSize(16, 16)), wxNullBitmap, wxITEM_NORMAL, _("New breakpoint"), _("New breakpoint"), NULL);
    
    m_auibar->AddTool(wxID_DELETE, _("Delete Selected Breakpoint"), wxArtProvider::GetBitmap(wxART_MINUS, wxART_TOOLBAR, wxSize(16, 16)), wxNullBitmap, wxITEM_NORMAL, _("Delete Selected Breakpoint"), _("Delete Selected Breakpoint"), NULL);
    
    m_auibar->AddTool(wxID_CLEAR, _("Delete All Breakpoints"), wxArtProvider::GetBitmap(wxART_DELETE, wxART_TOOLBAR, wxSize(16, 16)), wxNullBitmap, wxITEM_NORMAL, _("Delete All Breakpoints"), _("Delete All Breakpoints"), NULL);
    m_auibar->Realize();
    
    m_dataview = new wxDataViewCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxDV_ROW_LINES|wxDV_SINGLE);
    
    m_dataviewModel = new LLDBBreakpointModel;
    m_dataviewModel->SetColCount( 4 );
    m_dataview->AssociateModel(m_dataviewModel.get() );
    
    boxSizer10->Add(m_dataview, 1, wxALL|wxEXPAND, 2);
    
    m_dataview->AppendTextColumn(_("#"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_INERT, 40, wxALIGN_LEFT);
    m_dataview->AppendTextColumn(_("File"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_INERT, 200, wxALIGN_LEFT);
    m_dataview->AppendTextColumn(_("Line"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_INERT, 40, wxALIGN_LEFT);
    m_dataview->AppendTextColumn(_("Function"), m_dataview->GetColumnCount(), wxDATAVIEW_CELL_INERT, 200, wxALIGN_LEFT);
    
    SetSizeHints(500,300);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    this->Connect(wxID_NEW, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBBreakpointsPaneBase::OnNewBreakpoint), NULL, this);
    this->Connect(wxID_NEW, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBBreakpointsPaneBase::OnNewBreakpointUI), NULL, this);
    this->Connect(wxID_DELETE, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBBreakpointsPaneBase::OnDeleteBreakpointUI), NULL, this);
    this->Connect(wxID_DELETE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBBreakpointsPaneBase::OnDeleteBreakpoint), NULL, this);
    this->Connect(wxID_CLEAR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBBreakpointsPaneBase::OnDeleteAll), NULL, this);
    this->Connect(wxID_CLEAR, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBBreakpointsPaneBase::OnDeleteAllUI), NULL, this);
    m_dataview->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(LLDBBreakpointsPaneBase::OnBreakpointActivated), NULL, this);
    
}

LLDBBreakpointsPaneBase::~LLDBBreakpointsPaneBase()
{
    this->Disconnect(wxID_NEW, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBBreakpointsPaneBase::OnNewBreakpoint), NULL, this);
    this->Disconnect(wxID_NEW, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBBreakpointsPaneBase::OnNewBreakpointUI), NULL, this);
    this->Disconnect(wxID_DELETE, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBBreakpointsPaneBase::OnDeleteBreakpointUI), NULL, this);
    this->Disconnect(wxID_DELETE, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBBreakpointsPaneBase::OnDeleteBreakpoint), NULL, this);
    this->Disconnect(wxID_CLEAR, wxEVT_COMMAND_TOOL_CLICKED, wxCommandEventHandler(LLDBBreakpointsPaneBase::OnDeleteAll), NULL, this);
    this->Disconnect(wxID_CLEAR, wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBBreakpointsPaneBase::OnDeleteAllUI), NULL, this);
    m_dataview->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(LLDBBreakpointsPaneBase::OnBreakpointActivated), NULL, this);
    
}

LLDBNewBreakpointDlgBase::LLDBNewBreakpointDlgBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer32 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer32);
    
    wxFlexGridSizer* flexGridSizer41 = new wxFlexGridSizer(0, 3, 0, 0);
    flexGridSizer41->SetFlexibleDirection( wxBOTH );
    flexGridSizer41->SetNonFlexibleGrowMode( wxFLEX_GROWMODE_SPECIFIED );
    flexGridSizer41->AddGrowableCol(1);
    
    boxSizer32->Add(flexGridSizer41, 1, wxALL|wxEXPAND, 5);
    
    m_checkBoxFileLine = new wxCheckBox(this, wxID_ANY, _("File and Line:"), wxDefaultPosition, wxSize(-1,-1), wxALIGN_RIGHT);
    m_checkBoxFileLine->SetValue(false);
    
    flexGridSizer41->Add(m_checkBoxFileLine, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlFile = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    m_textCtrlFile->SetToolTip(_("File name"));
    
    flexGridSizer41->Add(m_textCtrlFile, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlLine = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    m_textCtrlLine->SetToolTip(_("Line number"));
    
    flexGridSizer41->Add(m_textCtrlLine, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    
    m_checkBoxFuncName = new wxCheckBox(this, wxID_ANY, _("Function name:"), wxDefaultPosition, wxSize(-1,-1), wxALIGN_RIGHT);
    m_checkBoxFuncName->SetValue(false);
    
    flexGridSizer41->Add(m_checkBoxFuncName, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5);
    
    m_textCtrlFunctionName = new wxTextCtrl(this, wxID_ANY, wxT(""), wxDefaultPosition, wxSize(-1,-1), 0);
    
    flexGridSizer41->Add(m_textCtrlFunctionName, 0, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5);
    
    flexGridSizer41->Add(0, 0, 1, wxALL, 5);
    
    m_stdBtnSizer34 = new wxStdDialogButtonSizer();
    
    boxSizer32->Add(m_stdBtnSizer34, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button36 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button36->SetDefault();
    m_stdBtnSizer34->AddButton(m_button36);
    
    m_button38 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer34->AddButton(m_button38);
    m_stdBtnSizer34->Realize();
    
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_checkBoxFileLine->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(LLDBNewBreakpointDlgBase::OnCheckFileAndLine), NULL, this);
    m_textCtrlFile->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBNewBreakpointDlgBase::OnFileLineEnabledUI), NULL, this);
    m_textCtrlLine->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBNewBreakpointDlgBase::OnFileLineEnabledUI), NULL, this);
    m_checkBoxFuncName->Connect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(LLDBNewBreakpointDlgBase::OnCheckFuncName), NULL, this);
    m_textCtrlFunctionName->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBNewBreakpointDlgBase::OnFuncNameUI), NULL, this);
    
}

LLDBNewBreakpointDlgBase::~LLDBNewBreakpointDlgBase()
{
    m_checkBoxFileLine->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(LLDBNewBreakpointDlgBase::OnCheckFileAndLine), NULL, this);
    m_textCtrlFile->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBNewBreakpointDlgBase::OnFileLineEnabledUI), NULL, this);
    m_textCtrlLine->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBNewBreakpointDlgBase::OnFileLineEnabledUI), NULL, this);
    m_checkBoxFuncName->Disconnect(wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler(LLDBNewBreakpointDlgBase::OnCheckFuncName), NULL, this);
    m_textCtrlFunctionName->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBNewBreakpointDlgBase::OnFuncNameUI), NULL, this);
    
}

LLDBLocalsViewBase::LLDBLocalsViewBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer67 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer67);
    
    SetMinSize( wxSize(200,200) );
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
}

LLDBLocalsViewBase::~LLDBLocalsViewBase()
{
}

LLDBSettingDialogBase::LLDBSettingDialogBase(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style)
    : wxDialog(parent, id, title, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer77 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer77);
    
    m_notebook87 = new wxNotebook(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxBK_DEFAULT);
    
    boxSizer77->Add(m_notebook87, 1, wxALL|wxEXPAND, 5);
    
    m_panel89 = new wxPanel(m_notebook87, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_notebook87->AddPage(m_panel89, _("Display"), true);
    
    wxBoxSizer* boxSizer93 = new wxBoxSizer(wxVERTICAL);
    m_panel89->SetSizer(boxSizer93);
    
    wxArrayString m_pgMgrDisplayPropertiesArr;
    wxUnusedVar(m_pgMgrDisplayPropertiesArr);
    wxArrayInt m_pgMgrDisplayPropertiesIntArr;
    wxUnusedVar(m_pgMgrDisplayPropertiesIntArr);
    m_pgMgrDisplayProperties = new wxPropertyGridManager(m_panel89, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxPG_DESCRIPTION|wxPG_SPLITTER_AUTO_CENTER|wxPG_BOLD_MODIFIED);
    
    boxSizer93->Add(m_pgMgrDisplayProperties, 1, wxALL|wxEXPAND, 5);
    
    m_pgPropCatGeneral = m_pgMgrDisplayProperties->Append(  new wxPropertyCategory( _("General") ) );
    m_pgPropCatGeneral->SetHelpString(wxT(""));
    
    m_pgPropRaiseCodeLite = m_pgMgrDisplayProperties->AppendIn( m_pgPropCatGeneral,  new wxBoolProperty( _("Raise CodeLite when breakpoint hit"), wxPG_LABEL, 1) );
    m_pgPropRaiseCodeLite->SetHelpString(_("When a breakpoint is hit, notify the user raising CodeLite"));
    
    m_pgPropArraySize = m_pgMgrDisplayProperties->AppendIn( m_pgPropCatGeneral,  new wxIntProperty( _("Max number of array elements"), wxPG_LABEL, 50) );
    m_pgPropArraySize->SetHelpString(_("The maximum number of eleements to display in arrays"));
    
    m_pgPropCallStackSize = m_pgMgrDisplayProperties->AppendIn( m_pgPropCatGeneral,  new wxIntProperty( _("Backtrace frames"), wxPG_LABEL, 100) );
    m_pgPropCallStackSize->SetHelpString(_("Maximum number of frames to show in the callstack window"));
    
    m_panel91 = new wxPanel(m_notebook87, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxTAB_TRAVERSAL);
    m_notebook87->AddPage(m_panel91, _("Types"), false);
    
    wxBoxSizer* boxSizer107 = new wxBoxSizer(wxVERTICAL);
    m_panel91->SetSizer(boxSizer107);
    
    m_stcTypes = new wxStyledTextCtrl(m_panel91, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), 0);
    #ifdef __WXMSW__
    // To get the newer version of the font on MSW, we use font wxSYS_DEFAULT_GUI_FONT with family set to wxFONTFAMILY_TELETYPE
    wxFont m_stcTypesFont = wxSystemSettings::GetFont(wxSYS_DEFAULT_GUI_FONT);
    m_stcTypesFont.SetFamily(wxFONTFAMILY_TELETYPE);
    #else
    wxFont m_stcTypesFont = wxSystemSettings::GetFont(wxSYS_ANSI_FIXED_FONT);
    m_stcTypesFont.SetFamily(wxFONTFAMILY_TELETYPE);
    #endif
    m_stcTypes->SetFont(m_stcTypesFont);
    m_stcTypes->SetToolTip(_("LLDB has a data formatters subsystem that allows users to define custom display options for their variables\nYou can set here the types to pass to LLDB"));
    // Configure the fold margin
    m_stcTypes->SetMarginType     (4, wxSTC_MARGIN_SYMBOL);
    m_stcTypes->SetMarginMask     (4, wxSTC_MASK_FOLDERS);
    m_stcTypes->SetMarginSensitive(4, true);
    m_stcTypes->SetMarginWidth    (4, 0);
    
    // Configure the tracker margin
    m_stcTypes->SetMarginWidth(1, 0);
    
    // Configure the symbol margin
    m_stcTypes->SetMarginType (2, wxSTC_MARGIN_SYMBOL);
    m_stcTypes->SetMarginMask (2, ~(wxSTC_MASK_FOLDERS));
    m_stcTypes->SetMarginWidth(2, 0);
    m_stcTypes->SetMarginSensitive(2, true);
    
    // Configure the line numbers margin
    m_stcTypes->SetMarginType(0, wxSTC_MARGIN_NUMBER);
    m_stcTypes->SetMarginWidth(0,0);
    
    // Configure the line symbol margin
    m_stcTypes->SetMarginType(3, wxSTC_MARGIN_FORE);
    m_stcTypes->SetMarginMask(3, 0);
    m_stcTypes->SetMarginWidth(3,0);
    // Select the lexer
    m_stcTypes->SetLexer(wxSTC_LEX_NULL);
    // Set default font / styles
    m_stcTypes->StyleClearAll();
    for(int i=0; i<wxSTC_STYLE_MAX; ++i) {
        m_stcTypes->StyleSetFont(i, m_stcTypesFont);
    }
    m_stcTypes->SetWrapMode(0);
    m_stcTypes->SetIndentationGuides(0);
    m_stcTypes->SetKeyWords(0, wxT(""));
    m_stcTypes->SetKeyWords(1, wxT(""));
    m_stcTypes->SetKeyWords(2, wxT(""));
    m_stcTypes->SetKeyWords(3, wxT(""));
    m_stcTypes->SetKeyWords(4, wxT(""));
    
    boxSizer107->Add(m_stcTypes, 1, wxALL|wxEXPAND, 5);
    
    m_hyperLink111 = new wxHyperlinkCtrl(m_panel91, wxID_ANY, _("Learn more about LLDB types"), wxT("http://lldb.llvm.org/varformats.html"), wxDefaultPosition, wxSize(-1,-1), wxHL_DEFAULT_STYLE);
    m_hyperLink111->SetNormalColour(wxColour(wxT("#0000FF")));
    m_hyperLink111->SetHoverColour(wxColour(wxT("#0000FF")));
    m_hyperLink111->SetVisitedColour(wxColour(wxT("#FF0000")));
    
    boxSizer107->Add(m_hyperLink111, 0, wxALL, 5);
    
    m_stdBtnSizer79 = new wxStdDialogButtonSizer();
    
    boxSizer77->Add(m_stdBtnSizer79, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
    
    m_button81 = new wxButton(this, wxID_CANCEL, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_stdBtnSizer79->AddButton(m_button81);
    
    m_button83 = new wxButton(this, wxID_OK, wxT(""), wxDefaultPosition, wxSize(-1, -1), 0);
    m_button83->SetDefault();
    m_stdBtnSizer79->AddButton(m_button83);
    m_stdBtnSizer79->Realize();
    
    SetSizeHints(-1,-1);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_pgMgrDisplayProperties->Connect(wxEVT_PG_CHANGED, wxPropertyGridEventHandler(LLDBSettingDialogBase::OnGeneralValueChanged), NULL, this);
    m_stcTypes->Connect(wxEVT_STC_UPDATEUI, wxStyledTextEventHandler(LLDBSettingDialogBase::OnStcUpdateUI), NULL, this);
    m_button83->Connect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBSettingDialogBase::OnOKUI), NULL, this);
    
}

LLDBSettingDialogBase::~LLDBSettingDialogBase()
{
    m_pgMgrDisplayProperties->Disconnect(wxEVT_PG_CHANGED, wxPropertyGridEventHandler(LLDBSettingDialogBase::OnGeneralValueChanged), NULL, this);
    m_stcTypes->Disconnect(wxEVT_STC_UPDATEUI, wxStyledTextEventHandler(LLDBSettingDialogBase::OnStcUpdateUI), NULL, this);
    m_button83->Disconnect(wxEVT_UPDATE_UI, wxUpdateUIEventHandler(LLDBSettingDialogBase::OnOKUI), NULL, this);
    
}

LLDBThreadsViewBase::LLDBThreadsViewBase(wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
    : wxPanel(parent, id, pos, size, style)
{
    if ( !bBitmapLoaded ) {
        // We need to initialise the default bitmap handler
        wxXmlResource::Get()->AddHandler(new wxBitmapXmlHandler);
        wxCrafternz79PnInitBitmapResources();
        bBitmapLoaded = true;
    }
    
    wxBoxSizer* boxSizer115 = new wxBoxSizer(wxVERTICAL);
    this->SetSizer(boxSizer115);
    
    m_dvListCtrlThreads = new wxDataViewListCtrl(this, wxID_ANY, wxDefaultPosition, wxSize(-1,-1), wxDV_ROW_LINES|wxDV_SINGLE);
    
    boxSizer115->Add(m_dvListCtrlThreads, 1, wxALL|wxEXPAND, 2);
    
    m_dvListCtrlThreads->AppendTextColumn(_("#"), wxDATAVIEW_CELL_INERT, 40, wxALIGN_LEFT);
    m_dvListCtrlThreads->AppendTextColumn(_("Function"), wxDATAVIEW_CELL_INERT, 150, wxALIGN_LEFT);
    m_dvListCtrlThreads->AppendTextColumn(_("File"), wxDATAVIEW_CELL_INERT, 200, wxALIGN_LEFT);
    m_dvListCtrlThreads->AppendTextColumn(_("Line"), wxDATAVIEW_CELL_INERT, 40, wxALIGN_LEFT);
    
    SetSizeHints(500,300);
    if ( GetSizer() ) {
         GetSizer()->Fit(this);
    }
    Centre(wxBOTH);
    // Connect events
    m_dvListCtrlThreads->Connect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(LLDBThreadsViewBase::OnItemActivated), NULL, this);
    
}

LLDBThreadsViewBase::~LLDBThreadsViewBase()
{
    m_dvListCtrlThreads->Disconnect(wxEVT_COMMAND_DATAVIEW_ITEM_ACTIVATED, wxDataViewEventHandler(LLDBThreadsViewBase::OnItemActivated), NULL, this);
    
}