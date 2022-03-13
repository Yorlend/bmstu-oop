#include "exit.hpp"

void exit(VAR model& model, VAR projection& projection)
{
    free_model(model);
    free_projection(projection);
}
