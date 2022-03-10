#include "load.hpp"

#include "core/utils/error_codes.hpp"

int load_model(OUT model& model, IN load_params params)
{
    int status = NO_ERRORS;

    if (params.filename == nullptr)
        status = ARGS_ERROR;
    else
    {
        FILE* file = fopen(params.filename, "r");

        status = read_model(model, file);

        if (file != nullptr)
            fclose(file);
    }

    return status;
}
