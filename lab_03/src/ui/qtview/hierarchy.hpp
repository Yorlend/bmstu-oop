#pragma once

#include <QObject>
#include "view/ihierarchy.hpp"

class QtHierarchyView : public QObject, public IHierarchyView
{
    Q_OBJECT

public:
    virtual void showHierarchy(const std::list<std::string>& objectNames) override;

signals:
    void showHierarchySignal(const std::list<std::string>& objectNames);
};
