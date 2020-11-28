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
void command::eval(cmd_parser::ast* command){
    wxString string=command->text.Lower();
}
void command::execute(cmd_parser::ast* command){
    eval(command);
}