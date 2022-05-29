#pragma once

#include <cstddef>

class IdGenerator
{
public:
    static size_t generateId();

private:
    static size_t nextId;
};
