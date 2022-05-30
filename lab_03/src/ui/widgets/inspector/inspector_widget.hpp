#pragma once

#include <QWidget>
#include <memory>
#include <list>
#include "commands/facade.hpp"
#include "ui_inspector_widget.h"

class InspectorWidget : public QWidget
{
    Q_OBJECT

public:
    InspectorWidget(QWidget *parent = Q_NULLPTR);
    ~InspectorWidget();

    void setFacade(std::shared_ptr<Facade> newFacade);

public slots:
    void showInfoAbout(const std::list<size_t> &objIds);

private:
    Ui::InspectorWidget *ui;
    std::shared_ptr<Facade> facade;
};
