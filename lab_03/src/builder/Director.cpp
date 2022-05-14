#include "Director.hpp"

Director::Director(std::unique_ptr<BaseObjectBuilder>&& objectBuilder) noexcept
    : builder(std::move(objectBuilder)) {}

std::shared_ptr<BaseObject> Director::construct(std::unique_ptr<IObjectLoader> loader) const
{
    
}
