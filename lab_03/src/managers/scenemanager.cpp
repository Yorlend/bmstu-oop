#include "scenemanager.hpp"
#include "solution/solution.hpp"
#include "solution/configuration.hpp"
#include "directors/cameradirector.hpp"
#include "builder/camerabuilder.hpp"
#include "entities/objectgroup.hpp"

SceneManager::SceneManager(Solution &solution)
    : dataRepository(solution.getDataRepository(DEFAULT_DATA_REPOSITORY)),
      defaultCameraDirector(solution.getObjectDirector(DEFAULT_CAMERA_DIRECTOR))
{
}

void SceneManager::createNewScene()
{
    Scene scene;

    CameraBuilder builder;
    defaultCameraDirector->setBuilder(builder);
    std::shared_ptr<BaseObject> camera = defaultCameraDirector->construct();

    scene.insertObject(scene.end(), camera);

    dataRepository->setActiveCamera(camera);
    dataRepository->setScene(std::move(scene));
}

void SceneManager::getHierarchy(std::function<void(const Scene&)> callback)
{
    callback(dataRepository->getScene());
}

void SceneManager::getInfoAbout(const std::list<size_t>& ids, std::function<void(std::shared_ptr<BaseObject>)> callback)
{
    auto& scene = dataRepository->getScene();

    if (ids.size() == 1)
    {
        auto object = *scene.findObjectById(ids.front());
        callback(object);
    }
    else if (ids.size() > 0)
    {
        auto group = std::shared_ptr<BaseObject>(new ObjectGroup(0, "group"));
        for (auto id : ids)
            group->insertChild(group->end(), *scene.findObjectById(id));

        callback(group);
    }
}
