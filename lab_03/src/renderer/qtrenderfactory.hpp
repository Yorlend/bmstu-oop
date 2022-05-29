#pragma once

#include <QGraphicsScene>
#include "irenderfactory.hpp"

class QtRenderFactory : public IRenderFactory
{
public:
    QtRenderFactory(QGraphicsScene &scene);

    virtual std::unique_ptr<IRenderer> createRenderer() override;

private:
    QGraphicsScene &scene;
};
