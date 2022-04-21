#pragma once

#include "BaseListException.h"

class InvalidIteratorStateException : public BaseListException
{
public:
    InvalidIteratorStateException(const char* filename, unsigned long line);
};
