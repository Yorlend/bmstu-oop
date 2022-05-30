#include <stdexcept>
#include "camerabuilder.hpp"
#include "entities/camera.hpp"
#include "entities/orthocamimpl.hpp"

void CameraBuilder::addPoint(const Vector &point)
{
    throw std::runtime_error("wrong instance of builder");
}

void CameraBuilder::addEdge(const Edge &edge)
{
    throw std::runtime_error("wrong instance of builder");
}

std::unique_ptr<BaseObject> CameraBuilder::build()
{
    auto id = getId();
    auto name = getName();
    auto matrix = buildTransform();

    auto details = std::shared_ptr<ICameraImpl>(new OrthoCameraImpl());
    return std::unique_ptr<BaseObject>(new Camera(details, id, name, matrix));
}
