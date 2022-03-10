#pragma once

#include "core/utils/projection/projection.hpp"

struct render_params
{
    projection& proj;
};

int render(VAR render_params& params, IN const model& model);
