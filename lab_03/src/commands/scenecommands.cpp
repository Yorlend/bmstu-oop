#include "managers/managerprovider.hpp"
#include "managers/scenemanager.hpp"
#include "scenecommands.hpp"

void CreateNewSceneCommand::execute(ManagerProvider &managerProvider)
{
    managerProvider.get<SceneManager>().createNewScene();
}

// ImportSceneCommand::ImportSceneCommand(const std::string &filename)
//     : filename(filename)
// {
// }

// void ImportSceneCommand::execute(ManagerProvider &managerProvider)
// {
//     managerProvider.get<SceneManager>().importScene(filename);
// }
