#pragma once

#include "commands/icommand.hpp"

class CreateNewSceneCommand : public ICommand
{
public:
    virtual void execute(ManagerProvider &managerProvider) override;
};

// class ImportSceneCommand : public ICommand
// {
// public:
//     ImportSceneCommand(const std::string &filename);

//     virtual void execute(ManagerProvider &managerProvider) override;

// private:
//     std::string filename;
// };
