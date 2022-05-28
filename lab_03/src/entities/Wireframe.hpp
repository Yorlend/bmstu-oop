#pragma once

#include <vector>
#include "Vector.hpp"
#include "Edge.hpp"

class Wireframe
{
public:
    Wireframe(std::vector<Vector> verts, std::vector<Edge> edges);
    Wireframe(Wireframe&& wireframe) noexcept;

    const std::vector<Vector>& getVertices() const;
    const std::vector<Edge>& getEdges() const;

private:
    std::vector<Vector> vertices;
    std::vector<Edge> edges;
};
