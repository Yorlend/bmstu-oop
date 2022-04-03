#include "load.hpp"

#include "core/utils/error_codes.hpp"

int load_model(VAR model& mod, IN load_params params)
{
    if (params.filename == nullptr)
        return ARGS_ERROR;

    int status = NO_ERRORS;

    FILE* file = fopen(params.filename, "r");
    if (file != nullptr)
    {
        model tmp_mod{};

        status = read_model(tmp_mod, file);

        fclose(file);

        if (status == NO_ERRORS)
        {
            free_model(mod);
            mod = tmp_mod;
        }
    }

    return status;
}
