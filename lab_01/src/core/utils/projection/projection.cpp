#include <cstdlib>
#include <cmath>
#include "projection.hpp"
#include "core/utils/error_codes.hpp"


projection init_projection()
{
    projection result{};

    result.data = nullptr;
    result.size = 0;

    return result;
}

bool is_valid(IN const projection& projection)
{
    return projection.data != nullptr && projection.size != 0;
}

int allocate_projection(OUT projection& projection, IN size_t size)
{
    int status = NO_ERRORS;
    if (size == 0)
        status = ARGS_ERROR;
    else
    {
        projection.data = (line*) calloc(size, sizeof(line));

        if (projection.data == nullptr)
            status = MEMORY_ERROR;
        else
            projection.size = size;
    }

    return status;
}

void free_projection(VAR projection& projection)
{
    if (projection.data != nullptr)
    {
        free(projection.data);
        projection.data = nullptr;
        projection.size = 0;
    }
}

static point project_vertex(IN const vertex& vertex)
{
    point res_point{};

    res_point.x = static_cast<int>(round(vertex.x));
    res_point.y = static_cast<int>(round(vertex.y));

    return res_point;
}

static int project_edge(OUT line& line, IN const model& model, IN size_t index)
{
    edge edge{};
    vertex first_vert{}, second_vert{};
    int status = get_edge(edge, model, index);

    if (status == NO_ERRORS)
        status = get_vertex(first_vert, model, edge.first_vertex);

    if (status == NO_ERRORS)
        status = get_vertex(second_vert, model, edge.second_vertex);

    if (status == NO_ERRORS)
    {
        line.start = project_vertex(first_vert);
        line.end = project_vertex(second_vert);
    }

    return status;
}

int project(OUT projection& projection, IN const model& model)
{
    size_t edges_size = 0;
    int status = get_edge_size(edges_size, model);

    if (status == NO_ERRORS)
        status = allocate_projection(projection, edges_size);

    for (size_t i = 0; i < edges_size && status == NO_ERRORS; i++)
        status = project_edge(projection.data[i], model, i);

    if (status != NO_ERRORS)
        free_projection(projection);

    return status;
}
