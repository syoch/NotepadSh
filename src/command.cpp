#include "pch.h"
#include "command.h"
#include "MyFrame.h"
#include "cmd_parser.h"

command::command(){
}

void command::update(){
    static bool isInCommand;
    static long start;
    wxString text=target->texteditor->GetValue();
    if(text.length() < 3)return;

    long insertPos=target->texteditor->GetInsertionPoint();
    wxString suffix=text.substr(text.length()-3,(size_t)insertPos);
    if(suffix==">>>" && isInCommand==false){
        start=insertPos;
        isInCommand=true;
    }
    if(suffix=="<<<" && isInCommand==true){
        wxString command=text.SubString(start,insertPos-4);
        command::execute(cmd_parser::parse(command));
        isInCommand=false;
    }

}
cmdIterator* command::evalIterator(cmd_parser::ast* cmd){
    cmdIterator *a = new cmdIterator;
    wxString name=cmd->text.Lower();
    std::cout<<name<<std::endl;
    if(name=="range"){
        a->type=a->INTEGER;
        eval(cmd->children[0]);
        eval(cmd->children[1]);
        eval(cmd->children[2]);
    }
    return a;
}
void command::eval(cmd_parser::ast* command){
    wxString string=command->text.Lower();
    if(string=="for"){
        std::cout<<*command<<std::endl;
        std::cout<<"for "<<command->children[0]->text<<std::endl;
        evalIterator(command->children[1]->children[0]);
        eval(command->children[2]);
    }else{
        std::cout<<"unk "<<*command<<std::endl;
    }
}
void command::execute(cmd_parser::ast* command){
    this->eval(command);
}