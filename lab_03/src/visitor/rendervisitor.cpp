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
    if (!model.getVisibility())
        return;

    
    auto &details = model.getDetails();

    auto points = details.getPoints();
    auto edges = details.getEdges();

    auto view = camera.getMatrix().inverse();
    auto mvp = view * model.getMatrix();

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
