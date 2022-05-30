#pragma once

#include "ivisitor.hpp"
#include "math/matrix.hpp"

class BaseObject;

class TransformVisitor : public IVisitor
{
public:
    TransformVisitor() = default;
    TransformVisitor(size_t id, const Matrix& matrix);

    virtual void visit(Camera &camera) override;
    virtual void visit(Model &model) override;
    virtual void visit(ObjectGroup &group) override;

private:
    void applyTransform(BaseObject& obj);

    size_t id;
    Matrix matrix;
};
