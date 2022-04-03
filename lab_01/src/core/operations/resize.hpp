#pragma once


#include "core/utils/var_types.hpp"
#include "core/utils/model/vertex.hpp"
#include "core/utils/model/model.hpp"

struct resize_params
{
    double cx;
    double cy;
    double cz;
    double kx;
    double ky;
    double kz;
};

void resize_vertex(VAR vertex& vert, resize_params params);
int resize_vertices(VAR vertex_array& verts, resize_params params);

int scale(VAR model& mod, resize_params params);
