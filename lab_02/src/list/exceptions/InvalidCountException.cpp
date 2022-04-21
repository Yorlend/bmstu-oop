#include "InvalidCountException.h"

InvalidCountException::InvalidCountException(const char* filename, unsigned long line)
    : BaseListException("invalid count", filename, line)
{
}
