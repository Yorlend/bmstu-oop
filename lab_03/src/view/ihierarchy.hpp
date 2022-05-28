#pragma once

#include <string>
#include <list>

class IHierarchyView
{
public:
    virtual ~IHierarchyView() = default;

    virtual void showHierarchy(const std::list<std::string>& objectNames) = 0;
};

