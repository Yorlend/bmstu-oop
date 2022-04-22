#include "MemoryException.h"

MemoryException::MemoryException(const char* filename, unsigned long line)
    : BaseListException("memory exception", filename, line)
{
}
