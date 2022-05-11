#include <iostream>

#include "object/BaseObject.hpp"
#include "object/Vector.hpp"

int main()
{
    Vector vec = {1, 2, 3, 0};

    vec += {2, 3, 4};

    std::cout << vec << std::endl;

    return 0;
}