
#include <QDebug>
#include <QPainter>
#include "MainWindow.hpp"
#include "Canvas.hpp"
#include "ui_main_window.h"
#include "core/operation_manager.hpp"
#include "core/utils/error_codes.hpp"


MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent), ui(new Ui::main_window), proj({}), canvas(new Canvas())
{
    ui->setupUi(this);

    ui->canvas->parentWidget()->layout()->replaceWidget(ui->canvas, canvas);
    canvas->setMinimumSize(QSize(600, 600));

    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::load);
    connect(ui->moveButton, &QPushButton::clicked, this, &MainWindow::move);
    connect(ui->rotateButton, &QPushButton::clicked, this, &MainWindow::rotate);
    connect(ui->scaleButton, &QPushButton::clicked, this, &MainWindow::resize);
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

    if (status == NO_ERRORS)
    {
        int width = canvas->width();
        int height = canvas->height();
        QPainter painter(&canvas->getRenderBuffer());

        painter.fillRect(0, 0, width, height, QColor(255, 255, 255));

        for (size_t i = 0; i < proj.size; i++)
        {
            int x1 = proj.data[i].start.x;
            int y1 = proj.data[i].start.y;
            int x2 = proj.data[i].end.x;
            int y2 = proj.data[i].end.y;

            painter.drawLine(x1 + width / 2, y1 + height / 2, x2 + width / 2, y2 + height / 2);
        }

        canvas->repaint();
    }

    qDebug() << "render status: " << status;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    render();
}

void MainWindow::move()
{
    move_params moving{};
    moving.dx = ui->dxSpinBox->value();
    moving.dy = ui->dySpinBox->value();
    moving.dz = ui->dzSpinBox->value();

    op_params params{ .op = MOVE, .moving = moving};

    int status = perform_operation(params);
    render();

    qDebug() << "move status: " << status;
}

void MainWindow::rotate()
{
    rotate_params rotating{};
    rotating.cx = ui->cxSpinBox->value();
    rotating.cy = ui->cySpinBox->value();
    rotating.cz = ui->czSpinBox->value();
    rotating.ax = ui->axSpinBox->value();
    rotating.ay = ui->aySpinBox->value();
    rotating.az = ui->azSpinBox->value();

    op_params params{ .op = ROTATE, .rotating = rotating };

    int status = perform_operation(params);
    render();

    qDebug() << "rotate status: " << status;
}

void MainWindow::resize()
{
    resize_params resizing{};
    resizing.cx = ui->cxSpinBox->value();
    resizing.cy = ui->cySpinBox->value();
    resizing.cz = ui->czSpinBox->value();
    resizing.kx = ui->kxSpinBox->value();
    resizing.ky = ui->kySpinBox->value();
    resizing.kz = ui->kzSpinBox->value();

    op_params params{ .op = RESIZE, .resizing = resizing };

    int status = perform_operation(params);
    render();

    qDebug() << "resize status: " << status;
}
