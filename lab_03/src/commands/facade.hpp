#pragma once

#include "icommand.hpp"

class Facade
{
public:
    void execute(ICommand& command);
};
