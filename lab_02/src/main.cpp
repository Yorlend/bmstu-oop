#include <iostream>
#include <vector>
#include "list/List.h"

int main()
{
    const List<int> list({1, 2, 3, 4, 5});
    std::cout << list << std::endl;

    std::vector<double> vect = {1, 2, 2, 5, 3, 6};
    List<double> dblLst(vect.begin(), vect.end());
    dblLst[2] = 10.2;
    std::cout << dblLst << std::endl;

    dblLst.remove(1, 2);
    std::cout << dblLst << std::endl;

    return 0;
}
