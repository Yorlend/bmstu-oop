#pragma once

#include <QMainWindow>
#include "ui_main_window.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    Ui::MainWindow* ui;
};
