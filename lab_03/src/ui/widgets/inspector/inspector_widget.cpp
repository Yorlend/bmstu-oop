#include "inspector_widget.hpp"

InspectorWidget::InspectorWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::InspectorWidget)
{
    ui->setupUi(this);
}

InspectorWidget::~InspectorWidget()
{
    delete ui;
}
