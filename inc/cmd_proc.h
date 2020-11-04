#include "pch.h"

#pragma once
#ifndef CMD_PROC_H
#define CMD_PROC_H

namespace commandProcessor
{
    class target{
    private:
        wxString src;
    public:
        wxArrayString tokens;

        target(wxString);
        target* tokenize();
    };
} // namespace commendProcessor


#endif // !defined(CMD_PROC_H)