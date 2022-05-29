#pragma once

#include "iobjectdirector.hpp"

class DefaultCameraDirector : public IObjectDirector
{
public:
    virtual std::unique_ptr<BaseObject> construct() override;
};