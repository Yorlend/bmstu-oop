#include "scale.hpp"
#include "move.hpp"
#include "core/utils/error_codes.hpp"

static move_params move_to_center(IN const resize_params& params)
{
    move_params move_params{};

    move_params.dx = params.cx;
    move_params.dy = params.cy;
    move_params.dz = params.cz;

    return move_params;
}

static move_params move_from_center(IN const resize_params& params)
{
    move_params move_params{};

    move_params.dx = -params.cx;
    move_params.dy = -params.cy;
    move_params.dz = -params.cz;

    return move_params;
}

void scale_vertex(VAR vertex& vert, resize_params params)
{
    vert.x *= params.kx;
    vert.y *= params.ky;
    vert.z *= params.kz;
}

int scale_vertices(VAR vertex_array& verts, resize_params params)
{
    int status = NO_ERRORS;
    if (!is_valid(verts))
        status = ARGS_ERROR;
    else
    {
        for (size_t i = 0; i < verts.size; i++)
            scale_vertex(verts.data[i], params);
    }

    return status;
}

int scale(VAR model& mod, resize_params params)
{
    if (!is_valid(mod))
        return ARGS_ERROR;

    model temp_model{};
    int status = copy(temp_model, mod);

    if (status == NO_ERRORS)
        status = move(temp_model, move_to_center(params));

    if (status == NO_ERRORS)
        status = scale_vertices(temp_model.vertices, params);

    if (status == NO_ERRORS)
        status = move(temp_model, move_from_center(params));

    if (status != NO_ERRORS)
        free_model(temp_model);
    else
    {
        free_model(mod);
        mod = temp_model;
    }

    return status;
}
