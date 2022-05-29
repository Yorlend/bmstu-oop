#include "baseobject.hpp"

BaseObject::BaseObject(size_t id, const std::string &name, const Transform &transform)
    : id(id), name(name), transform(transform), visible(true)
{
}

size_t BaseObject::getId() const
{
    return id;
}

const std::string &BaseObject::getName() const
{
    return name;
}

void BaseObject::setName(const std::string &newName)
{
    name = newName;
}

const Transform &BaseObject::getTransform() const
{
    return transform;
}

void BaseObject::setTransform(const Transform &newTransform)
{
    transform = newTransform;
}

bool BaseObject::getVisibility() const
{
    return visible;
}

void BaseObject::setVisibility(bool visibility)
{
    visible = visibility;
}

bool BaseObject::isComposite() const
{
    return false;
}

bool BaseObject::insertChild(Iterator pos, std::shared_ptr<BaseObject> obj)
{
    return false;
}

bool BaseObject::removeChild(Iterator pos)
{
    return false;
}

BaseObject::Iterator BaseObject::begin()
{
    return Iterator();
}

BaseObject::Iterator BaseObject::end()
{
    return Iterator();
}
