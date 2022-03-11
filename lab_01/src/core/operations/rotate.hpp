#pragma once


#include "core/utils/model/vertex.hpp"
#include "core/utils/model/model.hpp"

struct rotate_params
{
    double cx;
    double cy;
    double cz;

    double ax;
    double ay;
    double az;
};

void rotate_vertex(VAR vertex& vert, IN rotate_params params);
int rotate_vertices(VAR vertex_array& verts, IN rotate_params params);

int rotate(VAR model& model, IN rotate_params params);
