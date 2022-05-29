#pragma once

#include <memory>
#include "basemanager.hpp"
#include "datarepository.hpp"
#include "renderer/irenderfactory.hpp"

class Solution;

class RenderManager : public BaseManager
{
public:
    RenderManager(Solution& solution);

    void renderScene();

private:
    std::shared_ptr<DataRepository> dataRepository;
    std::shared_ptr<IRenderFactory> renderFactory;
};
