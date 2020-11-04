#include "pch.h"
#include "command.h"
#include "MyFrame.h"
command::command(){
}

void command::update(){
    static bool isInCommand;
    static long start;
    wxString text=target->texteditor->GetValue();
    if(text.length() < 3)return;

    long insertPos=target->texteditor->GetInsertionPoint();
    if(text.substr(text.length()-3,(size_t)insertPos)==">>>" && isInCommand==false){
        start=insertPos;
        isInCommand=true;
    }
    if(text.substr(text.length()-3,(size_t)insertPos)=="<<<" && isInCommand==true){
        wxString command=text.SubString(start,insertPos-4);
        isInCommand=false;
    }

}