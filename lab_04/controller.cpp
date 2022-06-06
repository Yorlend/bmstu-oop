#include "controller.h" 
#include <QDebug> 

constexpr auto wait_timeout = 2000;


Controller::Controller(Cabin *cabin, Door *door)
    : cabin(cabin), door(door)
{
    connect(this, &Controller::startOpeningDoorsSignal, this, &Controller::startOpeningDoors);

    connect(this, &Controller::doorsOpeningSignal, door, &Door::opening);
    connect(this, &Controller::doorsClosingSignal, door, &Door::closing);
    connect(door, &Door::openedSignal, this, &Controller::doorOpened);
    connect(door, &Door::closedSignal, this, &Controller::decide);
    connect(this, &Controller::elevatorMoveSignal, this, &Controller::cabinIsMoving);
    
    connect(this, &Controller::cabinMoveSignal, cabin, &Cabin::startMove);
    connect(this, &Controller::cabinStopSignal, cabin, &Cabin::stop);
    connect(cabin, &Cabin::movingSignal, this, &Controller::decide);
    connect(cabin, &Cabin::stoppedSignal, this, &Controller::startOpeningDoors);

    connect(this, &Controller::controllerNotActiveSignal, this, &Controller::controllerIsNotActive);
    connect(&timer, &QTimer::timeout, this, &Controller::waitingTimeout);
}

void Controller::startOpeningDoors()
{
    if (state == State::DECIDING_STATE || state == State::DOORS_CLOSING 
        || state == State::WAITING_PASSENGERS || state == State::NOT_ACTIVE)
    {
        state = State::DOORS_OPENING;

        qDebug() << "controller started opening doors";
        emit doorsOpeningSignal();
    }
}   

void Controller::doorOpened()
{
    if (state == State::DOORS_OPENING)
    {
        state = State::WAITING_PASSENGERS;
        qDebug() << "waiting passengers...";

        int currFloor = cabin->getCurrFloor();
        floorRequested[currFloor - 1] = false;

        emit releaseButton(currFloor);
        timer.start(wait_timeout);
    }
}

void Controller::waitingTimeout()
{
    if (state == State::WAITING_PASSENGERS)
    {
        state = State::DOORS_CLOSING;
        qDebug() << "end waiting";
        timer.stop();
        emit doorsClosingSignal();
    }
}

void Controller::decide()
{
    if (state == State::ELEVATOR_MOVING || state == State::DOORS_CLOSING)
    {
        state = State::DECIDING_STATE;

        if (floorRequested[cabin->getCurrFloor() - 1]) // Приехали куда надо
            emit cabinStopSignal();
        else if (getNextTargetFloor() != 0)            // Едем к цели         
            emit elevatorMoveSignal();
        else                                           // Ехать некуда
            emit controllerNotActiveSignal();
    }
}

void Controller::cabinIsMoving()
{
    if (state == State::DECIDING_STATE)
    {
        state = State::ELEVATOR_MOVING;

        emit cabinMoveSignal(getNextTargetFloor());
    }
}

void Controller::controllerIsNotActive()
{
    if (state == State::DECIDING_STATE)
    {
        state = State::NOT_ACTIVE;
        qDebug() << "elevator not active!";
    }
}


void Controller::buttonPressed(int floorNumber)
{
    floorRequested[floorNumber - 1] = true;

    if (state == State::NOT_ACTIVE) // Если лифт не активен
        emit startOpeningDoorsSignal();
    else if (state != State::WAITING_PASSENGERS && (state == State::DOORS_CLOSING || state == State::WAITING_PASSENGERS)
        && (floorNumber == cabin->getCurrFloor())) // Если нажали кнопку этажа, на котором лифт и так находится
        emit startOpeningDoorsSignal();
    else if (floorNumber == cabin->getCurrFloor())
    {
        floorRequested[floorNumber - 1] = false;
        emit releaseButton(floorNumber);
    }
}

void Controller::openButtonPressed()
{
    if (state != State::WAITING_PASSENGERS && (state == State::DOORS_CLOSING || state == State::NOT_ACTIVE))
        emit startOpeningDoorsSignal();
}


bool Controller::hasRequests() const
{
    for (int i = 0; i < FLOORS_COUNT; i++)
        if (floorRequested[i])
            return true;

    return false;
}

int Controller::getNextTargetFloor() const
{
    int currFloor = cabin->getCurrFloor();
    Direction dir = cabin->getDirection();

    return getNextTargetFloor(currFloor, dir);
}

int Controller::getNextTargetFloor(int currFloor, Direction dir) const
{
    if (dir == Direction::DOWN)
    {
        for (int i = currFloor - 1; i >= 0; i--)
            if (floorRequested[i])
                return i + 1;

        for (int i = currFloor - 1; i < FLOORS_COUNT; i++)
            if (floorRequested[i])
                return i + 1;
    }
    else
    {
        for (int i = currFloor - 1; i < FLOORS_COUNT; i++)
            if (floorRequested[i])
                return i + 1;

        for (int i = currFloor - 1; i >= 0; i--)
            if (floorRequested[i])
                return i + 1;
    }
    return 0;
}
