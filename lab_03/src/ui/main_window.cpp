#include "main_window.hpp"
#include "widgets/hierarchy/hierarchy_widget.hpp"

MainWindow::MainWindow()
    : ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
