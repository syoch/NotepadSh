#include "pch.h"

#pragma once
#ifndef COMMAND_H
#define COMMAND_H

namespace command{
    namespace buffer
    {
        extern wxString buffer;
        bool add(wxString);
        bool remove(wxString);
    } // namespace buffer
    
}

#endif // !defined(COMMAND_H)