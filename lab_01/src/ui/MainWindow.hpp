
#ifndef LAB_01_MAIN_WINDOW_HPP
#define LAB_01_MAIN_WINDOW_HPP

#include <QMainWindow>
#include "core/utils/projection/projection.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

public slots:
    void load();
    void render();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::main_window *ui;
    projection proj;
};


#endif //LAB_01_MAIN_WINDOW_HPP
