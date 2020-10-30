#include "pch.h"
#include "command.h"

// buffer: wxString command::buffer::buffer;

bool command::buffer::add(wxString str){
    std::cout<<"add"<< str;
    return true;
}
bool command::buffer::remove(wxString str){
    std::cout<<"rem"<<str;
    return true;
}