#include "pch.h"
#include "builtinTokens.h"
#pragma once
#ifndef CMD_PROC_H
#define CMD_PROC_H

namespace commandProcessor
{
    class ast{
    public:
        wxString text;
        std::vector<ast*> children;
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
    public:
        std::vector<wxString> tokens;

        target(wxString);
        target* tokenize();
        ast* toAst();
    };
} // namespace commendProcessor

std::ostream& operator<<(std::ostream&,commandProcessor::ast&);

#endif // !defined(CMD_PROC_H)