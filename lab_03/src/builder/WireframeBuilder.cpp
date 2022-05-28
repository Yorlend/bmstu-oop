#include "WireframeBuilder.hpp"
#include "object/Wireframe.hpp"
// #include "object/Adapter.hpp"

void WireframeBuilder::buildVerts(const Vector& vert)
{
    vertices.push_back(vert);
}

void WireframeBuilder::buildEdges(const Edge& edge)
{
    edges.push_back(edge);
}

std::shared_ptr<BaseObject> WireframeBuilder::assemble() const
{
    return nullptr;
    // return std::make_shared<Adapter<Wireframe>>(Wireframe(vertices, edges));
}
