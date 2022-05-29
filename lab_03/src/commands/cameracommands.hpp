#pragma once

#include "icommand.hpp"

class SwitchNextCameraCommand : public ICommand
{
public:
    virtual void execute(ManagerProvider &managerProvider) override;
};

class SwitchPrevCameraCommand : public ICommand
{
public:
    virtual void execute(ManagerProvider &managerProvider) override;
};
