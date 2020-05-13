#include "IOSDialog.h"


#include <wx/button.h>
//#include <wx/msgdlg.h>
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>


#undef _(s)
#define _(m) wxGetTranslation(wxString::FromUTF8(m))

const long IOSDialog::ID_IOSNAME = wxNewId();
const long IOSDialog::ID_STATICTEXT3 = wxNewId();
const long IOSDialog::ID_N_NRC = wxNewId();
const long IOSDialog::ID_STATICTEXT6 = wxNewId();
const long IOSDialog::ID_D_NRC = wxNewId();
const long IOSDialog::ID_STATICTEXT5 = wxNewId();
const long IOSDialog::ID_C_NRC = wxNewId();
const long IOSDialog::ID_STATICTEXT4 = wxNewId();
const long IOSDialog::ID_EXAMCENTER = wxNewId();
const long IOSDialog::ID_STATICTEXT2 = wxNewId();
const long IOSDialog::ID_STATE = wxNewId();
const long IOSDialog::ID_STATICTEXT1 = wxNewId();


BEGIN_EVENT_TABLE(IOSDialog,wxDialog)
	//(*EventTable(IOSDialog)
	//*)
END_EVENT_TABLE()


IOSDialog::IOSDialog(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	////(*Initialize(IOSDialog)
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;
	wxFlexGridSizer* FlexGridSizer2;
	wxFlexGridSizer* FlexGridSizer3;
	wxStdDialogButtonSizer* StdDialogButtonSizer1;

	Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	BoxSizer1 = new wxBoxSizer(wxVERTICAL);
	FlexGridSizer1 = new wxFlexGridSizer(0, 2, 0, 0);
	IOSname = new wxTextCtrl(this, ID_IOSNAME, wxEmptyString, wxDefaultPosition, wxSize(260,-1), wxTE_RIGHT, wxDefaultValidator, _T("ID_IOSNAME"));
	FlexGridSizer1->Add(IOSname, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _(": اللقب و إسم مدير المدرسة"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	FlexGridSizer1->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer2 = new wxFlexGridSizer(0, 6, 0, 0);
	NNRC = new wxTextCtrl(this, ID_N_NRC, wxEmptyString, wxDefaultPosition, wxSize(100,-1), wxTE_CENTRE, wxDefaultValidator, _T("ID_N_NRC"));
	FlexGridSizer2->Add(NNRC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("/"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT6"));
	wxFont StaticText6Font(20,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText6->SetFont(StaticText6Font);
	FlexGridSizer2->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	DNRC = new wxTextCtrl(this, ID_D_NRC, wxEmptyString, wxDefaultPosition, wxSize(50,-1), wxTE_CENTRE, wxDefaultValidator, _T("ID_D_NRC"));
	FlexGridSizer2->Add(DNRC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("/"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT5"));
	wxFont StaticText5Font(20,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText5->SetFont(StaticText5Font);
	FlexGridSizer2->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CNRC = new wxTextCtrl(this, ID_C_NRC, wxEmptyString, wxDefaultPosition, wxSize(40,-1), wxTE_CENTRE, wxDefaultValidator, _T("ID_C_NRC"));
	FlexGridSizer2->Add(CNRC, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _(":رقم تسجيل سيارة"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT4"));
	wxFont StaticText4Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText4->SetFont(StaticText4Font);
	FlexGridSizer2->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer3 = new wxFlexGridSizer(0, 4, 0, 0);
	Examcenter = new wxTextCtrl(this, ID_EXAMCENTER, wxEmptyString, wxDefaultPosition, wxSize(140,-1), wxTE_RIGHT, wxDefaultValidator, _T("ID_EXAMCENTER"));
	FlexGridSizer3->Add(Examcenter, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _(":مركز الإمتحان"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT2"));
	wxFont StaticText2Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText2->SetFont(StaticText2Font);
	FlexGridSizer3->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	state = new wxTextCtrl(this, ID_STATE, wxEmptyString, wxDefaultPosition, wxSize(140,-1), wxTE_RIGHT, wxDefaultValidator, _T("ID_STATE"));
	FlexGridSizer3->Add(state, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _(": ولاية"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	FlexGridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BoxSizer1->Add(FlexGridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	StdDialogButtonSizer1 = new wxStdDialogButtonSizer();
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_OK, _("حفظ")));
	StdDialogButtonSizer1->AddButton(new wxButton(this, wxID_CANCEL, _("الإلغاء")));
	StdDialogButtonSizer1->Realize();
	BoxSizer1->Add(StdDialogButtonSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(BoxSizer1);
	BoxSizer1->Fit(this);
	BoxSizer1->SetSizeHints(this);
	Connect(StdDialogButtonSizer1->GetCancelButton()->GetId(),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&IOSDialog::OnQuit);
    Connect(StdDialogButtonSizer1->GetAffirmativeButton()->GetId(),wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&IOSDialog::OnButton1Click);

	////*)
}

void IOSDialog::getIOS(wxString name,wxString NRC,wxString Examcenter,wxString state)
{
    this->IOSname->SetValue(name);
    this->Examcenter->SetValue(Examcenter);
    this->state->SetValue(state);
    this->CNRC->SetValue(NRC.substr(NRC.find_first_of("/")+1,2));
    this->DNRC->SetValue(NRC.substr(NRC.find_first_of("/")+4,3));
    wxString s = NRC.substr(NRC.find_first_of("/")+8,NRC.find_last_of("/"));
    this->NNRC->SetValue(s.substr(0,s.Len()-1));
}

IOSDialog::~IOSDialog()
{
	//(*Destroy(IOSDialog)
	//*)
}

void IOSDialog::OnQuit(wxCommandEvent& event)
{
    //wxMessageBox("close");
    this->EndDialog(0);
}
void setIOS(wxString name,wxString NRC,wxString Examcenter,wxString state);
void IOSDialog::OnButton1Click(wxCommandEvent& event)
{
    setIOS( this->IOSname->GetValue(), "/"+this->CNRC->GetValue()+"/"+this->DNRC->GetValue()+"/"+ this->NNRC->GetValue()+
           "/",this->Examcenter->GetValue(), this->state->GetValue());
    this->EndDialog(0);
}
