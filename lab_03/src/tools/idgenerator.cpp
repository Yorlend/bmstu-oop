#include "idgenerator.hpp"

size_t IdGenerator::nextId = 0;

size_t IdGenerator::generateId()
{
    return nextId++;
}
