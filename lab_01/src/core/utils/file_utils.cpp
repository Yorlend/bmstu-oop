#include "file_utils.hpp"
#include "error_codes.hpp"

int read_quantity(OUT size_t& quantity, IN FILE* file)
{
    if (file == nullptr)
        return FILE_ERROR;

    if (fscanf(file, "%zu", &quantity) != 1)
        return LOAD_ERROR;

    return NO_ERRORS;
}
