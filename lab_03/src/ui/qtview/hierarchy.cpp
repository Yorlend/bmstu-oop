#include "hierarchy.hpp"

void QtHierarchyView::showHierarchy(const std::list<std::string> &objectNames)
{
    emit showHierarchySignal(objectNames);
}
