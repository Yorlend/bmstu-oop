#pragma once

#include "iobjectdirector.hpp"

class CameraDirector : public IObjectDirector
{
public:
    virtual std::unique_ptr<BaseObject> construct() override;
};
