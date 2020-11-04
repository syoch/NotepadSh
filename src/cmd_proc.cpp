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
    char ch;
    size_t i;
    for (i = 0; i < src.length(); i++)
    {
        ch = src[i];
        if (ch == ' ' || ch == ',' || ch == '(' || ch == ')')
        {
            if (!buffer.empty())
                tokens.push_back(buffer);
            if (ch != ' ')
                tokens.push_back(ch);
            buffer = "";
            continue;
        }
        buffer += ch;
        if (ch == '\'')
        {
            i++; // skip first '
            size_t before = i;
            while (src[i] != '\'')
                i++;
            tokens.push_back(buffer + src.substr(before, i));
            buffer = "";
            //i+=1; // skip last '
        }
    }
    if (!buffer.empty())
    {
        tokens.push_back(buffer);
    }
    return this;
}