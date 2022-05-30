#include "managers/managerprovider.hpp"
#include "managers/scenemanager.hpp"
#include "scenecommands.hpp"

void CreateNewSceneCommand::execute(ManagerProvider &managerProvider)
{
    managerProvider.get<SceneManager>().createNewScene();
}

GetHierarchyCommand::GetHierarchyCommand(std::function<void(const Scene &)> callback)
    : callback(callback)
{
}

void GetHierarchyCommand::execute(ManagerProvider &managerProvider)
{
    managerProvider.get<SceneManager>().getHierarchy(callback);
}

GetInfoAboutCommand::GetInfoAboutCommand(const std::list<size_t> &ids, std::function<void(std::shared_ptr<BaseObject>)> callback)
    : ids(ids), callback(callback)
{
}

void GetInfoAboutCommand::execute(ManagerProvider &managerProvider)
{
    managerProvider.get<SceneManager>().getInfoAbout(ids, callback);
}
