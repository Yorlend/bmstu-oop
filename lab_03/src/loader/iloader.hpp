#pragma once

#include <string>
#include "math/vector.hpp"

class ILoader
{
public:
    virtual ~ILoader() = default;

    virtual size_t loadSize() = 0;
    virtual Vector loadVector() = 0;
    virtual std::string loadString() = 0;
};
