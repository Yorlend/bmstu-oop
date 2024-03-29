#include <QDebug>
#include "door.h"

constexpr auto tick_value = 10;
constexpr auto max_open_value = 260 - 50;

Door::Door()
{
    connect(this, &Door::startForcedOpening, this, &Door::opening);
    connect(this, &Door::doorsAlreadyOpend, this, &Door::open);

    connect(this, &Door::openingAnimationEnd, this, &Door::open);
    connect(this, &Door::closingAnimationEnd, this, &Door::close);
}

Door::State Door::getState() const
{
    return state;
}

void Door::opening()
{
    State prevState = state;
    if (state == State::CLOSED || state == State::CLOSING)
    {
        state = State::OPENING;
        qDebug() << "door is opening...";

        if (prevState == State::OPENED)
            emit openedSignal();
        else
        {
            timer.stop();
            timer.disconnect();
            connect(&timer, &QTimer::timeout, this, &Door::openingProcess);
            timer.start(tick_value);
        }
    }
}

void Door::openingProcess()
{
    openingValue += 2;
    if (openingValue >= max_open_value)
    {
        openingValue = max_open_value;
        timer.stop();
        timer.disconnect();
        emit openingAnimationEnd();
    }
    else
        emit doorsAnimationSignal(openingValue);
}

void Door::closing()
{
    if (state == State::OPENED)
    {
        qDebug() << "door is closing...";
        state = State::CLOSING;
        
        timer.stop();
        timer.disconnect();
        connect(&timer, &QTimer::timeout, this, &Door::closingProcess);
        timer.start(tick_value);
    }
}

void Door::closingProcess()
{
    openingValue -= 2;
    if (openingValue <= 0)
    {
        openingValue = 0;
        timer.stop();
        timer.disconnect();
        emit closingAnimationEnd();
    }
    else
        emit doorsAnimationSignal(openingValue);
}

void Door::open()
{
    if (state == State::OPENING)
    {
        qDebug() << "door opened.";
        state = State::OPENED;
        emit openedSignal();
    }
}

void Door::close()
{
    if (state == State::CLOSING)
    {
        qDebug() << "door closed.";
        state = State::CLOSED;
        emit closedSignal();
    }
}
