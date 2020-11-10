#include "pch.h"
#include "builtinTokens.h"
#pragma once
#ifndef CMD_PROC_H
#define CMD_PROC_H

namespace commandProcessor
{
    class ast{
    public:
        wxString procname;
        wxArrayString args;
    };
    class target{
    public:
        enum TokenType{
            STRING,
            NUMBER,
            NAME,
            BUILTIN,
            IDENTITY,
            UNKNOWN
        };
    private:
        wxString src;
        void fix_function();
    public:
        std::vector<std::pair<TokenType,wxString>> tokens;

        target(wxString);
        target* tokenize();
        target* fix();
    };
} // namespace commendProcessor


#endif // !defined(CMD_PROC_H)