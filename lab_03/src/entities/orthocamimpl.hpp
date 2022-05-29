#pragma once

#include "icameraimpl.hpp"

class OrthoCameraImpl : public ICameraImpl
{
public:
    virtual void setViewport(double width, double height) override;

    virtual Vector project(const Vector& point) override;
};
