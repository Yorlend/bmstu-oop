#include "idgenerator.hpp"

size_t IdGenerator::nextId = 1;

size_t IdGenerator::generateId()
{
    return nextId++;
}
