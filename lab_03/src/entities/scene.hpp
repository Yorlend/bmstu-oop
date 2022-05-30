#pragma once

#include "baseobject.hpp"

class Scene
{
public:
    using ConstIterator = BaseObject::ConstIterator;
    using Iterator = BaseObject::Iterator;

    Scene();
    Scene &operator=(Scene &&other) = default;

    Iterator findObjectById(size_t id);

    void insertObject(Iterator pos, std::shared_ptr<BaseObject> object);
    void removeObject(Iterator pos);

    void accept(IVisitor &visitor);

    Iterator begin();
    Iterator end();

    ConstIterator begin() const;
    ConstIterator end() const;

private:
    std::unique_ptr<BaseObject> objects;
};
