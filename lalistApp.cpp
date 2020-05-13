/***************************************************************
 * Name:      lalistApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2012-03-14
 * Copyright:  ()
 * License:
 **************************************************************/

#include "lalistApp.h"

#include "lalistMain.h"
#include <wx/image.h>
/*
#undef _(s)
#define _(m) wxGetTranslation(wxString::FromUTF8(m))
//*/

IMPLEMENT_APP(lalistApp);

bool lalistApp::OnInit()
{

   // wxInitAllImageHandlers();
    lalistFrame* Frame = new lalistFrame(0);
    Frame->Show();
    SetTopWindow(Frame);
    return true;

}
