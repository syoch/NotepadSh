#include "frame.h"
MyFrame::MyFrame() : wxFrame(NULL, wxID_ANY, "notepad#")
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(wxID_EXIT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    SetMenuBar(menuBar);

    // Status Bar
    CreateStatusBar();
    SetStatusText("Ready");
}