#include "load.hpp"

#include "core/utils/error_codes.hpp"

int load_model(VAR model& mod, IN load_params params)
{
    int status = NO_ERRORS;

    model tmp_mod{};

    if (params.filename == nullptr)
        status = ARGS_ERROR;
    else
    {
        FILE* file = fopen(params.filename, "r");

        status = read_model(tmp_mod, file);

        if (file != nullptr)
            fclose(file);
    }

    if (status == NO_ERRORS)
    {
        free_model(mod);
        mod = tmp_mod;
    }

    return status;
}
