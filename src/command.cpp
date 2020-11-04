#include "pch.h"
#include "command.h"
#include "MyFrame.h"
command::command(){
}

void command::update(){
    static bool isInCommand;
    wxString text=target->texteditor->GetValue();
    if(text.length() < 3)return;
    
    long insertPos=target->texteditor->GetInsertionPoint();
    if(text.substr(text.length()-3,(size_t)insertPos)==">>>" && isInCommand==false){
        std::cout<<"start!!!"<<std::endl;
        isInCommand=true;
    }
    if(text.substr(text.length()-3,(size_t)insertPos)=="<<<" && isInCommand==true){
        std::cout<<"end!!!"<<std::endl;
        isInCommand=false;
    }

}