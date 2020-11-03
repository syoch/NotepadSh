#include "pch.h"

#pragma once
#ifndef COMMAND_H
#define COMMAND_H

class command{
private:
    wxString text;
public:
    command();

    bool append(wxString);
    bool remove(size_t start,wxString);
    void update();    

    wxTextCtrl *textctrl;
};

#endif // !defined(COMMAND_H)