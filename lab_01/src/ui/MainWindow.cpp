
#include <QDebug>
#include <QPainter>
#include "MainWindow.hpp"
#include "ui_main_window.h"
#include "core/operation_manager.hpp"
#include "core/utils/error_codes.hpp"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::main_window), proj({})
{
    ui->setupUi(this);

    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::load);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::load()
{
    const char* filename = "../models/cube.txt";

    op_params params = {LOAD, {filename}};
    int status = perform_operation(params);

    qDebug() << "load status: " << status;

    render();
}

void MainWindow::render()
{
    op_params params{.op = RENDER, .rendering = (render_params) {proj}};
    int status = perform_operation(params);
    repaint();

    qDebug() << "render status: " << status;
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);

    QPainter painter(this);

    for (size_t i = 0; i < proj.size; i++)
    {
        int x1 = proj.data[i].start.x;
        int y1 = proj.data[i].start.y;
        int x2 = proj.data[i].end.x;
        int y2 = proj.data[i].end.y;

        painter.drawLine(x1 + width() / 2, y1 + height() / 2, x2 + width() / 2, y2 + height() / 2);
    }
}

