#include "pch.h"
#include <sstream>

#pragma once
#ifndef COMMAND_H
#define COMMAND_H

class MyFrame;
namespace cmd_parser{
    class ast;
}
struct object{
    union{
        std::vector<wxString>* string;
        std::vector<int>* integer;
    } value;
    enum{
        STRING,
        INTEGER
    } type;
};
typedef std::vector<object> objects;
class command{
public:
    command();

    void update();
    objects evalIterator(cmd_parser::ast*);
    object eval(cmd_parser::ast*);
    void execute(cmd_parser::ast*);

    MyFrame *target;
    std::stringstream output;
};

#endif // !defined(COMMAND_H)