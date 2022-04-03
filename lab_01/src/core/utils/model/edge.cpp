#include <cstdlib>
#include <cstring>
#include "edge.hpp"
#include "core/utils/error_codes.hpp"
#include "core/utils/file_utils.hpp"

edge_array init_edges()
{
    edge_array res_edges{};

    res_edges.data = nullptr;
    res_edges.size = 0;

    return res_edges;
}

int copy(OUT edge_array& destination, IN const edge_array& source)
{
    int status = ARGS_ERROR;
    if (is_valid(source))
    {
        destination.data = (edge*) malloc(source.size * sizeof(edge));
        if (destination.data == nullptr)
            status = MEMORY_ERROR;
        else
        {
            memcpy(destination.data, source.data, source.size * sizeof(edge));
            destination.size = source.size;
            status = NO_ERRORS;
        }
    }

    return status;
}

bool is_valid(IN const edge_array& edges)
{
    return edges.data != nullptr && edges.size != 0;
}

int allocate_edges(OUT edge_array& edges, IN size_t size)
{
    int status = NO_ERRORS;
    if (size == 0)
        status = ARGS_ERROR;
    else
    {
        edges.data = (edge*) calloc(size, sizeof(edge));

        if (edges.data == nullptr)
            status = MEMORY_ERROR;
        else
            edges.size = size;
    }

    return status;
}

void free_edges(VAR edge_array& edges)
{
    if (edges.data != nullptr)
    {
        free(edges.data);
        edges.size = 0;
        edges.data = nullptr;
    }
}

int read_edge(OUT edge& edge, IN FILE* file)
{
    int status = NO_ERRORS;
    if (file == nullptr)
        status = FILE_ERROR;
    else if (fscanf(file, "%zu%zu", &edge.first_vertex, &edge.second_vertex) != 2)
        status = LOAD_ERROR;

    return status;
}

int read_edges(OUT edge_array& edges, IN FILE* file)
{
    if (file == nullptr)
        return FILE_ERROR;

    size_t edges_quantity = 0;
    int status = read_quantity(edges_quantity, file);

    if (status == NO_ERRORS)
    {
        status = allocate_edges(edges, edges_quantity);

        for (size_t i = 0; status == NO_ERRORS && i < edges_quantity; i++)
            status = read_edge(edges.data[i], file);

        if (status != NO_ERRORS)
            free_edges(edges);
    }

    return status;
}

int get_size(OUT size_t& size, IN const edge_array& edges)
{
    int status = NO_ERRORS;
    if (!is_valid(edges))
        status = ARGS_ERROR;
    else
        size = edges.size;

    return status;
}

int get(OUT edge& edge, IN const edge_array& edges, IN size_t index)
{
    int status = NO_ERRORS;
    if (!is_valid(edges))
        status = ARGS_ERROR;
    else if (index >= edges.size)
        status = OUT_OF_BOUNDS_ERROR;
    else
        edge = edges.data[index];

    return status;
}
