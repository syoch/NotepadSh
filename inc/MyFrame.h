#pragma once
#ifndef MY_FRAME_H
#define MY_FRAME_H

#include <wx/file.h>

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
    // Datas
    wxFile file;
    // Handlers
    void OnOpenFile(wxCommandEvent &event);
    void OnSaveFile(wxCommandEvent &event);
    void OnCloseFile(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);

    // EventTable
    wxDECLARE_EVENT_TABLE();
};

#endif // !defined(MY_FRAME_H)