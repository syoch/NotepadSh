#include "pch.h"
#include "widgetids.h"
#include "command.h"
#include "MyFrame.h"

#include <wx/file.h>
#include <fstream>

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_OpenFile, MyFrame::OnOpenFile)
    EVT_MENU(ID_SaveFile, MyFrame::OnSaveFile)
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
    if(texteditor->IsModified()){
        int ret=wxMessageBox("File not saved.\nSave to Close?","Warning",wxYES_NO);
        if(ret==wxID_YES){
            save();
        }
    }
    Close(true);
}
void MyFrame::OnAbout(wxCommandEvent &)
{
    wxMessageBox("This is a Notepad like a microsoft notepad.",
                 "About Notepad#", wxOK | wxICON_INFORMATION);
}
void MyFrame::OnOpenFile(wxCommandEvent &)
{
    // Check modified
    if(texteditor->IsModified()){
        int ret=wxMessageBox("File not saved.\nSave to Open?","Warning",wxYES_NO);
        if(ret==wxID_YES){
            save();
        }
    }
    // Ask
    path=wxLoadFileSelector("Filename","*");
    
    //Open
    wxFile file;
    file.Open(path,wxFile::OpenMode::read);
    if (file.Error()){
        panel.statusBar->SetStatusText("Failed");
        wxMessageBox("Failed to open file["+path+"]","Error");
        return;
    }
    // Clear editor
    texteditor->Clear();
    texteditor->SetModified(false);

    //　Read
    wxString buffer;
    file.ReadAll(&buffer);
    texteditor->SetValue(buffer);
    file.Close();

    // Update Title
    SetTitle(
        "Notepad#"+
        wxSplit(path,wxT('/')).Last()// basename
    );
}
void MyFrame::OnSaveFile(wxCommandEvent &)
{
    save();
    // Update Status
    texteditor->SetModified(false);
    panel.statusBar->SetStatusText("Saved");

}
void MyFrame::EnterTextEditor(wxCommandEvent &)
{
    static wxString last;

    wxString currentString=texteditor->GetValue();

    const size_t 
        last_len=last.length(),
        currentString_len=currentString.length();
    
    if(last_len < currentString_len){
        size_t diff=currentString_len-last_len;
        
        // Search End - begin
        size_t offset=0;
        while(last[last_len-offset]==currentString[currentString_len-offset])offset++;
        offset-=1;
        // Search End - end        

        wxString change;
        for (size_t i = diff+offset; i > offset; i--) // (diff ~ 0)+offset
            change+=currentString[currentString_len-i];

        command::buffer::add(change);
    }else if(last_len > currentString_len){
        const size_t size=last_len-currentString_len;

        wxString change;
        for (size_t i = 0; i < size; i++)
            change+=last[last_len-size+i];

        command::buffer::remove(last_len-size,change);
    }else if(last_len==currentString_len){
        // Pressed copy or cut?
    }

    last=currentString;
}
void MyFrame::save(){
    wxFile file;
    file.Open(path,wxFile::OpenMode::write);
    file.Write(texteditor->GetValue());
    file.Close();
}