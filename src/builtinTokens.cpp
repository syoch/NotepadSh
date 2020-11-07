#include "pch.h"
#include "builtinTokens.h"

std::vector<wxString> builtinTokens{
    "for",
    "in",
    "range",
    "if",
    "is", // like a "=="
};

std::vector<wxString> identitys{
    "(",")",","," "
};

bool isBuiltinToken(wxString str){
    auto iter = std::find(
        builtinTokens.begin(),
        builtinTokens.end(),
        str
    );
    size_t index = std::distance(builtinTokens.begin(), iter);
    return index != builtinTokens.size();
}

bool isIdentitys(wxString str){
    auto iter = std::find(
        identitys.begin(),
        identitys.end(),
        str
    );
    size_t index = std::distance(identitys.begin(), iter);
    return index != identitys.size();
}