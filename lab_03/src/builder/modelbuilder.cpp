#include "modelbuilder.hpp"
#include "entities/model.hpp"
#include "entities/wireframeimpl.hpp"

void ModelBuidler::addPoint(const Vector &point)
{
    points.push_back(point);
}

void ModelBuidler::addEdge(const Edge &edge)
{
    edges.push_back(edge);
}

std::unique_ptr<BaseObject> ModelBuidler::build()
{
    auto id = getId();
    auto name = getName();
    auto matrix = buildTransform();

    auto details = std::shared_ptr<IModelImpl>(new WireframeImpl(points, edges));
    return std::unique_ptr<BaseObject>(new Model(details, id, name, matrix));
}
