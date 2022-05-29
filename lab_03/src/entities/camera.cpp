#include "camera.hpp"
#include "visitor/ivisitor.hpp"

Camera::Camera(std::shared_ptr<ICameraImpl> cameraImpl, size_t id, const std::string &name, const Transform &transform)
    : BaseObject(id, name, transform), cameraImpl(std::move(cameraImpl))
{
}

void Camera::accept(IVisitor &visitor)
{
    visitor.visit(*this);
}

ICameraImpl &Camera::getDetails()
{
    return *cameraImpl.get();
}
