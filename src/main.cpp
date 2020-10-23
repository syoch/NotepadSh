#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "frame.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame *frame = new MyFrame();
        frame->Show(true);
        return true;
    }
};
wxIMPLEMENT_APP(MyApp);