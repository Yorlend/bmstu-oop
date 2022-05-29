#include "facade.hpp"

Facade::Facade(std::unique_ptr<ManagerProvider> managerProvider)
    : managerProvider(std::move(managerProvider))
{
}

void Facade::execute(ICommand &command)
{
    command.execute(*managerProvider);
}
