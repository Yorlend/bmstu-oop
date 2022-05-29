#pragma once

#include <memory>
#include "managerprovider.hpp"

class Solution;

class ManagerCreator
{
public:
    virtual std::unique_ptr<ManagerProvider> createProvider(Solution& solution);
};
