#pragma once

#include <memory>
#include <string>
#include "math/vector.hpp"
#include "math/edge.hpp"
#include "math/transform.hpp"
#include "entities/baseobject.hpp"

class BaseObjectBuilder
{
public:
    virtual ~BaseObjectBuilder() = default;

    void setId(size_t newId);
    void setName(const std::string &newName);

    void setPosition(const Vector &newPosition);
    void setRotation(const Vector &newRotation);
    void setScale(const Vector &newScale);

    virtual void addPoint(const Vector &point) = 0;
    virtual void addEdge(const Edge &edge) = 0;

    virtual std::unique_ptr<BaseObject> build() = 0;

protected:
    size_t getId();
    const std::string &getName();

    Transform buildTransform();

private:
    size_t id;
    std::string name;

    Vector position;
    Vector rotation;
    Vector scale;
};
