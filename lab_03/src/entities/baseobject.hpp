#pragma once

#include <list>
#include <string>
#include <memory>
#include "math/transform.hpp"

class IVisitor;

class BaseObject
{
public:
    using Iterator = std::list<std::shared_ptr<BaseObject>>::iterator;

    BaseObject(size_t id, const std::string &name = "BaseObject", const Transform &transform = Transform());
    virtual ~BaseObject() = default;

    size_t getId() const;

    const std::string &getName() const;
    void setName(const std::string &newName);

    const Transform &getTransform() const;
    void setTransform(const Transform &newTransform);

    bool getVisibility() const;
    void setVisibility(bool visibility);

    virtual bool isComposite() const;

    virtual bool insertChild(Iterator pos, std::shared_ptr<BaseObject> obj);
    virtual bool removeChild(Iterator pos);

    virtual Iterator begin();
    virtual Iterator end();

    virtual void accept(IVisitor &visitor) = 0;

private:
    size_t id;
    std::string name;
    Transform transform;
    bool visible;
};
