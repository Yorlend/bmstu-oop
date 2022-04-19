#include "model.hpp"
#include "core/utils/error_codes.hpp"

model init_model()
{
    model res_model{};

    res_model.edges = init_edges();
    res_model.vertices = init_vertices();

    return res_model;
}

int copy(OUT model& destination, IN const model& source)
{
    int status = ARGS_ERROR;
    if (is_valid(source))
    {
        status = copy(destination.vertices, source.vertices);
        if (status == NO_ERRORS)
            status = copy(destination.edges, source.edges);

        if (status != NO_ERRORS)
            free_model(destination);
    }

    return status;
}

bool is_valid(IN const model& model)
{
    return is_valid(model.vertices) && is_valid(model.edges);
}

int read_model(OUT model& model, IN FILE* file)
{
    int status = read_vertices(model.vertices, file);

    if (status == NO_ERRORS) {
        status = read_edges(model.edges, file);

        if (status != NO_ERRORS)
            free_vertices(model.vertices);
    }

    return status;
}

void free_model(VAR model& model)
{
    free_vertices(model.vertices);
    free_edges(model.edges);
}

void free_model(VAR vertex_array& verts)
{
    free_vertices(verts);
}

int get_edge_size(OUT size_t& size, IN const model& model)
{
    int status = NO_ERRORS;
    if (!is_valid(model))
        status = ARGS_ERROR;
    else
        status = get_size(size, model.edges);

    return status;
}

int get_vertex(OUT vertex& vert, IN const model& model, IN size_t index)
{
    int status = NO_ERRORS;
    if (!is_valid(model))
        status = ARGS_ERROR;
    else
        status = get(vert, model.vertices, index);

    return status;
}

int get_edge(OUT edge& edge, IN const model& model, IN size_t index)
{
    int status = NO_ERRORS;
    if (!is_valid(model))
        status = ARGS_ERROR;
    else
        status = get(edge, model.edges, index);

    return status;
}
