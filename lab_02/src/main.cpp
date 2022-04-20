#include <iostream>
#include "list/List.h"

int main() {
    List<int> list({1, 2, 3, 4, 5});

    for (auto value : list)
        std::cout << value << std::endl;

    return 0;
}
