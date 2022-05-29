#pragma once

#include <cstddef>
#include "math/transform.hpp"
#include "icommand.hpp"

class ImportObjectCommand : public ICommand
{
public:
    ImportObjectCommand(const std::string &filename);

    virtual void execute(ManagerProvider &managerProvider) override;

private:
    std::string filename;
};

class RemoveObjectCommand : public ICommand
{
public:
    RemoveObjectCommand(size_t objectId);

    virtual void execute(ManagerProvider &managerProvider) override;

private:
    size_t objectId;
};

class TransformObjectCommand : public ICommand
{
public:
    TransformObjectCommand(size_t objectId, const Transform &transform);

    virtual void execute(ManagerProvider &managerProvider) override;

private:
    size_t objectId;
    Transform transform;
};
