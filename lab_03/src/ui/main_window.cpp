#include "main_window.hpp"
#include "widgets/hierarchy/hierarchy_widget.hpp"
#include "managers/managercreator.hpp"
#include "solution/solution.hpp"
#include "solution/configuration.hpp"
#include "renderer/qtrenderfactory.hpp"

#include "commands/scenecommands.hpp"
#include "commands/rendercommands.hpp"
#include "commands/cameracommands.hpp"
#include "commands/objectcommands.hpp"

MainWindow::MainWindow(Solution &solution)
    : ui(new Ui::MainWindow), graphicsScene(std::make_shared<QGraphicsScene>())
{
    ui->setupUi(this);

    auto factory = std::make_shared<QtRenderFactory>(*graphicsScene);
    solution.registerRenderFactory(QT_RENDER_FACTORY, factory);

    auto provider = ManagerCreator().createProvider(solution);
    facade = std::make_shared<Facade>(std::move(provider));

    ui->viewport->setScene(graphicsScene.get());

    {
        CreateNewSceneCommand cmd;
        facade->execute(cmd);
    }

    {
        ImportObjectCommand cmd("./models/cube.txt");
        facade->execute(cmd);
    }

    {
        RenderSceneCommand cmd;
        facade->execute(cmd);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
