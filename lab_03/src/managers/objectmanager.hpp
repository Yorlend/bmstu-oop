#pragma once

#include <memory>
#include "directors/iobjectdirector.hpp"
#include "datarepository.hpp"
#include "basemanager.hpp"

class Solution;

class ObjectManager : public BaseManager
{
public:
    ObjectManager(Solution& solution);

    void importObject(const std::string &filename);
    void removeObject(size_t id);

    void transformObject(size_t id, const Transform &transform);

private:
    std::shared_ptr<DataRepository> dataRepository;
    std::shared_ptr<IObjectDirector> importDirector;
};
