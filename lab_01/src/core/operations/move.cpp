#include "move.hpp"
#include "core/utils/error_codes.hpp"


void move_vertex(VAR vertex& vert, IN move_params params)
{
    vert.x += params.dx;
    vert.y += params.dy;
    vert.z += params.dz;
}

int move_vertices(VAR vertex_array& verts, IN move_params params)
{
    int status = NO_ERRORS;
    if (!is_valid(verts))
        status = ARGS_ERROR;
    else
    {
        for (size_t i = 0; i < verts.size; i++)
            move_vertex(verts.data[i], params);
    }

    return status;
}

int move(VAR vertex_array& verts, IN move_params params)
{
    int status = ARGS_ERROR;
    if (is_valid(verts))
        status = move_vertices(verts, params);

    return status;
}

int move(VAR model& model, IN move_params params)
{
    int status = ARGS_ERROR;
    if (is_valid(model))
        status = move_vertices(model.vertices, params);

    return status;
}
