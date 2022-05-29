#pragma once

#include <list>
#include "baseobject.hpp"

class ObjectGroup : public BaseObject
{
public:
    ObjectGroup(size_t id, const std::string &name);

    virtual bool isComposite() const override;

    virtual bool insertChild(Iterator pos, std::shared_ptr<BaseObject> obj) override;

    virtual bool removeChild(Iterator pos) override;

    virtual Iterator begin() override;
    virtual Iterator end() override;

    virtual void accept(IVisitor &visitor) override;

private:
    std::list<std::shared_ptr<BaseObject>> objects;
};
