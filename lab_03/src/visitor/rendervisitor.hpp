#pragma once

#include "renderer/irenderer.hpp"
#include "ivisitor.hpp"

class RenderVisitor : public IVisitor
{
public:
    RenderVisitor(IRenderer& renderer);

    virtual void visit(Camera &camera) override;
    virtual void visit(Model &model) override;
    virtual void visit(ObjectGroup &group) override;

private:
    IRenderer& renderer;
};
