#include "pch.h"

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
    void execute(wxString);

    MyFrame *target;
};

#endif // !defined(COMMAND_H)