#include "cameradirector.hpp"
#include "tools/idgenerator.hpp"

std::unique_ptr<BaseObject> CameraDirector::construct()
{
    auto &reader = getReader();
    auto &builder = getBuilder();

    builder.setId(IdGenerator::generateId());
    builder.setName(reader.readString());

    builder.setPosition(reader.readVector());
    builder.setRotation(reader.readVector());
    builder.setScale(reader.readVector());

    return builder.build();
}
