#include "InvalidIteratorStateException.h"

InvalidIteratorStateException::InvalidIteratorStateException(const char* filename, unsigned long line)
    : BaseListException("invalid iterator state", filename, line)
{
}
