#pragma once

#include <cstdio>
#include "core/utils/var_types.hpp"

struct vertex
{
    double x;
    double y;
    double z;
};

struct vertex_array
{
    size_t size;
    vertex* data;
};

vertex_array init_vertices();
int copy(OUT vertex_array& destination, IN const vertex_array& source);

bool is_valid(IN const vertex_array& vertices);

int allocate_vertices(OUT vertex_array& verts, IN size_t size);
void free_vertices(VAR vertex_array& verts);

int read_vertex(OUT vertex& vert, IN FILE* file);
int read_vertices(OUT vertex_array& verts, IN FILE* file);

int get(OUT vertex& vert, IN const vertex_array& verts, IN size_t index);
