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
    return stmt();
}
ast* cmd_parser::expr(){
    ast* a=new ast;
    a->text=getToken();
    return a;
}
ast* cmd_parser::stmt(){
    ast* a=new ast;
    a->text=getToken();
    return a;
}