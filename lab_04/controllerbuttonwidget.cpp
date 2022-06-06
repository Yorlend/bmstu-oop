#include "controllerbuttonwidget.h"

ControllerButtonWidget::ControllerButtonWidget(ControllerButton* button)
    : button(button)
{
    setText(QString::number(button->getFloorNumber()));

    connect(this, &QPushButton::pressed, this, &ControllerButtonWidget::buttonPressed);
    connect(button, &ControllerButton::releasedSignal, this, &ControllerButtonWidget::buttonReleased);
}

ControllerButton *ControllerButtonWidget::getControllerButton()
{
    return button;
}

void ControllerButtonWidget::buttonPressed()
{
    setDisabled(true);
    button->press();
}

void ControllerButtonWidget::buttonReleased()
{
    setDisabled(false);
}
