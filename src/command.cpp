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
objects command::evalIterator(cmd_parser::ast* cmd){
    objects ret;
    wxString name=cmd->text.Lower();
    std::cout<<name<<std::endl;
    if(name=="range"){
        // type of a  ==  integer
        unsigned long long start= *eval(cmd->children[0]).value.integer;
        eval(cmd->children[1]);
        eval(cmd->children[2]);
    }
    return ret;
}
object command::eval(cmd_parser::ast* command){
    object ret;
    wxString string=command->text.Lower();
    if(string=="for"){
        std::cout<<"for "<<command->children[0]->text<<std::endl;
        evalIterator(command->children[1]->children[0]);
        eval(command->children[2]);
    }else if(string.IsNumber() && command->children.size()==0){
        ret.type=object::INTEGER;
        string.ToULongLong(ret.value.integer);
    }else{
        std::cout<<"unk "<<*command<<std::endl;
    }
    return ret;
}
void command::execute(cmd_parser::ast* command){
    output.clear();
    this->eval(command);
    std::cout<<output.rdbuf()<<std::endl;
}