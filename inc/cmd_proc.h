#include "pch.h"

#pragma once
#ifndef CMD_PROC_H
#define CMD_PROC_H

namespace commandProcessor
{
    class target{
    private:
        wxString src;
        void fix_function();
    public:
        wxArrayString tokens;

        target(wxString);
        target* tokenize();
        target* fix();
    };
} // namespace commendProcessor


#endif // !defined(CMD_PROC_H)