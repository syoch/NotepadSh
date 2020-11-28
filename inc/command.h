#include "pch.h"
#include <sstream>

#pragma once
#ifndef COMMAND_H
#define COMMAND_H

class MyFrame;
namespace cmd_parser{
    class ast;
}
class command{
public:
    command();

    void update();
    void eval(cmd_parser::ast*);
    void execute(cmd_parser::ast*);

    MyFrame *target;
    std::stringstream output;
};

#endif // !defined(COMMAND_H)