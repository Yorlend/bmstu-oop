#include "inspector_widget.hpp"

#include "commands/scenecommands.hpp"
#include "commands/rendercommands.hpp"
#include "commands/cameracommands.hpp"
#include "commands/objectcommands.hpp"

InspectorWidget::InspectorWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::InspectorWidget)
{
    ui->setupUi(this);

    connect(ui->applyTranslation, &QPushButton::clicked, this, &InspectorWidget::translateAction);
    connect(ui->applyRotation, &QPushButton::clicked, this, &InspectorWidget::rotateAction);
    connect(ui->applyScaling, &QPushButton::clicked, this, &InspectorWidget::scaleAction);
}

InspectorWidget::~InspectorWidget()
{
    delete ui;
}

void InspectorWidget::setFacade(std::shared_ptr<Facade> newFacade)
{
    facade = newFacade;
}

void InspectorWidget::showInfoAbout(const std::list<size_t> &objIds)
{
    selectedIds = objIds;

    GetInfoAboutCommand cmd(objIds, [this](std::shared_ptr<BaseObject> object)
                            {
        if (object->isComposite())
        {
            std::string ids = "";

            for (auto iter : *object)
                ids += std::to_string(iter->getId()) + " ";

            ui->idLineEdit->setText(QString::fromStdString(ids));
            ui->nameLineEdit->setText("<object group>");
        }
        else
        {
            ui->idLineEdit->setText(QString::fromStdString(std::to_string(object->getId())));
            ui->nameLineEdit->setText(QString::fromStdString(object->getName()));
        } });

    facade->execute(cmd);
}

void InspectorWidget::translateAction()
{
    double dx = ui->dx->value();
    double dy = ui->dy->value();
    double dz = ui->dz->value();

    auto mat = Matrix::translate({dx, dy, dz});

    for (auto id : selectedIds)
    {
        TransformObjectCommand cmd(id, mat);
        facade->execute(cmd);
    }

    RenderSceneCommand cmd;
    facade->execute(cmd);
}

void InspectorWidget::rotateAction()
{
    double cx = ui->cx->value();
    double cy = ui->cy->value();
    double cz = ui->cz->value();

    double rx = ui->rx->value();
    double ry = ui->ry->value();
    double rz = ui->rz->value();

    auto mat = Matrix::rotate({cx, cy, cz}, {rx, ry, rz});

    for (auto id : selectedIds)
    {
        TransformObjectCommand cmd(id, mat);
        facade->execute(cmd);
    }

    RenderSceneCommand cmd;
    facade->execute(cmd);
}

void InspectorWidget::scaleAction()
{
    double cx = ui->cx->value();
    double cy = ui->cy->value();
    double cz = ui->cz->value();

    double sx = ui->sx->value();
    double sy = ui->sy->value();
    double sz = ui->sz->value();

    auto mat = Matrix::scale({cx, cy, cz}, {sx, sy, sz});

    for (auto id : selectedIds)
    {
        TransformObjectCommand cmd(id, mat);
        facade->execute(cmd);
    }

    RenderSceneCommand cmd;
    facade->execute(cmd);
}
