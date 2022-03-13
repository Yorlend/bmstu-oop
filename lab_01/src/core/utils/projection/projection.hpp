#pragma once

#include "point.hpp"
#include "line.hpp"
#include "core/utils/var_types.hpp"
#include "core/utils/model/model.hpp"

struct projection
{
    size_t size;
    line* data;
};

projection init_projection();
bool is_valid(IN const projection& projection);

int allocate_projection(OUT projection& projection, IN size_t size);
void free_projection(VAR projection& projection);

int project(OUT projection& projection, IN const model& model);
