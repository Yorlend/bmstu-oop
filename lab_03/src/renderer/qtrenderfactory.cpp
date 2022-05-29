#include "qtrenderfactory.hpp"
#include "qtrenderer.hpp"

QtRenderFactory::QtRenderFactory(QGraphicsScene &scene)
    : scene(scene)
{
}

std::unique_ptr<IRenderer> QtRenderFactory::createRenderer()
{
    return std::unique_ptr<IRenderer>(new QtRenderer(scene));
}
