
#ifndef LAB_01_MAIN_WINDOW_HPP
#define LAB_01_MAIN_WINDOW_HPP

#include <QMainWindow>
#include "Canvas.hpp"
#include "core/utils/projection/projection.hpp"


QT_BEGIN_NAMESPACE
namespace Ui { class main_window; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

protected:
    void resizeEvent(QResizeEvent* event) override;

public slots:
    void load();
    void render();
    void move();
    void rotate();
    void resize();

private:
    Ui::main_window *ui;
    projection proj;
    Canvas* canvas;
};


#endif //LAB_01_MAIN_WINDOW_HPP
