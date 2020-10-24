// -*- C++ -*-
//
// generated by wxGlade 0.9.4 on Sat Oct 24 10:13:54 2020
//
// Example for compiling a single file project under Linux using g++:
//  g++ MyApp.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp
//
// Example for compiling a multi file project under Linux using g++:
//  g++ main.cpp $(wx-config --libs) $(wx-config --cxxflags) -o MyApp Dialog1.cpp Frame1.cpp
//

#include <wx/wx.h>
#include "MyFrame.h"

// begin wxGlade: ::extracode
// end wxGlade


MyFrame::MyFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxFrame(parent, id, title, pos, size, wxDEFAULT_FRAME_STYLE)
{
    // begin wxGlade: MyFrame::MyFrame
    SetSize(wxSize(400, 400));
    TextEditor = new wxTextCtrl(this, wxID_ANY, wxT("#include <stdio.h>\n\nint main(){\n    printf(\"Helloworld\\n\");\n    return 0;\n}"), wxDefaultPosition, wxDefaultSize, wxTE_BESTWRAP|wxTE_LEFT|wxTE_MULTILINE|wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB);
    StatusBar = CreateStatusBar(2);
    MenuBar = new wxMenuBar();
    wxMenu *wxglade_tmp_menu;
    wxMenuItem *wxglade_tmp_item;
    wxglade_tmp_menu = new wxMenu();
    wxglade_tmp_menu->Append(wxID_ANY, wxT("Open"), wxEmptyString);
    wxglade_tmp_menu->Append(wxID_EXIT, wxT("Close"), wxEmptyString);
    wxglade_tmp_item = wxglade_tmp_menu->Append(wxID_ANY, wxT("Setting"), wxEmptyString);
    Bind(wxEVT_MENU, &MyFrame::open_setting, this, wxglade_tmp_item->GetId());
    MenuBar->Append(wxglade_tmp_menu, wxT("File"));
    SetMenuBar(MenuBar);

    set_properties();
    do_layout();
    // end wxGlade
}


void MyFrame::set_properties()
{
    // begin wxGlade: MyFrame::set_properties
    SetTitle(wxT("NotepadSh"));
    TextEditor->SetFont(wxFont(12, wxFONTFAMILY_MODERN, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, 0, wxT("")));
    int StatusBar_widths[] = { -1, -1 };
    StatusBar->SetStatusWidths(2, StatusBar_widths);

    // statusbar fields
    const wxString StatusBar_fields[] = {
        wxT("filename"),
        wxT("ShExt"),
    };
    for(int i = 0; i < StatusBar->GetFieldsCount(); ++i) {
        StatusBar->SetStatusText(StatusBar_fields[i], i);
    }
    // end wxGlade
}


void MyFrame::do_layout()
{
    // begin wxGlade: MyFrame::do_layout
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(TextEditor, 1, wxALL|wxEXPAND, 1);
    SetSizer(sizer);
    Layout();
    // end wxGlade
}


BEGIN_EVENT_TABLE(MyFrame, wxFrame)
    // begin wxGlade: MyFrame::event_table
    // end wxGlade
END_EVENT_TABLE();


void MyFrame::open_setting(wxCommandEvent &event)  // wxGlade: MyFrame.<event_handler>
{
    event.Skip();
    // notify the user that he hasn't implemented the event handler yet
    wxLogDebug(wxT("Event handler (MyFrame::open_setting) not implemented yet"));
}


// wxGlade: add MyFrame event handlers

