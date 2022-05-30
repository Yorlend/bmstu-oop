#include "inspector_widget.hpp"

#include "commands/scenecommands.hpp"
#include "commands/rendercommands.hpp"
#include "commands/cameracommands.hpp"
#include "commands/objectcommands.hpp"

InspectorWidget::InspectorWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::InspectorWidget)
{
    ui->setupUi(this);
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
    GetInfoAboutCommand cmd(objIds, [this](std::shared_ptr<BaseObject> object){
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
        }
    });

    facade->execute(cmd);
}
