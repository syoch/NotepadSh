#include "pch.h"
#include "command.h"

wxString command::buffer::buffer;

bool command::buffer::add(wxString str){
    command::buffer::buffer+=str;
    command::buffer::update();
    return true;
}
bool command::buffer::remove(size_t start,wxString str){
    command::buffer::buffer.Remove(start,str.length());
    command::buffer::update();
    return true;
}

void command::buffer::update(){
    std::cout<<command::buffer::buffer;
}