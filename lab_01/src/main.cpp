#include <QApplication>
#include "ui/MainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.setWindowTitle("Carcass model viewer");
    mainWindow.show();
    return QApplication::exec();
}
