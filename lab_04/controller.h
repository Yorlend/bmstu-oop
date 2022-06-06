#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QTimer>
#include <QPushButton>
#include "common.h"
#include "cabin.h"
#include "door.h"
#include "controllerbutton.h"


class Controller : public QObject
{
    Q_OBJECT

public:
    enum class State
    {
        NOT_ACTIVE,
        DOORS_OPENING,
        WAITING_PASSENGERS,
        DOORS_CLOSING,
        ELEVATOR_MOVING,
        DECIDING_STATE
    };

    Controller(Cabin* cabin, Door* door);
    virtual ~Controller() = default;

signals:
    void releaseButton(int floor);

    void startOpeningDoorsSignal();
    void doorsOpeningSignal();
    void doorsClosingSignal();

    void cabinMoveSignal(int targetFloor);
    void cabinStopSignal();

    void elevatorMoveSignal();
    void controllerNotActiveSignal();

public slots:
    void controllerIsNotActive();                 // NOT_ACTIVE
    void decide();                                // DECIDING_STATE
    void cabinIsMoving();                         // ELEVATOR_IN_MOVE
    void startOpeningDoors();                     // OPENING_DOORS
    void doorOpened();                            // WAITING_PASSENGERS
    void waitingTimeout();                        // CLOSING_DOORS

    void buttonPressed(int floorNumber);
    void openButtonPressed();

private:
    bool hasRequests() const;
    
    int getNextTargetFloor() const;
    int getNextTargetFloor(int currFloor, Direction dir) const;

    State state = State::NOT_ACTIVE;
    bool floorRequested[FLOORS_COUNT] = { false };

    Cabin* cabin;
    Door* door;
    QTimer timer;
};

#endif // CONTROLLER_H
