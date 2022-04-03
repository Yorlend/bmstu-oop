#pragma once

#include <QPainter>
#include "core/utils/var_types.hpp"
#include "core/utils/model/model.hpp"

struct render_params
{
    int width;
    int height;
    QPainter* painter;
};

bool is_valid(IN const render_params& params);

int render(const model &model, const render_params &params);
