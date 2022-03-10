#pragma once

#include "edge.hpp"
#include "vertex.hpp"

struct model
{
    vertex_array vertices;
    edge_array edges;
};

model init_model();
bool is_valid(IN const model& model);

int read_model(OUT model& model, IN FILE* file);
void free_model(VAR model& model);

int get_edge_size(OUT size_t& size, IN const model& model);

int get_vertex(OUT vertex& vert, IN const model& model, IN size_t index);
int get_edge(OUT edge& edge, IN const model& model, IN size_t index);
