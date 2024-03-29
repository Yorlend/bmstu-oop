#pragma once

#include <cstdio>
#include "core/utils/model/model.hpp"

struct load_params
{
    const char* filename;
};

int load_model(VAR model& model, IN load_params params);
