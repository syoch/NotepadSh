#include "cmd_parser.h"
#include "cmd_proc.h" // ast

using namespace commandProcessor;
using namespace cmd_parser;

std::vector<wxString> tokens;

ast& parse(std::vector<wxString> _tokens){
    tokens=_tokens;
}
ast& function(){

}