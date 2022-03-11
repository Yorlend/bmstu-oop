
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
            status = move(model, parameters.moving);
            break;
        case ROTATE:
            status = rotate(model, parameters.rotating);
            break;
        case RESIZE:
            status = resize(model, parameters.resizing);
            break;
        case EXIT:
            break;
    }

    return status;
}