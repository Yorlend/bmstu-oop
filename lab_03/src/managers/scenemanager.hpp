#pragma once

#include <memory>
#include <string>
#include "basemanager.hpp"
#include "datarepository.hpp"
#include "directors/iobjectdirector.hpp"

class Solution;

class SceneManager : public BaseManager
{
public:
    SceneManager(Solution& solution);

    void createNewScene();

private:
    std::shared_ptr<DataRepository> dataRepository;
    std::shared_ptr<IObjectDirector> defaultCameraDirector;
};
