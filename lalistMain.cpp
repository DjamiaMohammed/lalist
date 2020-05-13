/***************************************************************
 * Name:      lalistMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2012-03-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "lalistMain.h"
#include "AddDialog.h"
#include "IOSDialog.h"
#include <wx/wx.h>
#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>
#include <iostream>
#include <string>
#include <wx/wxcrt.h>
#include "appdb.h"

using namespace std;
//(*InternalHeaders(lalistFrame)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

#undef _(s)
#define _(m) wxGetTranslation(wxString::FromUTF8(m))
appdb* adb;
std::vector<int> Ids;
std::vector<listpe> lpen;
int id;
//(*IdInit(lalistFrame)
const long lalistFrame::ID_ADDBUT = wxNewId();
const long lalistFrame::ID_EDITBUT = wxNewId();
const long lalistFrame::ID_DELETBUT = wxNewId();
const long lalistFrame::ID_UPGRADEBUT = wxNewId();
const long lalistFrame::ID_ADDTOLEBUT = wxNewId();
const long lalistFrame::ID_EXAMCENTERL = wxNewId();
const long lalistFrame::ID_STATICTEXT7 = wxNewId();
const long lalistFrame::ID_STATEL = wxNewId();
const long lalistFrame::ID_STATICTEXT5 = wxNewId();
const long lalistFrame::ID_NRCL = wxNewId();
const long lalistFrame::ID_STATICTEXT3 = wxNewId();
const long lalistFrame::ID_NAMEL = wxNewId();
const long lalistFrame::ID_STATICTEXT1 = wxNewId();
const long lalistFrame::ID_tlistp = wxNewId();
const long lalistFrame::ID_SCROLLEDWINDOW1 = wxNewId();
const long lalistFrame::ID_PANEL1 = wxNewId();
const long lalistFrame::ID_EXAMCENTERL1 = wxNewId();
const long lalistFrame::ID_STATICTEXT10 = wxNewId();
const long lalistFrame::ID_STATEL1 = wxNewId();
const long lalistFrame::ID_STATICTEXT12 = wxNewId();
const long lalistFrame::ID_NAMEL1 = wxNewId();
const long lalistFrame::ID_STATICTEXT16 = wxNewId();
const long lalistFrame::ID_TLISTEN = wxNewId();
const long lalistFrame::ID_SCROLLEDWINDOW2 = wxNewId();
const long lalistFrame::ID_YE = wxNewId();
const long lalistFrame::ID_STATICTEXT2 = wxNewId();
const long lalistFrame::ID_ME = wxNewId();
const long lalistFrame::ID_STATICTEXT4 = wxNewId();
const long lalistFrame::ID_DE = wxNewId();
const long lalistFrame::ID_NRCL1 = wxNewId();
const long lalistFrame::ID_STATICTEXT14 = wxNewId();
const long lalistFrame::ID_EXPORT = wxNewId();
const long lalistFrame::ID_PANEL2 = wxNewId();
const long lalistFrame::ID_TLISTEO = wxNewId();
const long lalistFrame::ID_SCROLLEDWINDOW3 = wxNewId();
const long lalistFrame::ID_DATEO = wxNewId();
const long lalistFrame::ID_DATEO2 = wxNewId();
const long lalistFrame::ID_NRCO = wxNewId();
const long lalistFrame::ID_NRCO2 = wxNewId();
const long lalistFrame::ID_CTEO = wxNewId();
const long lalistFrame::ID_PANEL3 = wxNewId();
const long lalistFrame::ID_NOTEBOOK1 = wxNewId();
const long lalistFrame::idMenuSetting = wxNewId();
const long lalistFrame::idrefload = wxNewId();
const long lalistFrame::idMenuQuit = wxNewId();
const long lalistFrame::idMenuAbout = wxNewId();
//*)
const long lalistFrame::idReflish = wxNewId();

BEGIN_EVENT_TABLE(lalistFrame,wxFrame)
    //(*EventTable(lalistFrame)
    //*)
END_EVENT_TABLE()




lalistFrame::lalistFrame(wxWindow* parent,wxWindowID id)
{
    id = -1;
    adb = new appdb(".");
    lpen.clear();
    //(*Initialize(lalistFrame)
    wxFlexGridSizer* FlexGridSizer1;
    wxFlexGridSizer* FlexGridSizer2;
    wxFlexGridSizer* FlexGridSizer3;
    wxFlexGridSizer* FlexGridSizer4;
    wxFlexGridSizer* FlexGridSizer5;
    wxFlexGridSizer* FlexGridSizer6;
    wxGridBagSizer* GridBagSizer1;
    wxGridBagSizer* GridBagSizer2;
    wxGridBagSizer* GridBagSizer3;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("lalist"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(600,600));
    Notebook1 = new wxNotebook(this, ID_NOTEBOOK1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_NOTEBOOK1"));
    Panel1 = new wxPanel(Notebook1, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    FlexGridSizer1 = new wxFlexGridSizer(0, 1, 0, 0);
    GridBagSizer1 = new wxGridBagSizer(0, 0);
    FlexGridSizer2 = new wxFlexGridSizer(0, 5, 0, 0);
    addbut = new wxButton(Panel1, ID_ADDBUT, _("إضافة"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_ADDBUT"));
    wxFont addbutFont(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    addbut->SetFont(addbutFont);
    FlexGridSizer2->Add(addbut, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    editbut = new wxButton(Panel1, ID_EDITBUT, _("تحرير"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_EDITBUT"));
    wxFont editbutFont(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    editbut->SetFont(editbutFont);
    FlexGridSizer2->Add(editbut, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    deletbut = new wxButton(Panel1, ID_DELETBUT, _("حذف"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_DELETBUT"));
    wxFont deletbutFont(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    deletbut->SetFont(deletbutFont);
    FlexGridSizer2->Add(deletbut, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    upgradebut = new wxButton(Panel1, ID_UPGRADEBUT, _("ترقية"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_UPGRADEBUT"));
    wxFont upgradebutFont(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    upgradebut->SetFont(upgradebutFont);
    FlexGridSizer2->Add(upgradebut, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    addtolebut = new wxButton(Panel1, ID_ADDTOLEBUT, _("إضافة الى قائمة الإمتحان"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_ADDTOLEBUT"));
    wxFont addtolebutFont(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    addtolebut->SetFont(addtolebutFont);
    FlexGridSizer2->Add(addtolebut, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridBagSizer1->Add(FlexGridSizer2, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer3 = new wxFlexGridSizer(0, 8, 0, 0);
    examcenterl = new wxStaticText(Panel1, ID_EXAMCENTERL, wxEmptyString, wxDefaultPosition, wxSize(70,-1), wxALIGN_RIGHT, _T("ID_EXAMCENTERL"));
    FlexGridSizer3->Add(examcenterl, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText7 = new wxStaticText(Panel1, ID_STATICTEXT7, _(":مركز الإمتحان"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
    wxFont StaticText7Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText7->SetFont(StaticText7Font);
    FlexGridSizer3->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    statel = new wxStaticText(Panel1, ID_STATEL, wxEmptyString, wxDefaultPosition, wxSize(70,-1), wxALIGN_RIGHT, _T("ID_STATEL"));
    FlexGridSizer3->Add(statel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText5 = new wxStaticText(Panel1, ID_STATICTEXT5, _(":ولاية"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
    wxFont StaticText5Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText5->SetFont(StaticText5Font);
    FlexGridSizer3->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    NRCL = new wxStaticText(Panel1, ID_NRCL, wxEmptyString, wxDefaultPosition, wxSize(80,-1), wxALIGN_RIGHT, _T("ID_NRCL"));
    FlexGridSizer3->Add(NRCL, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _(":رقم تسجيل"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    FlexGridSizer3->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    namel = new wxStaticText(Panel1, ID_NAMEL, wxEmptyString, wxDefaultPosition, wxSize(70,-1), wxALIGN_RIGHT, _T("ID_NAMEL"));
    FlexGridSizer3->Add(namel, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _(":إسم"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridBagSizer1->Add(FlexGridSizer3, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer1->Add(GridBagSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ScrolledWindow1 = new wxScrolledWindow(Panel1, ID_SCROLLEDWINDOW1, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW1"));
    tlistp = new wxGrid(ScrolledWindow1, ID_tlistp, wxDefaultPosition, wxSize(580,430), 0, _T("ID_tlistp"));
    tlistp->CreateGrid(0,13);
    tlistp->EnableEditing(false);
    tlistp->EnableGridLines(true);
    tlistp->SetColLabelValue(0, _("ID"));
    tlistp->SetColLabelValue(1, _("اللقب"));
    tlistp->SetColLabelValue(2, _("الإسم"));
    tlistp->SetColLabelValue(3, _("ابن"));
    tlistp->SetColLabelValue(4, _("تاريخ ميلاد"));
    tlistp->SetColLabelValue(5, _("مكان الميلاد"));
    tlistp->SetColLabelValue(6, _("العنوان"));
    tlistp->SetColLabelValue(7, _("فصيلة الدم"));
    tlistp->SetColLabelValue(8, _("الهاتف"));
    tlistp->SetColLabelValue(9, _("المهنة"));
    tlistp->SetColLabelValue(10, _("الجنسية"));
    tlistp->SetColLabelValue(11, _("تاريخ تسجيل الملف"));
    tlistp->SetColLabelValue(12, _("طبيعة الإمتحان"));
    tlistp->SetDefaultCellFont( tlistp->GetFont() );
    tlistp->SetDefaultCellTextColour( tlistp->GetForegroundColour() );
    FlexGridSizer1->Add(ScrolledWindow1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(FlexGridSizer1);
    FlexGridSizer1->Fit(Panel1);
    FlexGridSizer1->SetSizeHints(Panel1);
    Panel2 = new wxPanel(Notebook1, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    GridBagSizer2 = new wxGridBagSizer(0, 0);
    FlexGridSizer5 = new wxFlexGridSizer(0, 9, 0, 0);
    examcenterl1 = new wxStaticText(Panel2, ID_EXAMCENTERL1, wxEmptyString, wxDefaultPosition, wxSize(100,-1), wxALIGN_RIGHT, _T("ID_EXAMCENTERL1"));
    FlexGridSizer5->Add(examcenterl1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText10 = new wxStaticText(Panel2, ID_STATICTEXT10, _(":مركز الإمتحان"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
    wxFont StaticText10Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText10->SetFont(StaticText10Font);
    FlexGridSizer5->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    statel1 = new wxStaticText(Panel2, ID_STATEL1, wxEmptyString, wxDefaultPosition, wxSize(100,-1), wxALIGN_RIGHT, _T("ID_STATEL1"));
    FlexGridSizer5->Add(statel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText12 = new wxStaticText(Panel2, ID_STATICTEXT12, _(":ولاية"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
    wxFont StaticText12Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText12->SetFont(StaticText12Font);
    FlexGridSizer5->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    namel1 = new wxStaticText(Panel2, ID_NAMEL1, wxEmptyString, wxDefaultPosition, wxSize(100,-1), wxALIGN_RIGHT, _T("ID_NAMEL1"));
    FlexGridSizer5->Add(namel1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText16 = new wxStaticText(Panel2, ID_STATICTEXT16, _(":إسم"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
    wxFont StaticText16Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText16->SetFont(StaticText16Font);
    FlexGridSizer5->Add(StaticText16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridBagSizer2->Add(FlexGridSizer5, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    ScrolledWindow2 = new wxScrolledWindow(Panel2, ID_SCROLLEDWINDOW2, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW2"));
    tlisten = new wxGrid(ScrolledWindow2, ID_TLISTEN, wxPoint(23,0), wxSize(520,476), 0, _T("ID_TLISTEN"));
    tlisten->CreateGrid(0,4);
    tlisten->EnableEditing(false);
    tlisten->EnableGridLines(true);
    tlisten->SetColLabelValue(0, _("الرقم"));
    tlisten->SetColLabelValue(1, _("اللقب و الاسم"));
    tlisten->SetColLabelValue(2, _("تاريخ ميلاد"));
    tlisten->SetColLabelValue(3, _("طبيعة الإمتحان"));
    tlisten->SetDefaultCellFont( tlisten->GetFont() );
    tlisten->SetDefaultCellTextColour( tlisten->GetForegroundColour() );
    GridBagSizer2->Add(ScrolledWindow2, wxGBPosition(2, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer6 = new wxFlexGridSizer(0, 8, 0, 0);
    ye = new wxTextCtrl(Panel2, ID_YE, wxEmptyString, wxDefaultPosition, wxSize(40,-1), wxTE_RIGHT, wxDefaultValidator, _T("ID_YE"));
    FlexGridSizer6->Add(ye, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText2 = new wxStaticText(Panel2, ID_STATICTEXT2, _("/"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    FlexGridSizer6->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    me = new wxComboBox(Panel2, ID_ME, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_ME"));
    me->SetSelection( me->Append(_("جانفي")) );
    me->Append(_("فيفري"));
    me->Append(_("مارس"));
    me->Append(_("أفريل"));
    me->Append(_("ماي"));
    me->Append(_("جوان"));
    me->Append(_("جويلية"));
    me->Append(_("أوت"));
    me->Append(_("سبتمبر"));
    me->Append(_("اكتوبر"));
    me->Append(_("فوفمبر"));
    me->Append(_("ديسمبر"));
    FlexGridSizer6->Add(me, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText4 = new wxStaticText(Panel2, ID_STATICTEXT4, _("/"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    wxFont StaticText4Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText4->SetFont(StaticText4Font);
    FlexGridSizer6->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    de = new wxTextCtrl(Panel2, ID_DE, wxEmptyString, wxDefaultPosition, wxSize(30,-1), wxTE_RIGHT, wxDefaultValidator, _T("ID_DE"));
    wxFont deFont(10,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    de->SetFont(deFont);
    FlexGridSizer6->Add(de, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    NRCL1 = new wxStaticText(Panel2, ID_NRCL1, wxEmptyString, wxDefaultPosition, wxSize(100,-1), wxALIGN_RIGHT, _T("ID_NRCL1"));
    FlexGridSizer6->Add(NRCL1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticText14 = new wxStaticText(Panel2, ID_STATICTEXT14, _(":رقم تسجيل"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
    wxFont StaticText14Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText14->SetFont(StaticText14Font);
    FlexGridSizer6->Add(StaticText14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    docxexport = new wxButton(Panel2, ID_EXPORT, _("تصدير"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_EXPORT"));
    wxFont docxexportFont(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    docxexport->SetFont(docxexportFont);
    FlexGridSizer6->Add(docxexport, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridBagSizer2->Add(FlexGridSizer6, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(GridBagSizer2);
    GridBagSizer2->Fit(Panel2);
    GridBagSizer2->SetSizeHints(Panel2);
    Panel3 = new wxPanel(Notebook1, ID_PANEL3, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    GridBagSizer3 = new wxGridBagSizer(0, 0);
    ScrolledWindow3 = new wxScrolledWindow(Panel3, ID_SCROLLEDWINDOW3, wxDefaultPosition, wxDefaultSize, wxVSCROLL|wxHSCROLL, _T("ID_SCROLLEDWINDOW3"));
    tlisteo = new wxGrid(ScrolledWindow3, ID_TLISTEO, wxPoint(23,0), wxSize(532,476), 0, _T("ID_TLISTEO"));
    tlisteo->CreateGrid(0,4);
    tlisteo->EnableEditing(false);
    tlisteo->EnableGridLines(true);
    tlisteo->SetColLabelValue(0, _("الرقم"));
    tlisteo->SetColLabelValue(1, _("اللقب و الاسم"));
    tlisteo->SetColLabelValue(2, _("تاريخ ميلاد"));
    tlisteo->SetColLabelValue(3, _("طبيعة الإمتحان"));
    tlisteo->SetDefaultCellFont( tlisteo->GetFont() );
    tlisteo->SetDefaultCellTextColour( tlisteo->GetForegroundColour() );
    GridBagSizer3->Add(ScrolledWindow3, wxGBPosition(1, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    FlexGridSizer4 = new wxFlexGridSizer(0, 9, 0, 0);
    dateo = new wxStaticText(Panel3, ID_DATEO, wxEmptyString, wxDefaultPosition, wxSize(60,-1), wxALIGN_RIGHT, _T("ID_DATEO"));
    FlexGridSizer4->Add(dateo, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    DATEO2 = new wxStaticText(Panel3, ID_DATEO2, _(":تاريخ الامتحان"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_DATEO2"));
    wxFont DATEO2Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    DATEO2->SetFont(DATEO2Font);
    FlexGridSizer4->Add(DATEO2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    NRCO = new wxStaticText(Panel3, ID_NRCO, wxEmptyString, wxDefaultPosition, wxSize(105,-1), wxALIGN_RIGHT, _T("ID_NRCO"));
    FlexGridSizer4->Add(NRCO, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    NRCO2 = new wxStaticText(Panel3, ID_NRCO2, _(":رقم تسجيل السيارة"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_NRCO2"));
    wxFont NRCO2Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    NRCO2->SetFont(NRCO2Font);
    FlexGridSizer4->Add(NRCO2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    CTEO = new wxChoice(Panel3, ID_CTEO, wxDefaultPosition, wxSize(100,-1), 0, 0, 0, wxDefaultValidator, _T("ID_CTEO"));
    FlexGridSizer4->Add(CTEO, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridBagSizer3->Add(FlexGridSizer4, wxGBPosition(0, 0), wxDefaultSpan, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel3->SetSizer(GridBagSizer3);
    GridBagSizer3->Fit(Panel3);
    GridBagSizer3->SetSizeHints(Panel3);
    Notebook1->AddPage(Panel1, _("قائمة المترشحين"), false);
    Notebook1->AddPage(Panel2, _("قائمة مترشحين للامتحان"), false);
    Notebook1->AddPage(Panel3, _("قائمة مترشحين السابقة"), false);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    Menu3 = new wxMenuItem(Menu1, idMenuSetting, _("إعدادات"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(Menu3);
    MenuItem3 = new wxMenuItem(Menu1, idrefload, _("اعادة تحميل"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);

    Connect(ID_ADDBUT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&lalistFrame::OnaddbutClick);
    Connect(ID_EDITBUT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&lalistFrame::OneditbutClick);
    Connect(ID_DELETBUT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&lalistFrame::OndeletbutClick);
    Connect(ID_UPGRADEBUT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&lalistFrame::OnupgradebutClick);
    Connect(ID_ADDTOLEBUT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&lalistFrame::OnaddtolebutClick);
    Connect(ID_EXPORT,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&lalistFrame::OndocxexportClick);
    Connect(ID_CTEO,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&lalistFrame::OnCTEOSelect);
    Connect(idMenuSetting,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&lalistFrame::OnSettingClick);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&lalistFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&lalistFrame::OnAbout);
    //*)
    Connect(idrefload,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&lalistFrame::OnRLoad);
    Connect(ID_tlistp,wxEVT_GRID_RANGE_SELECT,(wxObjectEventFunction)&lalistFrame::OntlistpRangeSelected);
    //////
    tlisteo->SetColSize(0,30);
    tlisteo->SetColSize(1,250);
    tlisteo->SetColSize(2,70);
    tlisteo->SetColSize(3,80);
    /////
    tlisten->SetColSize(0,30);
    tlisten->SetColSize(1,250);
    tlisten->SetColSize(2,70);
    tlisten->SetColSize(3,80);

    vector<string> mb = adb->getmb();
    for(int i = 0;i<mb.size();++i)
    {
        this->CTEO->Append(_(mb[i].c_str()));
    }
    this->OnReflish();
    this->tlistp->SetSelectionMode(wxGrid::wxGridSelectRows);
    Ids.clear();
}

lalistFrame::~lalistFrame()
{
    //(*Destroy(lalistFrame)
    //*)
}
void lalistFrame::OnRLoad(wxCommandEvent& event)
{
    this->OnReflish();
}


void lalistFrame::OnReflish()
{
    static bool el = false;
    if(el) tlistp->DeleteRows(0, tlistp->GetNumberRows());
    this->OnReLoad();
    el = true;
}

void lalistFrame::OnReLoad()
{
    /////////////////////////////////////////
    string name;string NRC;string Examcenter;string state;
    adb->getIOS( name, NRC, Examcenter, state);
    this->namel->SetLabel(wxString::FromUTF8(name.c_str()));
    this->examcenterl->SetLabel(wxString::FromUTF8(Examcenter.c_str()));
    this->statel->SetLabel(wxString::FromUTF8(state.c_str()));
    this->NRCL->SetLabel(wxString::FromUTF8(NRC.c_str()));
    /////////////////////////////////////////*/
    tlistp->AppendRows(adb->len());

    ////////
    vector<listp> l = adb->get_lps();
    int tol = l.size();
    for(int i = 0 ;i<tlistp->GetNumberRows() && i<tol;++i)
        {
            tlistp->SetCellValue(i,0,wxString(to_string(l[i].ID)));
            tlistp->SetCellValue(i,1,wxString::FromUTF8(l[i].firstname.c_str()));
            tlistp->SetCellValue(i,2,wxString::FromUTF8(l[i].lastname.c_str()));
            tlistp->SetCellValue(i,3,wxString::FromUTF8(l[i].sonof.c_str()));
            tlistp->SetCellValue(i,4,wxString::FromUTF8(l[i].HINC.c_str()));
            tlistp->SetCellValue(i,5,wxString::FromUTF8(l[i].PINC.c_str()));
            tlistp->SetCellValue(i,6,wxString::FromUTF8(l[i].Address.c_str()));
            wxString s;
            if (l[i].BT==0) s = wxString::FromUTF8("O+");
            else if (l[i].BT==1) s = wxString::FromUTF8("A+");
            else if (l[i].BT==2) s = wxString::FromUTF8("B+");
            else if (l[i].BT==3) s = wxString::FromUTF8("AB+");
            else if (l[i].BT==4) s = wxString::FromUTF8("O-");
            else if (l[i].BT==5) s = wxString::FromUTF8("A-");
            else if (l[i].BT==6) s = wxString::FromUTF8("B-");
            else if (l[i].BT==7) s = wxString::FromUTF8("AB-");
            tlistp->SetCellValue(i,7,s);
            tlistp->SetCellValue(i,8,wxString::FromUTF8(l[i].phone.c_str()));
            tlistp->SetCellValue(i,9,wxString::FromUTF8(l[i].work.c_str()));
            tlistp->SetCellValue(i,10,wxString::FromUTF8(l[i].nationlity.c_str()));
            tlistp->SetCellValue(i,11,wxString::FromUTF8(l[i].HRF.c_str()));
            wxString s1;
            if (l[i].TE==1) s1 = wxString::FromUTF8("القانون المرور");
            else if (l[i].TE==2) s1 = wxString::FromUTF8("المناورات");
            else if (l[i].TE==3) s1 = wxString::FromUTF8("القيادة");
            tlistp->SetCellValue(i,12,s1);
        }
    ////////////////////////////////////////////////////////

    ////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////

    //////////////////////////////////////////////////////

/////////
}

void lalistFrame::OnQuit(wxCommandEvent& event)
{
    Close();
   // wxExit();
}
void lalistFrame::OnSettingClick(wxCommandEvent& event)
{
    IOSDialog* Frame = new IOSDialog(this);

    string name;string NRC;string Examcenter;string state;
    adb->getIOS( name, NRC, Examcenter, state);
    Frame->getIOS(wxString::FromUTF8(name.c_str()),wxString::FromUTF8(NRC.c_str()),
                  wxString::FromUTF8(Examcenter.c_str()),wxString::FromUTF8(state.c_str()));
    Frame->Show();
}

void lalistFrame::OnAbout(wxCommandEvent& event)
{
    wxAboutDialogInfo aboutInfo;
    aboutInfo.SetName(wxT("lalist"));
    aboutInfo.SetVersion("1.0.0");
    aboutInfo.SetDescription(_("لصنع قائمة مترشحين خاصة بك بكل سهولة"));
    aboutInfo.AddDeveloper(wxT("Djamia Mohammed"));
    wxAboutBox(aboutInfo);

}

void addlistcmd(listaddcmd_t listadd)
{
    listp lp;
    lp.firstname = listadd.firstname.mb_str(wxConvUTF8).data();
    lp.lastname = listadd.lastname.mb_str(wxConvUTF8).data();
    lp.sonof = listadd.sonof.mb_str(wxConvUTF8).data();
    lp.HINC = listadd.HINC.mb_str(wxConvUTF8).data();
    lp.PINC = listadd.PINC.mb_str(wxConvUTF8).data();
    lp.Address = listadd.Address.mb_str(wxConvUTF8).data();
    lp.BT = listadd.BT;
    lp.phone = listadd.phone.mb_str(wxConvUTF8).data();
    lp.work = listadd.work.mb_str(wxConvUTF8).data();
    lp.nationlity = listadd.nationlity.mb_str(wxConvUTF8).data();
    lp.HRF = listadd.HRF.mb_str(wxConvUTF8).data();
    adb->add(lp);
    wxMessageBox(_("تم الإضافة"));
}

void edditlistcmd(listaddcmd_t listadd)
{
    listp lp;
    lp.ID = listadd.ID;
    lp.firstname = listadd.firstname.mb_str(wxConvUTF8).data();
    lp.lastname = listadd.lastname.mb_str(wxConvUTF8).data();
    lp.sonof = listadd.sonof.mb_str(wxConvUTF8).data();
    lp.HINC = listadd.HINC.mb_str(wxConvUTF8).data();
    lp.PINC = listadd.PINC.mb_str(wxConvUTF8).data();
    lp.Address = listadd.Address.mb_str(wxConvUTF8).data();
    lp.BT = listadd.BT;
    lp.phone = listadd.phone.mb_str(wxConvUTF8).data();
    lp.work = listadd.work.mb_str(wxConvUTF8).data();
    lp.nationlity = listadd.nationlity.mb_str(wxConvUTF8).data();
    lp.HRF = listadd.HRF.mb_str(wxConvUTF8).data();
    adb->edit(lp.ID,lp);
    wxMessageBox(_("تم التحرير"));
}

void setIOS(wxString name,wxString NRC,wxString Examcenter,wxString state)
{

    adb->setIOS(name.mb_str(wxConvUTF8).data(),NRC.mb_str(wxConvUTF8).data(),Examcenter.mb_str(wxConvUTF8).data(),state.mb_str(wxConvUTF8).data());
}


void lalistFrame::OnaddbutClick(wxCommandEvent& event)
{
    AddDialog* frame = new AddDialog(this,0);
    frame->Show();
}

void lalistFrame::OneditbutClick(wxCommandEvent& event)
{
    AddDialog* frame = new AddDialog(this,1);
   // wxMessageBox(wxString(to_string(event.)));
    if (id < 0) {delete frame;return;}
    listp l = adb->get_lp(id);
    listaddcmd_t listadd;
    listadd.ID = id;
    listadd.firstname = wxString::FromUTF8(l.firstname.c_str());
    listadd.lastname = wxString::FromUTF8(l.lastname.c_str());
    listadd.sonof = wxString::FromUTF8(l.sonof.c_str());
    listadd.Address = wxString::FromUTF8(l.Address.c_str());
    listadd.work = wxString::FromUTF8(l.work.c_str());
    listadd.nationlity = wxString::FromUTF8(l.nationlity.c_str());
    listadd.phone =wxString::FromUTF8(l.phone.c_str());
    listadd.PINC = wxString::FromUTF8(l.PINC.c_str());
    listadd.BT = l.BT;
    listadd.HINC = wxString::FromUTF8(l.HINC.c_str());
    listadd.HRF = wxString::FromUTF8(l.HRF.c_str());
    frame->eddDialog(listadd);
    frame->Show();
}

void lalistFrame::OndeletbutClick(wxCommandEvent& event)
{
    if(id < 0) return;
    adb->Delete(id);
    this->OnReflish();
}


void lalistFrame::OnupgradebutClick(wxCommandEvent& event)
{
    if(id < 0) return;
    adb->upgrad(id);
    this->OnReflish();
}

void lalistFrame::OnaddtolebutClick(wxCommandEvent& event)
{
    this->OnReflish();
    string name;string NRC;string Examcenter;string state;
    adb->getIOS( name, NRC, Examcenter, state);
    this->namel1->SetLabel(wxString::FromUTF8(name.c_str()));
    this->examcenterl1->SetLabel(wxString::FromUTF8(Examcenter.c_str()));
    this->statel1->SetLabel(wxString::FromUTF8(state.c_str()));
    this->NRCL1->SetLabel(wxString::FromUTF8(NRC.c_str()));
    static bool eln = false;
    if (eln) tlisten->DeleteRows(0,tlistp->GetRows());
    eln = true;
    int tol = Ids.size();
    tlisten->AppendRows(tol);
    int Nexam1 = 0;
    int Nexam2 = 0;
    int Nexam3 = 0;
    lpen.clear();
    for(int i = 0;i<tol;i++)
    {
       // int i = Ids[j];
        listpe s = adb->get_lpe(Ids[i],Nexam1,Nexam2,Nexam3);
        lpen.push_back(s);
        tlisten->SetCellValue(i,0,wxString::Format(wxT("%d"),s.NB));
        tlisten->SetCellValue(i,1,_(s.name.c_str()));
        tlisten->SetCellValue(i,2,_(s.HINC.c_str()));
        switch(s.TE){
            case 1:
                this->tlisten->SetCellValue(i,3,wxString::FromUTF8("القانون المرور"));
            break;
            case 2:
                this->tlisten->SetCellValue(i,3,wxString::FromUTF8("الـــــمـنــاورات"));
            break;
            case 3:
                this->tlisten->SetCellValue(i,3,wxString::FromUTF8("الــــــقـــــيـــادة"));
            break;
        }
    }
}

void lalistFrame::OndocxexportClick(wxCommandEvent& event)
{
    data_t dt;
    dt.day = wxAtoi(de->GetValue());
    dt.year = wxAtoi(ye->GetValue());
    dt.months = me->GetSelection()+1;
    if(dt.day< 1 || dt.day > 31 || dt.year < 2020 || dt.months < 1 || dt.months > 12)
        {wxMessageBox(_("ادخل تاريخ صحيح"));return;}
    wxString filename = wxSaveFileSelector("lalist","docx");
    if(filename.empty()){wxMessageBox(_("اختر ملف حفظ صحيح"));return;}
    //*
    adb->createtable(dt);
    for(int i;i<lpen.size();i++) adb->addtolist(lpen[i]);
    adb->endtable("temp",filename.mb_str());
    //*/
}
void lalistFrame::OnReflishto(wxString tname)
{
    vector<listpe> lpeo ;
    lpeo= adb->getle_byname(tname.mb_str(wxConvUTF8).data());
    listpe l;
    static bool elo = false;
    if(elo) tlisteo->DeleteRows(0, tlisteo->GetNumberRows());
    elo = true;
    int st = lpeo.size();
    tlisteo->AppendRows(st);
    for(int i = 0;i<st;++i)
    {
         l = lpeo[i];
         this->tlisteo->SetCellValue(i,0,wxString(to_string(l.NB)));
         this->tlisteo->SetCellValue(i,1,wxString::FromUTF8(l.name.c_str()));
         this->tlisteo->SetCellValue(i,2,wxString::FromUTF8(l.HINC.c_str()));
         switch(l.TE){
        case 1:
                this->tlisteo->SetCellValue(i,3,wxString::FromUTF8("القانون المرور"));
            break;
        case 2:
                this->tlisteo->SetCellValue(i,3,wxString::FromUTF8("الـــــمـنــاورات"));
            break;
        case 3:
                this->tlisteo->SetCellValue(i,3,wxString::FromUTF8("الــــــقـــــيـــادة"));
            break;
         }
    }
    lpeo.clear();
}

void lalistFrame::OnCTEOSelect(wxCommandEvent& event)
{
    this->dateo->SetLabel(wxString::FromUTF8(adb->getmbdate(event.GetString().mb_str(wxConvUTF8).data()).c_str()));
    this->NRCO->SetLabel(wxString::FromUTF8(adb->getmbNRC(event.GetString().mb_str(wxConvUTF8).data()).c_str()));
    OnReflishto(event.GetString());
}
//////////////////////////////////////////////////////////

void lalistFrame::OntlistpRangeSelected(wxGridRangeSelectEvent& ev)
{
    static bool enl1 = false;
    if (ev.Selecting())
    {
        for(int i = ev.GetTopRow();i <= ev.GetBottomRow();i++)
        {
            if(ev.GetTopRow() == ev.GetBottomRow())
            {
                enl1 = true;
                id = wxAtoi(tlistp->GetCellValue(i,0));
                Ids.push_back(id);
                continue;
            }
            if(enl1) {enl1 = false;continue;}
            Ids.push_back(wxAtoi(tlistp->GetCellValue(i,0)));
        }
    }
    else
    {
        if(ev.GetTopRow()==0 && ev.GetLeftCol() == 0 && (ev.GetRightCol()+1)==tlistp->GetCols() && (ev.GetBottomRow()+1) == tlistp->GetRows())
            {Ids.clear();id = -1;this->OnReflish();}
    }
}
