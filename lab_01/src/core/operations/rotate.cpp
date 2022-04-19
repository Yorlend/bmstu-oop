#include <cmath>
#include "rotate.hpp"
#include "core/utils/error_codes.hpp"
#include "move.hpp"

static void rotate_x(VAR vertex& vert, IN double angle)
{
    double sin_a = sin(angle * M_PI / 180);
    double cos_a = cos(angle * M_PI / 180);

    double new_y = cos_a * vert.y - sin_a * vert.z;
    double new_z = sin_a * vert.y + cos_a * vert.z;

    vert.y = new_y;
    vert.z = new_z;
}

static void rotate_y(VAR vertex& vert, IN double angle)
{
    double sin_a = sin(angle * M_PI / 180);
    double cos_a = cos(angle * M_PI / 180);

    double new_x = cos_a * vert.x + sin_a * vert.z;
    double new_z = -sin_a * vert.x + cos_a * vert.z;

    vert.x = new_x;
    vert.z = new_z;
}

static void rotate_z(VAR vertex& vert, IN double angle)
{
    double sin_a = sin(angle * M_PI / 180);
    double cos_a = cos(angle * M_PI / 180);

    double new_x = cos_a * vert.x - sin_a * vert.y;
    double new_y = sin_a * vert.x + cos_a * vert.y;

    vert.x = new_x;
    vert.y = new_y;
}

void rotate_vertex(VAR vertex& vert, IN rotate_params params)
{
    rotate_x(vert, params.ax);
    rotate_y(vert, params.ay);
    rotate_z(vert, params.az);
}

int rotate_vertices(VAR vertex_array& verts, IN rotate_params params)
{
    int status = NO_ERRORS;
    if (!is_valid(verts))
        status = ARGS_ERROR;
    else
    {
        for (size_t i = 0; i < verts.size; i++)
            rotate_vertex(verts.data[i], params);
    }

    return status;
}

static move_params move_to_center(IN const rotate_params& params)
{
    move_params move_params{};

    move_params.dx = params.cx;
    move_params.dy = params.cy;
    move_params.dz = params.cz;

    return move_params;
}

static move_params move_from_center(IN const rotate_params& params)
{
    move_params move_params{};

    move_params.dx = -params.cx;
    move_params.dy = -params.cy;
    move_params.dz = -params.cz;

    return move_params;
}

int rotate(VAR model& mod, IN rotate_params params)
{
    if (!is_valid(mod))
        return ARGS_ERROR;

    vertex_array verts{};
    int status = copy(verts, mod.vertices);

    if (status == NO_ERRORS)
        status = move(verts, move_to_center(params));

    if (status == NO_ERRORS)
        status = rotate_vertices(verts, params);

    if (status == NO_ERRORS)
        status = move(verts, move_from_center(params));

    if (status != NO_ERRORS)
        free_model(verts);
    else
    {
        free_model(mod.vertices);
        mod.vertices = verts;
    }

    return status;
}
