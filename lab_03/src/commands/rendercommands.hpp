#pragma once

#include "icommand.hpp"

class RenderSceneCommand : public ICommand
{
public:
    virtual void execute(ManagerProvider &managerProvider) override;
};
