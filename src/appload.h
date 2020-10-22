#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
class loader_frame;
class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        {
            loader_frame *frame = new loader_frame();
            frame->Show(true);
            return true;
        }
    }
};
wxIMPLEMENT_APP(MyApp);

#undef loader_frame