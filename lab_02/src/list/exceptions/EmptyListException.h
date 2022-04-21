#pragma once

#include "BaseListException.h"

class EmptyListException : public BaseListException
{
public:
    EmptyListException(const char* filename, unsigned long line);
};
