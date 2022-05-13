#include "Director.hpp"

Director::Director(std::unique_ptr<BaseObjectBuilder>&& objectBuilder) noexcept
    : builder(std::move(objectBuilder)) {}

std::shared_ptr<BaseObject> Director::construct() const
{
    
}
