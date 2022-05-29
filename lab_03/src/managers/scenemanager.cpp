#include "scenemanager.hpp"
#include "solution/solution.hpp"
#include "solution/configuration.hpp"
#include "directors/cameradirector.hpp"
#include "builder/camerabuilder.hpp"

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
