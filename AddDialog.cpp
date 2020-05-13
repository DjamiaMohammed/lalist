#include "AddDialog.h"

#include <wx/msgdlg.h>
#include <wx/button.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
#include <string>
#include <cstdlib>
using namespace std;
#undef _(s)
#define _(m) wxGetTranslation(wxString::FromUTF8(m))


const long AddDialog::ID_FIRSTNAME = wxNewId();
const long AddDialog::ID_STATICTEXT1 = wxNewId();
const long AddDialog::ID_LASTNAME = wxNewId();
const long AddDialog::ID_STATICTEXT2 = wxNewId();
const long AddDialog::ID_SONOF = wxNewId();
const long AddDialog::ID_STATICTEXT3 = wxNewId();
const long AddDialog::ID_P_INC = wxNewId();
const long AddDialog::ID_STATICTEXT11 = wxNewId();
const long AddDialog::ID_Y_H_INC = wxNewId();
const long AddDialog::ID_W_H_INC = wxNewId();
const long AddDialog::ID_D_H_INC = wxNewId();
const long AddDialog::ID_STATICTEXT10 = wxNewId();
const long AddDialog::ID_ADDRESS = wxNewId();
const long AddDialog::ID_STATICTEXT4 = wxNewId();
const long AddDialog::ID_PHONE = wxNewId();
const long AddDialog::ID_STATICTEXT7 = wxNewId();
const long AddDialog::ID_BT = wxNewId();
const long AddDialog::ID_STATICTEXT6 = wxNewId();
const long AddDialog::ID_WORK = wxNewId();
const long AddDialog::ID_STATICTEXT5 = wxNewId();
const long AddDialog::ID_Y_HRF = wxNewId();
const long AddDialog::ID_W_HRF = wxNewId();
const long AddDialog::ID_D_HRF = wxNewId();
const long AddDialog::ID_STATICTEXT9 = wxNewId();
const long AddDialog::ID_NATIONALITY = wxNewId();
const long AddDialog::ID_STATICTEXT8 = wxNewId();


BEGIN_EVENT_TABLE(AddDialog,wxDialog)
	//(*EventTable(AddDialog)
	//*)
END_EVENT_TABLE()

AddDialog::AddDialog(wxWindow* parent,bool ae,wxWindowID id,const wxPoint& pos,const wxSize& size) : _ae(ae)
{

	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;
	wxFlexGridSizer* FlexGridSizer4;
	wxFlexGridSizer* FlexGridSizer5;
	wxFlexGridSizer* FlexGridSizer6;
	wxFlexGridSizer* FlexGridSizer7;
	wxFlexGridSizer* FlexGridSizer8;
	wxStdDialogButtonSizer* addDB;
	this->_ID = 0;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	FlexGridSizer1 = new wxFlexGridSizer(0, 3, 0, 0);
	firstname = new wxTextCtrl(this, ID_FIRSTNAME, wxEmptyString, wxDefaultPosition, wxSize(260,-1), wxTE_RIGHT, wxDefaultValidator, _T("ID_FIRSTNAME"));
	FlexGridSizer1->Add(firstname, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _(": لقب"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	FlexGridSizer1->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 3, 0, 0);
	lastname = new wxTextCtrl(this, ID_LASTNAME, wxEmptyString, wxDefaultPosition, wxSize(260,-1), wxTE_RIGHT, wxDefaultValidator, _T("ID_LASTNAME"));
	FlexGridSizer2->Add(lastname, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _(": إسم"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	FlexGridSizer2->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 3, 0, 0);
	sonof = new wxTextCtrl(this, ID_SONOF, wxEmptyString, wxDefaultPosition, wxSize(260,21), wxTE_RIGHT, wxDefaultValidator, _T("ID_SONOF"));
	FlexGridSizer3->Add(sonof, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _(": إبن"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	FlexGridSizer3->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer4 = new wxFlexGridSizer(0, 6, 0, 0);
	PINC = new wxTextCtrl(this, ID_P_INC, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT, wxDefaultValidator, _T("ID_P_INC"));
	FlexGridSizer4->Add(PINC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _(":مكان الإزدياد"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT11"));
	wxFont StaticText11Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText11->SetFont(StaticText11Font);
	FlexGridSizer4->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	YHINC = new wxTextCtrl(this, ID_Y_H_INC, wxEmptyString, wxDefaultPosition, wxSize(35,-1), 0, wxDefaultValidator, _T("ID_Y_H_INC"));
	FlexGridSizer4->Add(YHINC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	WHINC = new wxChoice(this, ID_W_H_INC, wxDefaultPosition, wxSize(60,-1), 0, 0, 0, wxDefaultValidator, _T("ID_W_H_INC"));
	WHINC->SetSelection( WHINC->Append(_("جانفي")) );
	WHINC->Append(_("فيفري"));
	WHINC->Append(_("مارس"));
	WHINC->Append(_("أفريل"));
	WHINC->Append(_("ماي"));
	WHINC->Append(_("جوان"));
	WHINC->Append(_("جويلية"));
	WHINC->Append(_("أوت"));
	WHINC->Append(_("سبتمبر"));
	WHINC->Append(_("اكتوبر"));
	WHINC->Append(_("فوفمبر"));
	WHINC->Append(_("ديسمبر"));
	FlexGridSizer4->Add(WHINC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DHINC = new wxTextCtrl(this, ID_D_H_INC, wxEmptyString, wxDefaultPosition, wxSize(25,-1), 0, wxDefaultValidator, _T("ID_D_H_INC"));
	FlexGridSizer4->Add(DHINC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _(":تاريخ الإزدياد"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT10"));
	wxFont StaticText10Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText10->SetFont(StaticText10Font);
	FlexGridSizer4->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer5 = new wxFlexGridSizer(0, 3, 0, 0);
	address = new wxTextCtrl(this, ID_ADDRESS, wxEmptyString, wxDefaultPosition, wxSize(260,-1), wxTE_RIGHT, wxDefaultValidator, _T("ID_ADDRESS"));
	FlexGridSizer5->Add(address, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _(":العنوان"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT4"));
	wxFont StaticText4Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);
	FlexGridSizer5->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer6 = new wxFlexGridSizer(1, 4, 0, 0);
	phone = new wxTextCtrl(this, ID_PHONE, wxEmptyString, wxDefaultPosition, wxSize(100,-1), 0, wxDefaultValidator, _T("ID_PHONE"));
	FlexGridSizer6->Add(phone, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _(":الهاتف"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT7"));
	wxFont StaticText7Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText7->SetFont(StaticText7Font);
	FlexGridSizer6->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BT = new wxChoice(this, ID_BT, wxDefaultPosition, wxSize(70,21), 0, 0, 0, wxDefaultValidator, _T("ID_BT"));
	BT->SetSelection( BT->Append(_("O+")) );
	BT->Append(_("A+"));
	BT->Append(_("B+"));
	BT->Append(_("AB+"));
	BT->Append(_("O-"));
	BT->Append(_("A-"));
	BT->Append(_("B-"));
	BT->Append(_("AB-"));
	FlexGridSizer6->Add(BT, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _(":فصيلة الدم"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	wxFont StaticText6Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText6->SetFont(StaticText6Font);
	FlexGridSizer6->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer7 = new wxFlexGridSizer(1, 2, 0, 0);
	work = new wxTextCtrl(this, ID_WORK, wxEmptyString, wxDefaultPosition, wxSize(260,-1), wxTE_RIGHT, wxDefaultValidator, _T("ID_WORK"));
	FlexGridSizer7->Add(work, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _(": المهنة"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT5"));
	wxFont StaticText5Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText5->SetFont(StaticText5Font);
	FlexGridSizer7->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer8 = new wxFlexGridSizer(0, 6, 0, 0);
	YHRF = new wxTextCtrl(this, ID_Y_HRF, wxEmptyString, wxDefaultPosition, wxSize(35,-1), 0, wxDefaultValidator, _T("ID_Y_HRF"));
	FlexGridSizer8->Add(YHRF, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	WHRF = new wxChoice(this, ID_W_HRF, wxDefaultPosition, wxSize(60,-1), 0, 0, 0, wxDefaultValidator, _T("ID_W_HRF"));
	WHRF->SetSelection( WHRF->Append(_("جانفي")) );
	WHRF->Append(_("فيفري"));
	WHRF->Append(_("مارس"));
	WHRF->Append(_("أفريل"));
	WHRF->Append(_("ماي"));
	WHRF->Append(_("جوان"));
	WHRF->Append(_("جويلية"));
	WHRF->Append(_("أوت"));
	WHRF->Append(_("سبتمبر"));
	WHRF->Append(_("اكتوبر"));
	WHRF->Append(_("فوفمبر"));
	WHRF->Append(_("ديسمبر"));
	FlexGridSizer8->Add(WHRF, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DHRF = new wxTextCtrl(this, ID_D_HRF, wxEmptyString, wxDefaultPosition, wxSize(25,-1), 0, wxDefaultValidator, _T("ID_D_HRF"));
	FlexGridSizer8->Add(DHRF, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _(":تاريخ تسجيل"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT9"));
	wxFont StaticText9Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText9->SetFont(StaticText9Font);
	FlexGridSizer8->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	Nationality = new wxTextCtrl(this, ID_NATIONALITY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT, wxDefaultValidator, _T("ID_NATIONALITY"));
	FlexGridSizer8->Add(Nationality, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _(":الجنسية"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT8"));
	wxFont StaticText8Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText8->SetFont(StaticText8Font);
	FlexGridSizer8->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	addDB = new wxStdDialogButtonSizer();
    if(_ae) addDB->AddButton(new wxButton(this, wxID_OK, _("حفظ")));
    else addDB->AddButton(new wxButton(this, wxID_OK, _("إضافة")));
	addDB->AddButton(new wxButton(this, wxID_CANCEL, _("الإلغاء")));
	addDB->Realize();
	//addDB->GetAffirmativeButton()->GetId()
	BoxSizer1->Add(addDB, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	Connect(addDB->GetCancelButton()->GetId(),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AddDialog::OnQuit);
    Connect(addDB->GetAffirmativeButton()->GetId(),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AddDialog::OnButton1Click);
	Connect(wxID_ANY,wxEVT_INIT_DIALOG,(wxObjectEventFunction)&AddDialog::OnInit);

}

AddDialog::~AddDialog()
{
	//(*Destroy(AddDialog)
	//*)
}

void AddDialog::OnInit(wxInitDialogEvent& event)
{
}

void AddDialog::OnQuit(wxCommandEvent& event)
{
    //wxMessageBox("close");
    this->EndDialog(0);
}

void AddDialog::eddDialog(listaddcmd_t elist)
{
    this->firstname->SetValue(elist.firstname);
    this->lastname->SetValue(elist.lastname);
    this->sonof->SetValue(elist.sonof);
    this->address->SetValue(elist.Address);
    this->work->SetValue(elist.work);
    this->Nationality->SetValue(elist.nationlity);
    this->phone->SetValue(elist.phone);
    this->PINC->SetValue(elist.PINC);
    this->BT->SetSelection(elist.BT);
    this->YHINC->SetValue(elist.HINC.substr(0,elist.HINC.find_first_of("/")));
    this->YHRF->SetValue(elist.HRF.substr(0,elist.HRF.find_first_of("/")));
    this->DHINC->SetValue(elist.HINC.substr(elist.HINC.find_last_of("/")+1,2));
    this->DHRF->SetValue(elist.HRF.substr(elist.HRF.find_last_of("/")+1,2));
    wxString s;    wxString l;
    s = elist.HINC;
    if((s.substr(s.find_first_of("/")+1,2) == wxString("10"))) l = s.substr(s.find_first_of("/")+1,2);
    else if((s.substr(s.find_first_of("/")+1,2) == wxString("11"))) l = s.substr(s.find_first_of("/")+1,2);
    else if((s.substr(s.find_first_of("/")+1,2) == wxString("12"))) l = s.substr(s.find_first_of("/")+1,2);
    else  l = s.substr(s.find_first_of("/")+1,1);
    this->WHINC->SetSelection(atoi(l.mb_str().data())-1);
    s = elist.HRF;
    if((s.substr(s.find_first_of("/")+1,2) == wxString("10"))) l = s.substr(s.find_first_of("/")+1,2);
    else if((s.substr(s.find_first_of("/")+1,2) == wxString("11"))) l = s.substr(s.find_first_of("/")+1,2);
    else if((s.substr(s.find_first_of("/")+1,2) == wxString("12"))) l = s.substr(s.find_first_of("/")+1,2);
    else  l = s.substr(s.find_first_of("/")+1,1);
    this->WHRF->SetSelection(atoi(l.mb_str().data())-1);
    this->_ID = elist.ID;
}

void AddDialog::OnButton1Click(wxCommandEvent& event)
{
    listaddcmd_t listadd;

    listadd.firstname = this->firstname->GetValue();
    listadd.lastname = this->lastname->GetValue();
    listadd.sonof = this->sonof->GetValue();
    listadd.Address = this->address->GetValue();
    listadd.work = this->work->GetValue();
    listadd.nationlity = this->Nationality->GetValue();
    listadd.phone = this->phone->GetValue();
    listadd.PINC = this->PINC->GetValue();
    listadd.BT = this->BT->GetSelection();
    listadd.HINC = this->YHINC->GetValue()+"/"+to_string(this->WHINC->GetSelection()+1).c_str()+"/"+this->DHINC->GetValue();
    listadd.HRF = this->YHRF->GetValue()+"/"+to_string(this->WHRF->GetSelection()+1).c_str()+"/"+this->DHRF->GetValue();
    if(!_ae) addlistcmd(listadd);
    else if (_ae){listadd.ID = this->_ID;edditlistcmd(listadd);}
    this->EndDialog(0);
}
