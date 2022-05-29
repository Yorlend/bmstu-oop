#pragma once

#include <vector>
#include "math/vector.hpp"
#include "math/edge.hpp"

class IModelImpl
{
public:
    virtual ~IModelImpl() = default;

    virtual std::vector<Vector> getPoints() = 0;
    virtual std::vector<Edge> getEdges() = 0;
};
