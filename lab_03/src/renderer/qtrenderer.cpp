#include "qtrenderer.hpp"

QtRenderer::QtRenderer(QGraphicsScene &scene)
    : scene(scene)
{
}

void QtRenderer::clear()
{
    scene.clear();
}

void QtRenderer::renderLine(const Vector &p1, const Vector &p2)
{
    scene.addLine(p1.getX(), p1.getY(), p2.getX(), p2.getY());
}
