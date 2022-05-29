#pragma once

#include "entities/scene.hpp"

class DataRepository
{
public:
    virtual ~DataRepository() = default;

    virtual Scene &getScene();
    virtual void setScene(Scene &&scene);

    virtual std::shared_ptr<BaseObject> getActiveCamera();
    virtual void setActiveCamera(std::shared_ptr<BaseObject> newCamera);

private:
    Scene scene;
    std::shared_ptr<BaseObject> camera;
};
