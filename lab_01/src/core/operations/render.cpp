
#include "render.hpp"
#include "core/utils/error_codes.hpp"

int render(VAR render_params& params, IN const model& model)
{
    projection temp_projection{};
    int status = project(temp_projection, model);

    if (status == NO_ERRORS)
    {
        free_projection(params.proj);
        params.proj = temp_projection;
    }

    return status;
}
