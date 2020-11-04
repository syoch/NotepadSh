#include "pch.h"

#pragma once
#ifndef CMD_PROC_H
#define CMD_PROC_H

namespace commandProcessor
{
    class target{
    public:
        target(wxString);
        wxArrayString tokenize(wxString);
    };
} // namespace commendProcessor


#endif // !defined(CMD_PROC_H)