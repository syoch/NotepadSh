#include "pch.h"
#include "cmd_proc.h"

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

            tokens.push_back(std::make_pair(NUMBER,src.SubString(start,i)));
        }else if(ch=='\'')
        {
            size_t start=i;
            i++;
            while(src[i]!='\''){
                i++;
                if(src[i]=='\\')i++;
            }

            tokens.push_back(std::make_pair(STRING,src.SubString(start,i)));
        }else if(wxIsalpha(ch)){
            size_t start=i;
            while(wxIsalpha(src[i]))i++;
            i--;
            wxString token=src.SubString(start,i);
            if(isBuiltinToken(token)){
                tokens.push_back(std::make_pair(BUILTIN,token));
            }else{
                tokens.push_back(std::make_pair(NAME,token));
            }
        }else if(isIdentitys(ch)){
            tokens.push_back(std::make_pair(IDENTITY,ch));
        }else{
            tokens.push_back(std::make_pair(UNKNOWN,ch));
        }
    }
    if (!buffer.empty())
    {
        tokens.push_back(std::make_pair(UNKNOWN,buffer));
    }
    return this;
}

commandProcessor::target* commandProcessor::target::fix(){
    fix_function();
    return this;
}
void commandProcessor::target::fix_function(){
    
}
commandProcessor::ast commandProcessor::target::toAst(){
    ast a;
    a.procname=tokens[0].second;
    for (size_t i = 1; i < tokens.size(); i++)
    {
        a.args.push_back(tokens[i].second);
    }
    
    return a;
}