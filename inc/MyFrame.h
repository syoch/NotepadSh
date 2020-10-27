#pragma once
#ifndef MY_FRAME_H
#define MY_FRAME_H

class MyFrame : public wxFrame
{
public:
    MyFrame();

private:
    // Widgets
    wxTextCtrl *texteditor;
    struct
    {
        wxPanel *panel;
        wxBoxSizer *sizer;
        wxMenu *file;
        wxMenu *help;
        wxMenuBar *bar;
        wxStatusBar *statusBar;
    } panel;
    // Handlers
    void OnOpenFile(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);

    // EventTable
    wxDECLARE_EVENT_TABLE();
};

#endif // !defined(MY_FRAME_H)