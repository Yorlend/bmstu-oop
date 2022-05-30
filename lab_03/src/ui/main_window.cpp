#include <QFileDialog>
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

    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::onLoadAction);
    connect(ui->actionSwitchNext, &QAction::triggered, this, &MainWindow::onSwitchToNextCamera);
    connect(ui->actionAddNewCamera, &QAction::triggered, this, &MainWindow::onAddNewCamera);

    connect(ui->hierarchyWidget, &HierarchyWidget::selectedSignal, ui->inspectorWidget, &InspectorWidget::showInfoAbout);

    auto factory = std::make_shared<QtRenderFactory>(*graphicsScene);
    solution.registerRenderFactory(QT_RENDER_FACTORY, factory);

    auto provider = ManagerCreator().createProvider(solution);
    facade = std::make_shared<Facade>(std::move(provider));

    ui->viewport->setScene(graphicsScene.get());
    ui->hierarchyWidget->setFacade(facade);
    ui->inspectorWidget->setFacade(facade);

    ui->viewport->setSceneRect(QRectF(-450, -450, 900, 900));

    {
        CreateNewSceneCommand cmd;
        facade->execute(cmd);
    }

    {
        RenderSceneCommand cmd;
        facade->execute(cmd);
    }

    ui->hierarchyWidget->updateHierarchy();
}

void MainWindow::onLoadAction()
{
    auto filename = QFileDialog::getOpenFileName(
        nullptr, "Выберите файл", nullptr, QFileDialog::tr("Txt files (*.txt)"), nullptr).toStdString();

    {
        ImportObjectCommand cmd(filename);
        facade->execute(cmd);
    }

    {
        RenderSceneCommand cmd;
        facade->execute(cmd);
    }

    ui->hierarchyWidget->updateHierarchy();
}

void MainWindow::onSwitchToNextCamera()
{
    {
        SwitchNextCameraCommand cmd;
        facade->execute(cmd);
    }
    {
        RenderSceneCommand cmd;
        facade->execute(cmd);
    }
}

void MainWindow::onAddNewCamera()
{
    AddCameraCommand cmd({0, 100, -300}, {0, 0, -1});
    facade->execute(cmd);

    ui->hierarchyWidget->updateHierarchy();
}

MainWindow::~MainWindow()
{
    delete ui;
}
