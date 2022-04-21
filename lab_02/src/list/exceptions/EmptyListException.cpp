#include "EmptyListException.h"

EmptyListException::EmptyListException(const char* filename, unsigned long line)
    : BaseListException("empty list", filename, line)
{
}
