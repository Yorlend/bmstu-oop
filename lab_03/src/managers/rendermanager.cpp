#include "rendermanager.hpp"
#include "solution/solution.hpp"
#include "solution/configuration.hpp"
#include "visitor/rendervisitor.hpp"

RenderManager::RenderManager(Solution &solution)
    : dataRepository(solution.getDataRepository(DEFAULT_DATA_REPOSITORY)),
      renderFactory(solution.getRenderFactory(QT_RENDER_FACTORY))
{
}

void RenderManager::renderScene()
{
    auto &scene = dataRepository->getScene();
    auto camera = dataRepository->getActiveCamera();

    auto renderer = renderFactory->createRenderer();
    auto visitor = RenderVisitor(*renderer);

    renderer->clear();
    scene.accept(visitor);
}
