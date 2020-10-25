#include "MyApp.h"

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame("Notepad#", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}