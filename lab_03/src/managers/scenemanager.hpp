#pragma once

#include <memory>
#include <string>
#include <functional>
#include "basemanager.hpp"
#include "datarepository.hpp"
#include "directors/iobjectdirector.hpp"

class Solution;

class SceneManager : public BaseManager
{
public:
    SceneManager(Solution& solution);

    void createNewScene();

    void addCamera(const Vector &position, const Vector &eye);

    void getHierarchy(std::function<void(const Scene&)> callback);

    void getInfoAbout(const std::list<size_t>& ids, std::function<void(std::shared_ptr<BaseObject>)> callback);

private:
    std::shared_ptr<DataRepository> dataRepository;
    std::shared_ptr<IObjectDirector> defaultCameraDirector;
};
