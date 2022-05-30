#include <QStringListModel>
#include "hierarchy_widget.hpp"

#include "commands/scenecommands.hpp"
#include "commands/rendercommands.hpp"
#include "commands/cameracommands.hpp"
#include "commands/objectcommands.hpp"

HierarchyWidget::HierarchyWidget(QWidget *parent)
    : QWidget(parent), ui(new Ui::HierarchyWidget)
{
    ui->setupUi(this);

    ui->objectListView->setModel(new QStringListModel());

    auto selectionModel = ui->objectListView->selectionModel();

    connect(selectionModel, &QItemSelectionModel::selectionChanged, this, &HierarchyWidget::selectionChanged);
}

HierarchyWidget::~HierarchyWidget()
{
    delete ui;
}

void HierarchyWidget::setFacade(std::shared_ptr<Facade> newFacade)
{
    facade = newFacade;
}

void HierarchyWidget::updateHierarchy()
{
    GetHierarchyCommand cmd([this](const Scene& scene){
        auto model = this->ui->objectListView->model();
        model->removeRows(0, model->rowCount());

        for (auto obj : scene)
        {
            auto id = obj->getId();
            auto name = obj->getName();

            name = std::to_string(id) + ": " + name;

            model->insertRow(model->rowCount());
            auto index = model->index(model->rowCount() - 1, 0);
            model->setData(index, QString::fromStdString(name));
        }
    });

    facade->execute(cmd);
}

void HierarchyWidget::selectionChanged()
{
    auto model = ui->objectListView->model();
    auto selectionModel = ui->objectListView->selectionModel();
    auto selected = selectionModel->selectedIndexes();

    std::list<size_t> ids;

    foreach(const auto &index, selectionModel->selectedIndexes())
        ids.push_back(extractId(index.data(Qt::DisplayRole).toString()));

    emit selectedSignal(ids);
}

size_t HierarchyWidget::extractId(const QString& string)
{
    return string.split(":").front().toULong();
}
