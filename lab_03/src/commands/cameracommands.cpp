#include "managers/managerprovider.hpp"
#include "managers/cameramanager.hpp"
#include "cameracommands.hpp"

void SwitchNextCameraCommand::execute(ManagerProvider &managerProvider)
{
    managerProvider.get<CameraManager>().switchNextCamera();
}
