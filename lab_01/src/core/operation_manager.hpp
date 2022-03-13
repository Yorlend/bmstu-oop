#pragma once

#include "utils/var_types.hpp"
#include "operations/load.hpp"
#include "operations/render.hpp"
#include "operations/move.hpp"
#include "operations/resize.hpp"
#include "operations/rotate.hpp"
#include "operations/exit.hpp"

enum operation
{
    LOAD,
    RENDER,
    MOVE,
    ROTATE,
    RESIZE,
    EXIT
};

struct op_params
{
    operation op;
    union
    {
        load_params     loading;
        render_params   rendering;
        move_params     moving;
        resize_params   resizing;
        rotate_params   rotating;
    };
};

int perform_operation(VAR op_params parameters);
