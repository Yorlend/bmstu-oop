#pragma once

#include "BaseListException.h"

class InvalidCountException : public BaseListException
{
public:
    InvalidCountException(const char* filename, unsigned long line);
};
