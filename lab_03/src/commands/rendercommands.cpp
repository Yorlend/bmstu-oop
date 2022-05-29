#include "managers/managerprovider.hpp"
#include "managers/rendermanager.hpp"
#include "rendercommands.hpp"

void RenderSceneCommand::execute(ManagerProvider &managerProvider)
{
    managerProvider.get<RenderManager>().renderScene();
}
