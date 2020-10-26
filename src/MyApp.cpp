#include "pch.h"
#include "MyApp.h"

#include "MyFrame.h"

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("Notepad#", wxDefaultPosition, wxSize(400, 400));
    frame->Show(true);
    return true;
}