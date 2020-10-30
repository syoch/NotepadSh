#include "pch.h"
#include "widgetids.h"
#include "MyFrame.h"

#include <wx/file.h>
#include <fstream>

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_OpenFile, MyFrame::OnOpenFile)
    EVT_MENU(ID_SaveFile, MyFrame::OnSaveFile)
    EVT_MENU(ID_CloseFile, MyFrame::OnCloseFile)
    EVT_TEXT(ID_TextEditor,MyFrame::EnterTextEditor)
    EVT_MENU(wxID_EXIT, MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

MyFrame::MyFrame()
       : wxFrame(NULL, wxID_ANY,wxT("NotepadSH"), wxDefaultPosition, wxSize(400,400))
{
    // MenuBar
    // - File
    panel.file = new wxMenu;
    panel.file->Append(ID_OpenFile, "&Open File\tCtrl-O",
                     "Open a file.");
    panel.file->Append(ID_SaveFile, "&Save File\tCtrl-O",
                     "Save a file.");
    panel.file->Append(ID_CloseFile, "&Close File\tCtrl-O",
                     "Close opened file.");
    panel.file->AppendSeparator();
    panel.file->Append(wxID_EXIT);
    // - Help
    panel.help = new wxMenu;
    panel.help->Append(wxID_ABOUT);
    // - Bar
    panel.bar = new wxMenuBar;
    panel.bar->Append(panel.file, "&File");
    panel.bar->Append(panel.help, "&Help");
    SetMenuBar(panel.bar);
    // StatusBar
    panel.statusBar = new wxStatusBar(this);
    SetStatusBar(panel.statusBar);
    // panel
    panel.panel=new  wxPanel(this,wxID_ANY);
    // - sizer
    panel.sizer = new wxBoxSizer(wxVERTICAL);
    // - - add childs
    // - - - text editor
    texteditor = new wxTextCtrl(panel.panel,ID_TextEditor,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_MULTILINE);
    texteditor->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("")));
    panel.sizer->Add(texteditor,1,wxALL|wxEXPAND,1);
    // - Set sizer
    panel.panel->SetSizer(panel.sizer);
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
void MyFrame::OnOpenFile(wxCommandEvent &)
{
    if(file.IsOpened()){
        file.Close();
    }
    // Ask
    wxString name=wxLoadFileSelector("Filename","*");
    
    //Open
    file.Open(name,wxFile::OpenMode::read);
    if (file.Error()){
        panel.statusBar->SetStatusText("Failed");
        wxMessageBox("Failed to open file["+name+"]","Error");
        return;
    }
    // Clear editor
    texteditor->Clear();

    //　Read
    wxString buffer;
    file.ReadAll(&buffer);
    texteditor->SetValue(buffer);
    SetTitle(
        "Notepad#"+
        wxSplit(name,wxT('/')).Last()// basename
    );
}
void MyFrame::OnSaveFile(wxCommandEvent &)
{
    file.Write(texteditor->GetValue());
    file.Flush();

    // Update Status
    panel.statusBar->SetStatusText("Saved");

}
void MyFrame::OnCloseFile(wxCommandEvent &)
{
    // TODO: Check Edited `texteditor`
    file.Close();
    
    // Update Status
    panel.statusBar->SetStatusText("Closed");
}
void MyFrame::EnterTextEditor(wxCommandEvent &event)
{
    static wxString last;

    wxString currentString=texteditor->GetValue();

    const size_t 
        last_len=last.length(),
        currentString_len=currentString.length();
    
    if(last_len < currentString_len){
        std::cout<<"add: ";
        size_t diff=currentString_len-last_len;
        for (size_t i = diff; i > 0; i--)
        {
            std::cout<<(wxChar)currentString[currentString_len-i]<<" ";
        }
        
        std::cout<<std::endl;
    }else if(currentString_len+1 == last_len){
        std::cout<<"backspace"<<std::endl;
    }else{
        std::cout
            <<last<<"["<<last_len<<"]"
            <<" "
            <<currentString<<"["<<currentString_len<<"]"<<std::endl;
    }

    last=currentString;
}