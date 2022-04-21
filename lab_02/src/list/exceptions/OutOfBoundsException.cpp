#include "OutOfBoundsException.h"

OutOfBoundsException::OutOfBoundsException(const char *filename, unsigned long line)
    : BaseListException("index out of bounds", filename, line)
{
}
