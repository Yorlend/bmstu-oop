#include "controllerwidget.h"

ControllerWidget::ControllerWidget(Controller* controller, Cabin* cabin)
    : QWidget(nullptr), ui(new Ui::Controller), controller(controller)
{
    ui->setupUi(this);

    for (int i = FLOORS_COUNT / 2 + 1; i > 0; i--)
        addButton(i, ui->buttonsLayout);

    for (int i = FLOORS_COUNT; i > FLOORS_COUNT / 2 + 1; i--)
        addButton(i, ui->buttonsLayout_2);

    addOpenButton(ui->buttonsLayout_2);

    floorLCD = ui->lcdNumber;
    floorLCD->setSegmentStyle(QLCDNumber::Flat);
    setStyleSheet("QLCDNumber {"
        "border-style: solid;"
        "border-width: 2px;"
        "border-color: grey;"
        "border-radius: 10px;"
        "background-color: rgb(0, 0, 204);"
        "color: rgb(182, 182, 182);"
        "}");
    floorLCD->display(1);

    connect(cabin, &Cabin::movingSignal, this, &ControllerWidget::floorVisited);
}

ControllerWidget::~ControllerWidget()
{
    delete ui;
}

void ControllerWidget::floorVisited(int floor)
{
    setStyleSheet("QLCDNumber {"
        "border-style: solid;"
        "border-width: 2px;"
        "border-color: grey;"
        "border-radius: 10px;"
        "background-color: rgb(0, 0, 204);"
        "color: rgb(182, 182, 182);"
        "}");
    floorLCD->display(floor);
}


void ControllerWidget::addButton(int floor, QVBoxLayout* buttonsLayout)
{
    ControllerButton* button = new ControllerButton(floor);
    ControllerButtonWidget* buttonWidget = new ControllerButtonWidget(button);

    buttons.insert(buttons.begin(), button);
    buttonWidgets.insert(buttonWidgets.begin(), buttonWidget);

    buttonsLayout->addWidget(buttonWidget);
//    controller->connectButton(button);

    controller->connect(button, &ControllerButton::pressedSignal, controller, &Controller::buttonPressed);
    controller->connect(controller, &Controller::releaseButton, [button](int floor)
    {
        if (floor == button->getFloorNumber())
            button->release();
    });
}


void ControllerWidget::addOpenButton(QVBoxLayout* buttonsLayout)
{
    QPushButton* button = new QPushButton("<>");
    openButton = button;

    buttonsLayout->addWidget(button);
//    controller->connectOpenButton(button);
    controller->connect(button, &QPushButton::pressed, controller, &Controller::openButtonPressed);
}
