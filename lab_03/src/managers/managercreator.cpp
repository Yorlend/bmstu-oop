#include "managercreator.hpp"
#include "scenemanager.hpp"
#include "rendermanager.hpp"
#include "objectmanager.hpp"
#include "cameramanager.hpp"
#include "solution/solution.hpp"

std::unique_ptr<ManagerProvider> ManagerCreator::createProvider(Solution &solution)
{
    auto provider = std::make_unique<ManagerProvider>();

    provider->registerManager<SceneManager>(solution);
    provider->registerManager<CameraManager>(solution);
    provider->registerManager<ObjectManager>(solution);
    provider->registerManager<RenderManager>(solution);

    return provider;
}
