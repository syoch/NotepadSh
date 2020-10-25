#include "MyFrame.h"
#include "widgetids.h"

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_OpenFile, MyFrame::OnOpenFile)
    EVT_MENU(wxID_EXIT, MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

MyFrame::MyFrame(const wxString &title, const wxPoint &pos, const wxSize &size)
       : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    // MenuBar
    // - File
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_OpenFile, "&Open File\tCtrl-O",
                     "Open a file.");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    // - Help
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    // - Bar
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    // StatusBar
    // - Create
    CreateStatusBar();
    // - Show
    SetStatusText("Welcome to wxWidgets!");
}
void MyFrame::OnExit(wxCommandEvent &event)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox("This is a Notepad like a microsoft notepad.",
                 "About Notepad#", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnOpenFile(wxCommandEvent &event) // TODO :OnOpenFIle implemented
{
    //wxString file=wxFileSelector("file to open.");
    
}