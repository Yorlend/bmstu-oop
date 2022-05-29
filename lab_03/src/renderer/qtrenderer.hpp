#pragma once

#include <QGraphicsScene>
#include "irenderer.hpp"

class QtRenderer : public IRenderer
{
public:
    QtRenderer(QGraphicsScene &scene);

    virtual void clear() override;
    virtual void renderLine(const Vector &p1, const Vector &p2) override;

private:
    QGraphicsScene &scene;
};
