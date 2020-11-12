#include "pch.h"
#pragma once
#ifndef CMD_PARSER_H
#define CMD_PARSER_H

namespace commandProcessor{
    class ast;
};

namespace cmd_parser{
    commandProcessor::ast& parse(std::vector<wxString>);
    commandProcessor::ast& function();
}

#endif // !defined(CMD_PROC_H)