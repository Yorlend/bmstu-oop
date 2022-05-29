#include "cameramanager.hpp"
#include "solution/solution.hpp"
#include "solution/configuration.hpp"

CameraManager::CameraManager(Solution &solution)
    : dataRepository(solution.getDataRepository(DEFAULT_DATA_REPOSITORY))
{
}

void CameraManager::switchNextCamera()
{
    auto &scene = dataRepository->getScene();
    auto camera = dataRepository->getActiveCamera();

    if (camera == nullptr)
    {
        
    }
}

void CameraManager::switchPrevCamera()
{
}
