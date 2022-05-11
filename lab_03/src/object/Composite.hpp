#pragma once

#include "BaseObject.hpp"
#include <list>


class Composite : public BaseObject
{
public:
    Composite() = default;

    virtual bool add(std::shared_ptr<BaseObject> obj) override;
    virtual bool remove(Iterator iter) override;
    virtual Iterator begin() override;
    virtual Iterator end() override;

    virtual bool isComposite() const override;

private:
    std::list<std::shared_ptr<BaseObject>> objects;
};
