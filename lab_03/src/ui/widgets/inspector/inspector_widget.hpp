#pragma once

#include <QWidget>
#include "ui_inspector_widget.h"

class InspectorWidget : public QWidget
{
    Q_OBJECT

public:
    InspectorWidget(QWidget *parent = Q_NULLPTR);
    ~InspectorWidget();

private:
    Ui::InspectorWidget *ui;
};
