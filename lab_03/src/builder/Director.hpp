#pragma once

#include "BaseObjectBuilder.hpp"
#include "object/BaseObject.hpp"
#include ""
#include <memory>

class Director
{
public:
    
    explicit Director(std::unique_ptr<BaseObjectBuilder>&& objectBuilder) noexcept;

    std::shared_ptr<BaseObject> construct(std::unique_ptr<IObjectLoader> loader) const;

private:
    std::unique_ptr<BaseObjectBuilder> builder;
};
