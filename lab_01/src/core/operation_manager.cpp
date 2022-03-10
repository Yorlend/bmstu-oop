
#include "operation_manager.hpp"
#include "utils/error_codes.hpp"

int perform_operation(op_params parameters)
{
    static model model = init_model();
    int status = NO_ERRORS;

    switch (parameters.op)
    {
        case LOAD:
            status = load_model(model, parameters.loading);
            break;
        case RENDER:
            status = render(parameters.rendering, model);
            break;
        case MOVE:
            break;
        case ROTATE:
            break;
        case RESIZE:
            break;
        case EXIT:
            break;
    }

    return status;
}
