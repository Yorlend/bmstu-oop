#include "modeldirector.hpp"
#include "tools/idgenerator.hpp"

std::unique_ptr<BaseObject> ModelDirector::construct()
{
    auto &reader = getReader();
    auto &builder = getBuilder();

    builder.setId(IdGenerator::generateId());
    builder.setName(reader.readString());

    builder.setPosition(reader.readVector());
    builder.setRotation(reader.readVector());
    builder.setScale(reader.readVector());

    size_t pointsCount = reader.readCount();
    for (size_t i = 0; i < pointsCount; i++)
        builder.addPoint(reader.readVector());

    size_t edgesCount = reader.readCount();
    for (size_t i = 0; i < edgesCount; i++)
        builder.addEdge(reader.readEdge());

    return builder.build();
}
