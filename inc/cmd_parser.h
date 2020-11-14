#include "pch.h"
#pragma once
#ifndef CMD_PARSER_H
#define CMD_PARSER_H

namespace commandProcessor{
    class ast;
};

namespace cmd_parser{
    class ast{
    public:
        wxString text;
        std::vector<ast*> children;
    };
    std::vector<wxString> tokenize(wxString);
    ast* parse(std::vector<wxString>);
    ast* stmt();
    ast* expr();
    ast* For();
}

std::ostream& operator<<(std::ostream&,cmd_parser::ast&);

#endif // !defined(CMD_PROC_H)