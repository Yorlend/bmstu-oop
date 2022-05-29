#pragma once

#include <memory>
#include <QGraphicsScene>
#include <QMainWindow>
#include "ui_main_window.h"
#include "commands/facade.hpp"

class Solution;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Solution& solution);
    ~MainWindow();

private:
    Ui::MainWindow* ui;

    std::shared_ptr<Facade> facade;
    std::shared_ptr<QGraphicsScene> graphicsScene;
};
