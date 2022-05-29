#pragma once

#include <memory>
#include "entities/baseobject.hpp"
#include "io/ireader.hpp"
#include "builder/basebuilder.hpp"

class IObjectDirector
{
public:
    virtual ~IObjectDirector() = default;

    void setReader(IReader &newReader);
    void setBuilder(BaseObjectBuilder &builder);

    virtual std::unique_ptr<BaseObject> construct() = 0;

protected:
    IReader &getReader();
    BaseObjectBuilder &getBuilder();

private:
    IReader *reader = nullptr;
    BaseObjectBuilder *builder = nullptr;
};
