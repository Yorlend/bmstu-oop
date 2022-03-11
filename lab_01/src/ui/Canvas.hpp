#pragma once

#include <QWidget>

class Canvas : public QWidget
{
public:
    explicit Canvas(QWidget* parent = nullptr);

    QImage& getRenderBuffer();

protected:
    void paintEvent(QPaintEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;

private:
    QImage buffer;
};
