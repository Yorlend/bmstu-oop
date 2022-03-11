#include <QDebug>
#include <QPainter>
#include <QPaintEvent>
#include "Canvas.hpp"

Canvas::Canvas(QWidget *parent) :
    QWidget(parent)
{}

QImage &Canvas::getRenderBuffer() {
    return buffer;
}

void Canvas::paintEvent(QPaintEvent *event) {
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.drawImage(0, 0, buffer);

    // qDebug() << "canvas painted!";
}

void Canvas::resizeEvent(QResizeEvent *event) {
    QWidget::resizeEvent(event);

    if (buffer.isNull())
        buffer = QImage(event->size(), QImage::Format_ARGB32);
    else
        buffer = buffer.scaled(event->size());

    // qDebug() << "canvas resized!";
}
