#pragma once

#include <vector>
#include "object/Vector.hpp"
#include "object/Edge.hpp"

class BaseObjectBuilder
{
public:

    virtual void buildVerts(const Vector& vert) = 0;
    virtual void buildEdges(const Edge& edge) = 0;
};
