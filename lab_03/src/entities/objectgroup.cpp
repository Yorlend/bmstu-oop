#include "objectgroup.hpp"
#include "visitor/ivisitor.hpp"

ObjectGroup::ObjectGroup(size_t id, const std::string &name)
    : BaseObject(id, name)
{
}

bool ObjectGroup::isComposite() const
{
    return true;
}

bool ObjectGroup::insertChild(Iterator pos, std::shared_ptr<BaseObject> obj)
{
    objects.insert(pos, obj);
    return true;
}

bool ObjectGroup::removeChild(Iterator pos)
{
    objects.erase(pos);
    return true;
}

BaseObject::Iterator ObjectGroup::begin()
{
    return objects.begin();
}

BaseObject::Iterator ObjectGroup::end()
{
    return objects.end();
}

void ObjectGroup::accept(IVisitor &visitor)
{
    visitor.visit(*this);
}
