#include "viewport_widget.hpp"

ViewportWidget::ViewportWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::ViewportWidget)
{
    ui->setupUi(this);
}

ViewportWidget::~ViewportWidget()
{
    delete ui;
}
