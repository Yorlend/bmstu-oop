#pragma once

#include "BaseListException.h"

class OutOfBoundsException : public BaseListException
{
public:
    OutOfBoundsException(const char* filename, unsigned long line);
};
