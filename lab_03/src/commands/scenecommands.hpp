#pragma once

#include <functional>
#include "commands/icommand.hpp"

class CreateNewSceneCommand : public ICommand
{
public:
    virtual void execute(ManagerProvider &managerProvider) override;
};

class GetHierarchyCommand : public ICommand
{
public:
    GetHierarchyCommand(std::function<void(const Scene &)> callback);

    virtual void execute(ManagerProvider &managerProvider) override;

private:
    std::function<void(const Scene &)> callback;
};

class GetInfoAboutCommand : public ICommand
{
public:
    GetInfoAboutCommand(const std::list<size_t> &ids, std::function<void(std::shared_ptr<BaseObject>)> callback);

    virtual void execute(ManagerProvider &managerProvider) override;

private:
    std::list<size_t> ids;
    std::function<void(std::shared_ptr<BaseObject>)> callback;
};
