#include "pch.h"

#pragma once
#ifndef BUILTINTOKENS_H
#define BUILTINTOKENS_H

extern std::vector<wxString> builtinTokens;

bool isBuiltinToken(wxString str);

#endif // !defined(BUILTINTOKENS_H)