#ifndef IOSDIALOG_H
#define IOSDIALOG_H

//(*Headers(IOSDialog)
#include <wx/dialog.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)

class IOSDialog: public wxDialog
{
	public:

		IOSDialog(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		void getIOS(wxString name,wxString NRC,wxString Examcenter,wxString state);
		virtual ~IOSDialog();

		////(*Declarations(IOSDialog)
		wxStaticText* StaticText1;
		wxStaticText* StaticText2;
		wxStaticText* StaticText3;
		wxStaticText* StaticText4;
		wxStaticText* StaticText5;
		wxStaticText* StaticText6;
		wxTextCtrl* CNRC;
		wxTextCtrl* DNRC;
		wxTextCtrl* Examcenter;
		wxTextCtrl* IOSname;
		wxTextCtrl* NNRC;
		wxTextCtrl* state;
		////*)

	protected:

		//(*Identifiers(IOSDialog)
		static const long ID_IOSNAME;
		static const long ID_STATICTEXT3;
		static const long ID_N_NRC;
		static const long ID_STATICTEXT6;
		static const long ID_D_NRC;
		static const long ID_STATICTEXT5;
		static const long ID_C_NRC;
		static const long ID_STATICTEXT4;
		static const long ID_EXAMCENTER;
		static const long ID_STATICTEXT2;
		static const long ID_STATE;
		static const long ID_STATICTEXT1;
		//*)

	private:

		//(*Handlers(IOSDialog)
		//*)

        void OnQuit(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);

		DECLARE_EVENT_TABLE()
};

#endif
