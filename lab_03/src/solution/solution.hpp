#pragma once

#include <map>
#include "directors/iobjectdirector.hpp"
#include "managers/datarepository.hpp"
#include "renderer/irenderfactory.hpp"

class Solution
{
public:
    template <typename T>
    using MapType = std::map<size_t, std::shared_ptr<T>>;

    virtual void registerObjectDirector(size_t id, std::shared_ptr<IObjectDirector> director);
    virtual void registerRenderFactory(size_t id, std::shared_ptr<IRenderFactory> factory);
    virtual void registerDataRepository(size_t id, std::shared_ptr<DataRepository> repository);

    virtual std::shared_ptr<IObjectDirector> getObjectDirector(size_t id);
    virtual std::shared_ptr<IRenderFactory> getRenderFactory(size_t id);
    virtual std::shared_ptr<DataRepository> getDataRepository(size_t id);

private:
    MapType<IObjectDirector> objectDirectors;
    MapType<IRenderFactory> renderFactories;
    MapType<DataRepository> dataRepositories;
};
