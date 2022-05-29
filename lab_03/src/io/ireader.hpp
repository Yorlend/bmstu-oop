#pragma once

#include <string>
#include "math/vector.hpp"
#include "math/edge.hpp"

class IReader
{
public:
    virtual ~IReader() = default;

    virtual size_t readCount() = 0;
    virtual std::string readString() = 0;
    virtual Vector readVector() = 0;
    virtual Edge readEdge() = 0;
    virtual double readDouble() = 0;
    virtual bool readBool() = 0;
};
