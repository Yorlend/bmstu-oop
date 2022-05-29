#pragma once

class ManagerProvider;

class ICommand
{
public:
    virtual ~ICommand() = default;

    virtual void execute(ManagerProvider &managerProvider) = 0;
};
