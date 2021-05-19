#pragma once
#ifndef MY_FRAME_H
#define MY_FRAME_H

#include <wx/file.h>
#include <fstream>

class MyFrame : public wxFrame
{
public:
  MyFrame();
  // Widgets
  wxTextCtrl *texteditor;

private:
  // constructing
  void setupBar();
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
  wxString path;
  wxString buffer;
  // functions
  void save();
  // Handlers
  void OnOpenFile(wxCommandEvent &);
  void OnSaveFile(wxCommandEvent &);
  void EnterTextEditor(wxCommandEvent &);
  void OnExit(wxCommandEvent &);
  void OnAbout(wxCommandEvent &);

  // EventTable
  wxDECLARE_EVENT_TABLE();
};

#endif // !defined(MY_FRAME_H)