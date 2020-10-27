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
        wxMenu *file;
        wxMenu *help;
        wxMenuBar *bar;
    } menus;
    // Handlers
    void OnOpenFile(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);

    // EventTable
    wxDECLARE_EVENT_TABLE();
};

#endif // !defined(MY_FRAME_H)