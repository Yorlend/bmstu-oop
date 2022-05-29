#include "solution.hpp"

void Solution::registerObjectDirector(size_t id, std::shared_ptr<IObjectDirector> director)
{
    objectDirectors.emplace(id, director);
}

void Solution::registerRenderFactory(size_t id, std::shared_ptr<IRenderFactory> factory)
{
    renderFactories.emplace(id, factory);
}

void Solution::registerDataRepository(size_t id, std::shared_ptr<DataRepository> repository)
{
    dataRepositories.emplace(id, repository);
}

std::shared_ptr<IObjectDirector> Solution::getObjectDirector(size_t id)
{
    return objectDirectors[id];
}

std::shared_ptr<IRenderFactory> Solution::getRenderFactory(size_t id)
{
    return renderFactories[id];
}

std::shared_ptr<DataRepository> Solution::getDataRepository(size_t id)
{
    return dataRepositories[id];
}
