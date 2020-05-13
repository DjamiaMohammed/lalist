/***************************************************************
 * Name:      lalistMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2012-03-14
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef LALISTMAIN_H
#define LALISTMAIN_H
#include <vector>
//(*Headers(lalistFrame)
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/combobox.h>
#include <wx/frame.h>
#include <wx/gbsizer.h>
#include <wx/grid.h>
#include <wx/menu.h>
#include <wx/notebook.h>
#include <wx/panel.h>
#include <wx/scrolwin.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
//*)


class lalistFrame: public wxFrame
{
    public:

        lalistFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~lalistFrame();
    private:
        void OnReflishto(wxString tname);
        void OnReflish();
        void OnReLoad();
        void OnRLoad(wxCommandEvent& event);
        //(*Handlers(lalistFrame)

        void OnSettingClick(wxCommandEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnaddbutClick(wxCommandEvent& event);
        void OneditbutClick(wxCommandEvent& event);
        void OndeletbutClick(wxCommandEvent& event);
        void OnupgradebutClick(wxCommandEvent& event);
        void OnaddtolebutClick(wxCommandEvent& event);
        void OndocxexportClick(wxCommandEvent& event);
        void OnCTEOSelect(wxCommandEvent& event);
        //*)
        void OntlistpRangeSelected( wxGridRangeSelectEvent& ev);
        //(*Identifiers(lalistFrame)
        static const long ID_ADDBUT;
        static const long ID_EDITBUT;
        static const long ID_DELETBUT;
        static const long ID_UPGRADEBUT;
        static const long ID_ADDTOLEBUT;
        static const long ID_EXAMCENTERL;
        static const long ID_STATICTEXT7;
        static const long ID_STATEL;
        static const long ID_STATICTEXT5;
        static const long ID_NRCL;
        static const long ID_STATICTEXT3;
        static const long ID_NAMEL;
        static const long ID_STATICTEXT1;
        static const long ID_tlistp;
        static const long ID_SCROLLEDWINDOW1;
        static const long ID_PANEL1;
        static const long ID_EXAMCENTERL1;
        static const long ID_STATICTEXT10;
        static const long ID_STATEL1;
        static const long ID_STATICTEXT12;
        static const long ID_NAMEL1;
        static const long ID_STATICTEXT16;
        static const long ID_TLISTEN;
        static const long ID_SCROLLEDWINDOW2;
        static const long ID_YE;
        static const long ID_STATICTEXT2;
        static const long ID_ME;
        static const long ID_STATICTEXT4;
        static const long ID_DE;
        static const long ID_NRCL1;
        static const long ID_STATICTEXT14;
        static const long ID_EXPORT;
        static const long ID_PANEL2;
        static const long ID_TLISTEO;
        static const long ID_SCROLLEDWINDOW3;
        static const long ID_DATEO;
        static const long ID_DATEO2;
        static const long ID_NRCO;
        static const long ID_NRCO2;
        static const long ID_CTEO;
        static const long ID_PANEL3;
        static const long ID_NOTEBOOK1;
        static const long idMenuSetting;
        static const long idrefload;
        static const long idMenuQuit;
        static const long idMenuAbout;
        //*)
        static const long idReflish;

        //(*Declarations(lalistFrame)
        wxButton* addbut;
        wxButton* addtolebut;
        wxButton* deletbut;
        wxButton* docxexport;
        wxButton* editbut;
        wxButton* upgradebut;
        wxChoice* CTEO;
        wxComboBox* me;
        wxGrid* tlisten;
        wxGrid* tlisteo;
        wxGrid* tlistp;
        wxMenuItem* Menu3;
        wxMenuItem* MenuItem3;
        wxNotebook* Notebook1;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxPanel* Panel3;
        wxScrolledWindow* ScrolledWindow1;
        wxScrolledWindow* ScrolledWindow2;
        wxScrolledWindow* ScrolledWindow3;
        wxStaticText* DATEO2;
        wxStaticText* NRCL1;
        wxStaticText* NRCL;
        wxStaticText* NRCO2;
        wxStaticText* NRCO;
        wxStaticText* StaticText10;
        wxStaticText* StaticText12;
        wxStaticText* StaticText14;
        wxStaticText* StaticText16;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStaticText* StaticText4;
        wxStaticText* StaticText5;
        wxStaticText* StaticText7;
        wxStaticText* dateo;
        wxStaticText* examcenterl1;
        wxStaticText* examcenterl;
        wxStaticText* namel1;
        wxStaticText* namel;
        wxStaticText* statel1;
        wxStaticText* statel;
        wxTextCtrl* de;
        wxTextCtrl* ye;
        //*)
        wxMenuItem* Menu4;

        DECLARE_EVENT_TABLE()
};

#endif // LALISTMAIN_H
