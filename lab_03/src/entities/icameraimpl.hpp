#pragma once

#include "math/vector.hpp"

class ICameraImpl
{
public:
    virtual ~ICameraImpl() = default;

    virtual void setViewport(double width, double height) = 0;
    virtual Vector project(const Vector& point) = 0;
};
