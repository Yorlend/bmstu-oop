#include "basebuilder.hpp"

void BaseObjectBuilder::setId(size_t newId)
{
    id = newId;
}

void BaseObjectBuilder::setName(const std::string &newName)
{
    name = newName;
}

void BaseObjectBuilder::setPosition(const Vector &newPosition)
{
    position = newPosition;
}

void BaseObjectBuilder::setRotation(const Vector &newRotation)
{
    rotation = newRotation;
}

void BaseObjectBuilder::setScale(const Vector &newScale)
{
    scale = newScale;
}

size_t BaseObjectBuilder::getId()
{
    return id;
}

const std::string &BaseObjectBuilder::getName()
{
    return name;
}

Matrix BaseObjectBuilder::buildTransform()
{
    return Matrix::trsModel(position, rotation, scale);
}
