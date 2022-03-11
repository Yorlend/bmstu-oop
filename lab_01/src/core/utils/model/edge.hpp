#pragma once

#include <cstdio>
#include "core/utils/var_types.hpp"

struct edge
{
    size_t first_vertex;
    size_t second_vertex;
};

struct edge_array
{
    size_t size;
    edge* data;
};

edge_array init_edges();
int copy(OUT edge_array& destination, IN const edge_array& source);

bool is_valid(IN const edge_array& edges);

int allocate_edges(OUT edge_array& edges, IN size_t size);
void free_edges(VAR edge_array& edges);

int read_edge(OUT edge& edge, IN FILE* file);
int read_edges(OUT edge_array& edges, IN FILE* file);

int get_size(OUT size_t& size, IN const edge_array& edges);

int get(OUT edge& edge, IN const edge_array& edges, IN size_t index);
