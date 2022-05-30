#include "rendervisitor.hpp"
#include "entities/objectgroup.hpp"
#include "entities/model.hpp"
#include "entities/camera.hpp"

RenderVisitor::RenderVisitor(IRenderer &renderer, Camera& camera)
    : renderer(renderer), camera(camera)
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

    auto view = camera.getTransform().toMatrix().inverse();
    auto mvp = view * model.getTransform().toMatrix();

    for (auto edge : edges)
    {
        auto p1 = mvp * points[edge.getStart()];
        auto p2 = mvp * points[edge.getEnd()];

        renderer.renderLine(p1, p2);
    }
}

void RenderVisitor::visit(ObjectGroup &group)
{
    for (auto obj : group)
        obj->accept(*this);
}
