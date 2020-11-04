#include "pch.h"
#include "command.h"
#include "MyFrame.h"
command::command(){
}

void command::update(){
    
    wxString text=target->texteditor->GetValue();
    if(text.length() < 3)return;
    
    long insertPos=target->texteditor->GetInsertionPoint();
    if(text.substr(text.length()-3,(size_t)insertPos)==">>>"){
        std::cout<<"start!!!"<<std::endl;
    }
    if(text.substr(text.length()-3,(size_t)insertPos)=="<<<"){
        std::cout<<"stop!!!"<<std::endl;
    }
}