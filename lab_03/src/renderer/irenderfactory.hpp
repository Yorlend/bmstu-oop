#pragma once

#include <memory>
#include "irenderer.hpp"

class IRenderFactory
{
public:
    virtual ~IRenderFactory() = default;

    virtual std::unique_ptr<IRenderer> createRenderer() = 0;
};
