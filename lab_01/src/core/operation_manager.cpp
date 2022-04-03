
#include "operation_manager.hpp"
#include "utils/error_codes.hpp"

int perform_operation(IN const op_params& parameters)
{
    static model model = init_model();
    int status = NO_ERRORS;

    switch (parameters.op)
    {
        case LOAD:
            status = load_model(model, parameters.loading);
            break;
        case RENDER:
            status = render(model, parameters.rendering);
            break;
        case MOVE:
            status = move(model, parameters.moving);
            break;
        case ROTATE:
            status = rotate(model, parameters.rotating);
            break;
        case RESIZE:
            status = scale(model, parameters.resizing);
            break;
        case EXIT:
            cleanup(model);
            break;
        default:
            status = UNKNOWN_OPERATION;
            break;
    }

    return status;
}
