#include "cmd_parser.h"
#include "cmd_proc.h" // ast

using namespace commandProcessor;
using namespace cmd_parser;

std::vector<wxString> tokens;

wxString getToken(){
    static int i=0;
    return tokens[i++];
}

ast* cmd_parser::parse(std::vector<wxString> _tokens){
    tokens=_tokens;
    return function();
}
ast* cmd_parser::function(){
    ast* a=new ast;
    a->text=getToken();
    return a;
}