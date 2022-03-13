#include "load.hpp"

#include "core/utils/error_codes.hpp"

int load_model(VAR model& model, IN load_params params)
{
    int status = NO_ERRORS;

    free_model(model);

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
