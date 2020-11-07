#include "pch.h"

#pragma once
#ifndef CMD_PROC_H
#define CMD_PROC_H

namespace commandProcessor
{
    class target{
    public:
        enum TokenType{
            LITERAL,
            NUMBER,
            NAME,
            BUILTIN,
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