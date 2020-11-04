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
        target(wxString);
        wxArrayString tokenize();
    };
} // namespace commendProcessor


#endif // !defined(CMD_PROC_H)