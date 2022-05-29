#pragma once

class Camera;
class Model;
class ObjectGroup;

class IVisitor
{
public:
    virtual ~IVisitor() = default;

    virtual void visit(Camera &camera) = 0;
    virtual void visit(Model &model) = 0;
    virtual void visit(ObjectGroup &group) = 0;
};
