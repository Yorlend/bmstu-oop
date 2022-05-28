#pragma once

#include <QWidget>
#include "ui_viewport_widget.h"

class ViewportWidget : public QWidget
{
    Q_OBJECT

public:
    ViewportWidget(QWidget *parent = Q_NULLPTR);
    ~ViewportWidget();

private:
    Ui::ViewportWidget *ui;
};
