#pragma once

#include <vector>
#include "basebuilder.hpp"

class ModelBuidler : public BaseObjectBuilder
{
public:
    ModelBuidler() = default;

    virtual void addPoint(const Vector &point) override;
    virtual void addEdge(const Edge &edge) override;

    virtual std::unique_ptr<BaseObject> build() override;

private:
    std::vector<Vector> points;
    std::vector<Edge> edges;
};
