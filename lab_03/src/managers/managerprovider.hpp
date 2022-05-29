#pragma once

#include <map>
#include "basemanager.hpp"

class ManagerProvider
{
public:
    template <typename Manager>
    Manager &get();

    template <typename Manager, typename... Args>
    void registerManager(Args &&...args);

private:
    std::map<size_t, std::shared_ptr<BaseManager>> managerMap;
};

template <typename Manager>
Manager &ManagerProvider::get()
{
    auto key = typeid(Manager).hash_code();
    return *dynamic_cast<Manager *>(managerMap.at(key).get());
}

template <typename Manager, typename... Args>
void ManagerProvider::registerManager(Args &&...args)
{
    auto key = typeid(Manager).hash_code();
    auto value = std::shared_ptr<BaseManager>(new Manager(args...));

    managerMap.emplace(key, value);
}
