#include "vertex.hpp"
#include "core/utils/error_codes.hpp"
#include "core/utils/file_utils.hpp"
#include <cstdlib>
#include <cstring>

vertex_array init_vertices()
{
    vertex_array res_vertices{};

    res_vertices.data = nullptr;
    res_vertices.size = 0;

    return res_vertices;
}

int copy(OUT vertex_array& destination, IN const vertex_array& source)
{
    int status = ARGS_ERROR;
    if (is_valid(source))
    {
        destination.data = (vertex*) malloc(source.size * sizeof(vertex));
        if (destination.data == nullptr)
            status = MEMORY_ERROR;
        else
        {
            memcpy(destination.data, source.data, source.size * sizeof(vertex));
            destination.size = source.size;
            status = NO_ERRORS;
        }
    }

    return status;
}

bool is_valid(IN const vertex_array& vertices)
{
    return vertices.data != nullptr && vertices.size != 0;
}

int allocate_vertices(OUT vertex*& verts, IN size_t size)
{
    int status = NO_ERRORS;
    if (size == 0)
        status = ARGS_ERROR;
    else
    {
        verts = (vertex*) calloc(size, sizeof(vertex));

        if (verts == nullptr)
            status = MEMORY_ERROR;
    }

    return status;
}

void free_vertices(VAR vertex_array& verts)
{
    if (verts.data != nullptr)
    {
        free(verts.data);
        verts.size = 0;
        verts.data = nullptr;
    }
}

void free_vertices(VAR vertex*& verts)
{
    if (verts != nullptr)
    {
        free(verts);
        verts = nullptr;
    }
}

int read_vertex(OUT vertex& vert, IN FILE* file)
{
    int status = NO_ERRORS;
    if (file == nullptr)
        status = FILE_ERROR;
    else if (fscanf(file, "%lf%lf%lf", &vert.x, &vert.y, &vert.z) != 3)
        status = LOAD_ERROR;

    return status;
}

int read_vertices(OUT vertex_array& verts, IN FILE* file)
{
    if (file == nullptr)
        return FILE_ERROR;

    size_t verts_quantity = 0;

    int status = read_quantity(verts.size, file);

    if (status == NO_ERRORS)
    {
        status = allocate_vertices(verts.data, verts.size);

        for (size_t i = 0; status == NO_ERRORS && i < verts.size; i++)
            status = read_vertex(verts.data[i], file);

        if (status != NO_ERRORS)
            free_vertices(verts.data);
    }

    return status;
}

int get(OUT vertex& vert, IN const vertex_array& verts, IN size_t index)
{
    int status = NO_ERRORS;
    if (!is_valid(verts))
        status = ARGS_ERROR;
    else if (index >= verts.size)
        status = OUT_OF_BOUNDS_ERROR;
    else
        vert = verts.data[index];

    return status;
}
