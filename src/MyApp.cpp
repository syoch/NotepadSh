#include "pch.h"
#include "MyApp.h"

#include "MyFrame.h"

bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    //frame->texteditor->WriteText(">>>");
    //frame->texteditor->WriteText("for i in (range(1,10,sin(pi/2))) '{i}, {sin(i)}\\n'");
    //frame->texteditor->WriteText("<<<");
    //frame->Close();
    return true;
}