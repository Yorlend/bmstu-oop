#pragma once

#include "ivisitor.hpp"

class TransformVisitor : public IVisitor
{
public:
    TransformVisitor() = default;

    virtual void visit(Camera &camera) override;
    virtual void visit(Model &model) override;
    virtual void visit(ObjectGroup &group) override;
};
