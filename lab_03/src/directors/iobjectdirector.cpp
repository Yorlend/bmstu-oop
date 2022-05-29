#include <stdexcept>
#include "iobjectdirector.hpp"

void IObjectDirector::setReader(IReader &newReader)
{
    reader = &newReader;
}

void IObjectDirector::setBuilder(BaseObjectBuilder &newBuilder)
{
    builder = &newBuilder;
}

IReader &IObjectDirector::getReader()
{
    if (reader == nullptr)
        throw std::runtime_error("reader not set");

    return *reader;
}

BaseObjectBuilder &IObjectDirector::getBuilder()
{
    if (builder == nullptr)
        throw std::runtime_error("builder not set");

    return *builder;
}