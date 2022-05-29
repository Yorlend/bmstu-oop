#include "defaultcamdirector.hpp"
#include "tools/idgenerator.hpp"

std::unique_ptr<BaseObject> DefaultCameraDirector::construct()
{
    auto &builder = getBuilder();

    builder.setId(IdGenerator::generateId());
    builder.setName("Main Camera");

    builder.setPosition({0, 100, 100});
    builder.setRotation({-30.0 / 180.0 * 3.141592, 0, 0});

    return builder.build();
}
