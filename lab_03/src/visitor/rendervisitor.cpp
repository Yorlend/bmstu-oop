#include "rendervisitor.hpp"
#include "entities/objectgroup.hpp"
#include "entities/model.hpp"

RenderVisitor::RenderVisitor(IRenderer &renderer)
    : renderer(renderer)
{
}

void RenderVisitor::visit(Camera &camera)
{
}

void RenderVisitor::visit(Model &model)
{
    auto &details = model.getDetails();

    auto points = details.getPoints();
    auto edges = details.getEdges();

    for (auto edge : edges)
    {
        auto p1 = points[edge.getStart()];
        auto p2 = points[edge.getEnd()];

        ///TODO: camera here

        renderer.renderLine(p1, p2);
    }
}

void RenderVisitor::visit(ObjectGroup &group)
{
    for (auto obj : group)
        obj->accept(*this);
}
