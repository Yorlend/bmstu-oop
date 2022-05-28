#pragma once

#include <QWidget>
#include "ui_hierarchy_widget.h"

class HierarchyWidget : public QWidget
{
    Q_OBJECT

public:
    HierarchyWidget(QWidget* parent = Q_NULLPTR);
    ~HierarchyWidget();

private:
    Ui::HierarchyWidget* ui;
};
