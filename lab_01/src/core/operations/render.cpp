
#include "render.hpp"
#include "core/utils/error_codes.hpp"

int render(VAR render_params& params, VAR projection& proj,  IN const model& model)
{
    projection temp_projection{};
    int status = project(temp_projection, model);

    if (status == NO_ERRORS)
    {
        free_projection(proj);
        proj = temp_projection;
        params.proj = proj;
    }

    return status;
}
