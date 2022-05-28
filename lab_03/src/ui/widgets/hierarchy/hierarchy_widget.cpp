#include "hierarchy_widget.hpp"

HierarchyWidget::HierarchyWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::HierarchyWidget)
{
    ui->setupUi(this);
}

HierarchyWidget::~HierarchyWidget()
{
    delete ui;
}
