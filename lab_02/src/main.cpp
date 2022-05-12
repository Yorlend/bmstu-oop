#include <iostream>
#include <vector>
#include <string>
#include "list/List.h"

int main()
{
    const List<int> list({1, 2, 3, 4, 5});
    std::cout << list << std::endl;

    std::vector<double> vect = {1, 2, 2, 5, 3, 6};
    List<double> dblLst(vect.begin(), vect.end());
    std::cout << dblLst << std::endl;

    int arr[] = {5, 9, 2, 11, 55};
    List<int> fromArray(arr, 5);

    std::cout << fromArray << std::endl;

    {
        auto iter = fromArray.begin();
        std::advance(iter, 3);

        fromArray.remove(iter);
    }

    std::cout << "From array: " << fromArray << std::endl;

    List<std::string> strLst;

    strLst.pushBack("abc");
    strLst.pushFront("aaa");

    std::cout << strLst << std::endl;

    try
    {
        for (size_t i = 0; i < 5; i++)
            strLst.popBack();
    }
    catch(const EmptyListException& e)
    {
        std::cerr << e.what() << '\n';
    }

    List<double> randLst = {5.2, 1.2, 4.3, 9.5, 2.3, 4.6};

    randLst.insert(randLst.begin(), 8.2);
    randLst.insert(randLst.end(), 9.99);

    double* doubleArr = randLst.toArray();

    for (size_t i = 0; i < randLst.size(); i++)
            std::cout << doubleArr[i] << " ";
    std::cout << std::endl;

    return 0;
}
