#include "cmd_parser.h"
#include "cmd_proc.h" // ast

using namespace commandProcessor;
using namespace cmd_parser;

std::vector<wxString> tokens;
static size_t i=0;

wxString getToken(){
    i+=1;
    if(i>tokens.size()){
        throw "Over:Index";
    }
    return tokens[i-1];
}
wxString peekToken(){
    if(i>tokens.size()){
        throw "Over:Index";
    }
    return tokens[i];
}
wxString nextTokenOrDefault(){
    if(i+1>tokens.size()){
        return "";
    }
    return tokens[i+1];
}
bool hasData(){
    return i < tokens.size();
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
    while(hasData()){
        a->children.push_back(expr());
    }
    return a;
}