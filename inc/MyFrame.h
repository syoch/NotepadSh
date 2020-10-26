#pragma once
#ifndef MY_FRAME_H
#define MY_FRAME_H

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

private:
    void OnOpenFile(wxCommandEvent &event);
    void OnExit(wxCommandEvent &event);
    void OnAbout(wxCommandEvent &event);


    wxDECLARE_EVENT_TABLE();
};

#endif // !defined(MY_FRAME_H)