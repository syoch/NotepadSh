#include "pch.h"
#include "command.h"

command::command(){
}

bool command::append(wxString str){
    update();
    return true;
}
bool command::remove(size_t start,wxString str){
    update();
    return true;
}

void command::update(){
}