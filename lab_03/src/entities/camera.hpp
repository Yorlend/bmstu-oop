#pragma once

#include <memory>
#include "icameraimpl.hpp"
#include "baseobject.hpp"

class Camera : public BaseObject
{
public:
    Camera(std::shared_ptr<ICameraImpl> cameraImpl, size_t id, const std::string &name = "Camera", const Matrix &matrix = Matrix::identity());

    virtual void accept(IVisitor &visitor) override;

private:
    ICameraImpl &getDetails();

    std::shared_ptr<ICameraImpl> cameraImpl;
};
