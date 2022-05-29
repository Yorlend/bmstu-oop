#pragma once

#include "basebuilder.hpp"

class CameraBuilder : public BaseObjectBuilder
{
public:
    virtual void addPoint(const Vector &point) override;
    virtual void addEdge(const Edge &edge) override;

    virtual std::unique_ptr<BaseObject> build() override;
};
