#include "cmd_parser.h"

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
bool hasData(){
    return i < tokens.size();
}

std::ostream& operator<<(std::ostream &st,ast &ast){
    st<<ast.text;
    if(ast.children.size()!=0){
        st<<"[";
        for(auto child:ast.children){
            st<<*child;
        }
        st<<"]";
    }else{
        st<<",";
    }
    return st;
}

std::vector<wxString> cmd_parser::tokenize(wxString src)
{
    // split
    std::vector<wxString> tokens;
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
    return tokens;
}
ast* cmd_parser::parse(std::vector<wxString> _tokens){
    tokens=_tokens;
    return stmt();
}
ast* cmd_parser::expr(){
    ast* a=new ast;
    a->text=getToken();
    if(a->text.IsWord() && peekToken()=="("){
        getToken(); // skip "("
        while(peekToken()!=")"){
            if(peekToken()==",") // argument split
            {
                i++;
                continue;
            }
            a->children.push_back(expr());
        }
        getToken();
    }
    return a;
}
ast* cmd_parser::stmt(){
    wxString function=peekToken();
    if(function=="for"){
        return For();
    }
    else{
        ast* a=new ast;
        a->text=function;
        while(hasData()){
            a->children.push_back(expr());
        }
        return a;
    }
}
ast* cmd_parser::For(){
    ast* a=new ast;
    a->text=getToken();
    if(peekToken() == "in")getToken();//skip
    while(hasData()){
        a->children.push_back(expr());
    }
    return a;
}
