#include "Wireframe.hpp"

Wireframe::Wireframe(std::vector<Vector> verts, std::vector<Edge> edges)
    : vertices(verts), edges(edges) {}

Wireframe::Wireframe(Wireframe&& wireframe) noexcept
    : vertices(std::move(wireframe.vertices)), edges(std::move(wireframe.edges)) {}


const std::vector<Vector>& Wireframe::getVertices() const
{
    return vertices;
}

const std::vector<Edge>& Wireframe::getEdges() const
{
    return edges;
}
