#include "scene.hpp"
#include "entities/objectgroup.hpp"

Scene::Scene()
    : objects(new ObjectGroup(0, "Scene container"))
{
}

BaseObject::Iterator Scene::findObjectById(size_t id)
{
    auto iter = begin();

    while (iter != end() && (*iter)->getId() != id)
        iter++;

    return iter;
}

void Scene::insertObject(Iterator pos, std::shared_ptr<BaseObject> object)
{
    objects->insertChild(pos, object);
}

void Scene::removeObject(Iterator pos)
{
    objects->removeChild(pos);
}

void Scene::accept(IVisitor &visitor)
{
    objects->accept(visitor);
}

BaseObject::Iterator Scene::begin()
{
    return objects->begin();
}

BaseObject::Iterator Scene::end()
{
    return objects->end();
}

BaseObject::ConstIterator Scene::begin() const
{
    return objects->begin();
}

BaseObject::ConstIterator Scene::end() const
{
    return objects->end();
}
