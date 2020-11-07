#include "pch.h"

#pragma once
#ifndef BUILTINTOKENS_H
#define BUILTINTOKENS_H

extern std::vector<wxString> builtinTokens;
extern std::vector<wxString> identitys;

bool isBuiltinToken(wxString str);
bool isIdentitys(wxString str);

#endif // !defined(BUILTINTOKENS_H)