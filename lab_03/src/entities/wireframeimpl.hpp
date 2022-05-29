#pragma once

#include "imodelimpl.hpp"

class WireframeImpl : public IModelImpl
{
public:
    WireframeImpl(const std::vector<Vector> &points, const std::vector<Edge> &edges)
        : points(points), edges(edges) {}

    virtual std::vector<Vector> getPoints() override { return points; }
    virtual std::vector<Edge> getEdges() override { return edges; }

private:
    std::vector<Vector> points;
    std::vector<Edge> edges;
};
