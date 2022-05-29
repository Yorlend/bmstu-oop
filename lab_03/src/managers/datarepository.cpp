#include "datarepository.hpp"

Scene &DataRepository::getScene()
{
    return scene;
}

void DataRepository::setScene(Scene &&newScene)
{
    scene = std::move(newScene);
}

std::shared_ptr<BaseObject> DataRepository::getActiveCamera()
{
    return camera;
}

void DataRepository::setActiveCamera(std::shared_ptr<BaseObject> newCamera)
{
    camera = newCamera;
}
