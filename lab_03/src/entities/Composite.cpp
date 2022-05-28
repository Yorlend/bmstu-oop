#include "Composite.hpp"

bool Composite::add(std::shared_ptr<BaseObject> obj)
{
    objects.push_back(obj);

    return true;
}

bool Composite::remove(Iterator iter)
{
    objects.erase(iter);

    return true;
}

BaseObject::Iterator Composite::begin()
{
    return objects.begin();
}

BaseObject::Iterator Composite::end()
{
    return objects.end();
}

bool Composite::isComposite() const
{
    return true;
}
