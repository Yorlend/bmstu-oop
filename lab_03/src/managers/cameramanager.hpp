#pragma once

#include <memory>
#include "basemanager.hpp"
#include "datarepository.hpp"

class Solution;

class CameraManager : public BaseManager
{
public:
    CameraManager(Solution &solution);

    void switchNextCamera();

private:
    std::shared_ptr<DataRepository> dataRepository;
};
