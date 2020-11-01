#include "pch.h"

#pragma once
#ifndef COMMAND_H
#define COMMAND_H

class command{
private:
    wxString text;
    void update();    
public:
    command();

    bool append(wxString);
    bool remove(size_t start,wxString);

    wxTextCtrl *textctrl;
};

#endif // !defined(COMMAND_H)