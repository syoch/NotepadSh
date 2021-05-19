#include "pch.h"
#pragma once
#ifndef UTILS_H
#define UTILS_H

/*
    Contains Template Utilitys
*/

template <typename T, std::size_t size>
bool isContains(T (&arr)[size], T val)
{
    for (size_t i = 0; i < size; i++)
    {
        if (arr[i] == val)
        {
            return true;
        }
    }
    return false;
}
#endif // !defined(UTILS_H)