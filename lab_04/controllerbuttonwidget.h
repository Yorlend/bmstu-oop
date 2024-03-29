#ifndef CONTROLLERBUTTONWIDGET_H
#define CONTROLLERBUTTONWIDGET_H

#include <QPushButton>
#include "controllerbutton.h"


class ControllerButtonWidget : public QPushButton
{
    Q_OBJECT

public:
    explicit ControllerButtonWidget(ControllerButton* button);
    virtual ~ControllerButtonWidget() = default;

    ControllerButton* getControllerButton();

protected slots:
    void buttonPressed();
    void buttonReleased();

private:
    ControllerButton* button;
};

#endif // CONTROLLERBUTTONWIDGET_H
