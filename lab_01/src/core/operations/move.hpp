#pragma once


#include "core/utils/var_types.hpp"
#include "core/utils/model/vertex.hpp"
#include "core/utils/model/model.hpp"

struct move_params
{
    double dx;
    double dy;
    double dz;
};

void move_vertex(VAR vertex& vert, IN move_params params);
int move_vertices(VAR vertex_array& verts, IN move_params params);

int move(VAR model& model, IN move_params params);
int move(VAR vertex_array& verts, IN move_params params);
