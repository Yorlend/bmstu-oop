#pragma once

#include "core/utils/projection/projection.hpp"

struct render_params
{
    projection& proj;
};

int render(VAR render_params& params, VAR projection& proj, IN const model& model);
