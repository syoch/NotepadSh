#include "pch.h"

#pragma once
#ifndef COMMAND_H
#define COMMAND_H

class MyFrame;

class command{
public:
    command();

    void update();    

    MyFrame *target;
};

#endif // !defined(COMMAND_H)