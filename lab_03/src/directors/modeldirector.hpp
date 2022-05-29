#pragma once

#include "iobjectdirector.hpp"

class ModelDirector : public IObjectDirector
{
public:
    virtual std::unique_ptr<BaseObject> construct() override;
};
