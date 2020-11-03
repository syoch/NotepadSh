#include "pch.h"
#include "command.h"

command::command(){
}

void command::update(){
    
    wxString text=textctrl->GetValue();
    if(text.length() < 3)return;
    
    long insertPos=textctrl->GetInsertionPoint();
    if(text.substr(text.length()-3,(size_t)insertPos)==">>>"){
        std::cout<<"start!!!"<<std::endl;
    }
}