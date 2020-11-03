#include "pch.h"

#pragma once
#ifndef COMMAND_H
#define COMMAND_H

class command{
public:
    command();

    void update();    

    wxTextCtrl *textctrl;
    wxString *buffer;
};

#endif // !defined(COMMAND_H)