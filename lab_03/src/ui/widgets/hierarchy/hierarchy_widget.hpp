#pragma once

#include <QWidget>
#include <memory>
#include "commands/facade.hpp"
#include "ui_hierarchy_widget.h"

class HierarchyWidget : public QWidget
{
    Q_OBJECT

public:
    HierarchyWidget(QWidget* parent = Q_NULLPTR);
    ~HierarchyWidget();

    void setFacade(std::shared_ptr<Facade> newFacade);

    void updateHierarchy();

signals:
    void selectedSignal(const std::list<size_t>& ids);

protected slots:
    void selectionChanged();

private:
    size_t extractId(const QString& string);

    Ui::HierarchyWidget* ui;

    std::shared_ptr<Facade> facade;
};
