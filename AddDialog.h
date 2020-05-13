#ifndef ADDDIALOG_H
#define ADDDIALOG_H

//(*Headers(AddDialog)
#include <wx/choice.h>
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

struct listaddcmd_t
{int ID = 0;wxString firstname;wxString lastname; wxString sonof;wxString HINC;wxString PINC;
wxString Address;int BT=0;wxString phone;wxString work;wxString nationlity;wxString HRF;};
void addlistcmd(listaddcmd_t listadd);
void edditlistcmd(listaddcmd_t listadd);

class AddDialog: public wxDialog
{
	public:

		AddDialog(wxWindow* parent,bool ae,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~AddDialog();
		void eddDialog(listaddcmd_t elist);

		//(*Declarations(AddDialog)
		wxChoice* BT;
		wxChoice* WHINC;
		wxChoice* WHRF;
		wxStaticText* StaticText10;
		wxStaticText* StaticText11;
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxStaticText* StaticText7;
		wxStaticText* StaticText8;
		wxStaticText* StaticText9;
		wxTextCtrl* DHINC;
		wxTextCtrl* DHRF;
		wxTextCtrl* Nationality;
		wxTextCtrl* PINC;
		wxTextCtrl* YHINC;
		wxTextCtrl* YHRF;
		wxTextCtrl* address;
		wxTextCtrl* firstname;
		wxTextCtrl* lastname;
		wxTextCtrl* phone;
		wxTextCtrl* sonof;
		wxTextCtrl* work;
		//*)

	protected:

		//(*Identifiers(AddDialog)
		static const long ID_FIRSTNAME;
		static const long ID_STATICTEXT1;
		static const long ID_LASTNAME;
		static const long ID_STATICTEXT2;
		static const long ID_SONOF;
		static const long ID_STATICTEXT3;
		static const long ID_P_INC;
		static const long ID_STATICTEXT11;
		static const long ID_Y_H_INC;
		static const long ID_W_H_INC;
		static const long ID_D_H_INC;
		static const long ID_STATICTEXT10;
		static const long ID_ADDRESS;
		static const long ID_STATICTEXT4;
		static const long ID_PHONE;
		static const long ID_STATICTEXT7;
		static const long ID_BT;
		static const long ID_STATICTEXT6;
		static const long ID_WORK;
		static const long ID_STATICTEXT5;
		static const long ID_Y_HRF;
		static const long ID_W_HRF;
		static const long ID_D_HRF;
		static const long ID_STATICTEXT9;
		static const long ID_NATIONALITY;
		static const long ID_STATICTEXT8;
		//*)
        bool _ae;
	private:

        int _ID;
		void OnInit(wxInitDialogEvent& event);
		void OnQuit(wxCommandEvent& event);
		void OnButton1Click(wxCommandEvent& event);


		DECLARE_EVENT_TABLE()
};

#endif
