#include "pch.h"
#include "command.h"

command::command(){
    text="";
}

bool command::append(wxString str){
    text+=str;
    update();
    return true;
}
bool command::remove(size_t start,wxString str){
    text.Remove(start,str.length());
    update();
    return true;
}

void command::update(){
}