
#include "operation_manager.hpp"
#include "utils/error_codes.hpp"

int perform_operation(op_params parameters)
{
    switch (parameters.op)
    {
        case LOAD:
            break;
        case RENDER:
            break;
        case MOVE:
            break;
        case ROTATE:
            break;
        case RESIZE:
            break;
        case QUIT:
            break;
    }

    return SUCCESS;
}
