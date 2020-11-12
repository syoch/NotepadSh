#include "pch.h"
#include "cmd_proc.h"
#include "cmd_parser.h"

commandProcessor::target::target(wxString _src)
    : src(_src)
{
    
}

commandProcessor::target* commandProcessor::target::tokenize()
{
    // split
    wxString buffer;
    wxUniChar ch;
    size_t i;
    for (i = 0; i < src.length(); i++)
    {
        ch = src[i];
        if(wxIsdigit(ch))
        {
            size_t start=i;
            while(wxIsdigit(src[i]))i++;
            i--;

            tokens.push_back(src.SubString(start,i));
        }else if(ch=='\'')
        {
            size_t start=i;
            i++;
            while(src[i]!='\''){
                i++;
                if(src[i]=='\\')i++;
            }

            tokens.push_back(src.SubString(start,i));
        }else if(wxIsalpha(ch)){
            size_t start=i;
            while(wxIsalpha(src[i]))i++;
            i--;

            tokens.push_back(src.SubString(start,i));
        }else if(ch==' '){
            continue;
        }else {
            tokens.push_back(ch);
        }
    }
    if (!buffer.empty())
    {
        tokens.push_back(buffer);
    }
    return this;
}
commandProcessor::ast* commandProcessor::target::toAst(){
    return cmd_parser::parse(tokens);
}

std::ostream& operator<<(std::ostream &st,commandProcessor::ast &ast){
    st<<ast.text<<"[";
    for(auto child:ast.children){
        st<<*child;
    }
    st<<"]";
    return st;
}