#include "pch.h"
#include "command.h"
#include "MyFrame.h"
#include "cmd_parser.h"
#include "utils.h"

wxString mathFuncs[] ={
    "sin",  "asin",
    "cos",  "acos",
    "tan",  "atan",
    "sinh", "asinh",
    "cosh", "acosh",
    "tanh", "atanh",
    "exp",  "log",
    "sqrt",
    "pow"
};
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
        unsigned long long end= *eval(cmd->children[1]).value.integer;
        unsigned long long step= *eval(cmd->children[2]).value.integer;
        std::cout<<start<<" "<<end<<" "<<step<<std::endl;
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
        ret.value.integer=new unsigned long long ;
        string.ToULongLong(ret.value.integer);
    }else if(isContains(mathFuncs,string)){
        ret.type=object::INTEGER;
        *ret.value.integer=0;
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