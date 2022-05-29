#include "managers/managerprovider.hpp"
#include "managers/objectmanager.hpp"
#include "objectcommands.hpp"

ImportObjectCommand::ImportObjectCommand(const std::string &filename)
    : filename(filename)
{
}

void ImportObjectCommand::execute(ManagerProvider &managerProvider)
{
    managerProvider.get<ObjectManager>().importObject(filename);
}

RemoveObjectCommand::RemoveObjectCommand(size_t objectId)
    : objectId(objectId)
{
}

void RemoveObjectCommand::execute(ManagerProvider &managerProvider)
{
    managerProvider.get<ObjectManager>().removeObject(objectId);
}

TransformObjectCommand::TransformObjectCommand(size_t objectId, const Transform &transform)
    : objectId(objectId), transform(transform)
{
}

void TransformObjectCommand::execute(ManagerProvider &managerProvider)
{
    managerProvider.get<ObjectManager>().transformObject(objectId, transform);
}
