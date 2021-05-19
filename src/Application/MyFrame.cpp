#include "pch.h"
#include "widgetids.h"
#include "MyFrame.h"

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_OpenFile, MyFrame::OnOpenFile)
        EVT_MENU(ID_SaveFile, MyFrame::OnSaveFile)
            EVT_TEXT(ID_TextEditor, MyFrame::EnterTextEditor)
                EVT_MENU(wxID_EXIT, MyFrame::OnExit)
                    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
                        wxEND_EVENT_TABLE()

                            MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, wxT("NotepadSH"), wxDefaultPosition, wxSize(400, 400))
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
    panel.panel = new wxPanel(this, wxID_ANY);
    // - sizer
    panel.sizer = new wxBoxSizer(wxVERTICAL);
    // - - add childs
    // - - - text editor
    texteditor = new wxTextCtrl(panel.panel, ID_TextEditor, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PROCESS_ENTER | wxTE_PROCESS_TAB | wxTE_MULTILINE);
    texteditor->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("")));
    panel.sizer->Add(texteditor, 1, wxALL | wxEXPAND, 1);
    // - Set sizer
    panel.panel->SetSizer(panel.sizer);
    Layout();
}
void MyFrame::OnExit(wxCommandEvent &)
{
    if (texteditor->IsModified())
    {
        int ret = wxMessageBox("File not saved.\nSave to Close?", "Warning", wxYES_NO);
        if (ret == wxID_YES)
        {
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
    if (texteditor->IsModified())
    {
        int ret = wxMessageBox("File not saved.\nSave to Open?", "Warning", wxYES_NO);
        if (ret == wxID_YES)
        {
            save();
        }
    }
    // Ask
    path = wxLoadFileSelector("Filename", "*");

    //Open
    wxFile file;
    file.Open(path, wxFile::OpenMode::read);
    if (file.Error())
    {
        panel.statusBar->SetStatusText("Failed");
        wxMessageBox("Failed to open file[" + path + "]", "Error");
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
        "Notepad#" +
        wxSplit(path, wxT('/')).Last() // basename
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
    //command_processer.update();
}
void MyFrame::save()
{
    wxFile file;
    file.Open(path, wxFile::OpenMode::write);
    file.Write(texteditor->GetValue());
    file.Close();
}