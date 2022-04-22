#pragma once

#include "BaseListException.h"

class MemoryException : public BaseListException
{
public:
    MemoryException(const char* filename, unsigned long line);
};
