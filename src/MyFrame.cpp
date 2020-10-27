#include "pch.h"
#include "MyFrame.h"

#include "widgetids.h"
#include <fstream>


wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_OpenFile, MyFrame::OnOpenFile)
    EVT_MENU(wxID_EXIT, MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

MyFrame::MyFrame()
       : wxFrame(NULL, wxID_ANY,wxT("NotepadSH"), wxDefaultPosition, wxSize(400,400))
{
    // MenuBar
    // - File
    menus.file = new wxMenu;
    menus.file->Append(ID_OpenFile, "&Open File\tCtrl-O",
                     "Open a file.");
    menus.file->AppendSeparator();
    menus.file->Append(wxID_EXIT);
    // - Help
    menus.help = new wxMenu;
    menus.help->Append(wxID_ABOUT);
    // - Bar
    menus.bar = new wxMenuBar;
    menus.bar->Append(menus.file, "&File");
    menus.bar->Append(menus.help, "&Help");
    SetMenuBar(menus.bar);
    // StatusBar
    statusBar = new wxStatusBar(this);
    SetStatusBar(statusBar);
    // panel
    wxPanel *panel=new  wxPanel(this,wxID_ANY);
    // - sizer
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    // - - add childs
    // - - - text editor
    texteditor = new wxTextCtrl(panel,wxID_ANY,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_MULTILINE);
    texteditor->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("")));
    sizer->Add(texteditor,1,wxALL|wxEXPAND,1);
    // - Set sizer
    panel->SetSizer(sizer);
    Layout();
}
void MyFrame::OnExit(wxCommandEvent &)
{
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent &)
{
    wxMessageBox("This is a Notepad like a microsoft notepad.",
                 "About Notepad#", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnOpenFile(wxCommandEvent &) // TODO :OnOpenFIle implemented
{
    //wxString name=wxFileSelector("file to open.");
    
    // Debug code
    wxString name=wxString::FromAscii("./MakeFile");
    // end of debug code

    std::cout<<"DEBUG:"<<name<<std::endl;
    std::ifstream file(name);

}