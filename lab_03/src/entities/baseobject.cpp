#include "baseobject.hpp"

BaseObject::BaseObject(size_t id, const std::string &name, const Matrix &matrix)
    : id(id), name(name), matrix(matrix), visible(true)
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

const Matrix &BaseObject::getMatrix() const
{
    return matrix;
}

void BaseObject::setMatrix(const Matrix &newTransform)
{
    matrix = newTransform;
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
