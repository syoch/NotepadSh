#include "pch.h"
#include <sstream>

#pragma once
#ifndef COMMAND_H
#define COMMAND_H

class MyFrame;
namespace cmd_parser{
    class ast;
}
struct cmdIterator{
    union{
        wxString* string;
        int* integer;
    } value;
    enum{
        STRING,
        INTEGER
    } type;
};
class command{
public:
    command();

    void update();
    cmdIterator* evalIterator(cmd_parser::ast*);
    void eval(cmd_parser::ast*);
    void execute(cmd_parser::ast*);

    MyFrame *target;
    std::stringstream output;
};

#endif // !defined(COMMAND_H)