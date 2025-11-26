#include <iostream>
#include <vector>
#include "MergeSort.h"

int main()
{
    // Utworzenie instancji klasy MergeSort dla typu int oraz double
    MergeSort<int> sorterInt;
    MergeSort<double> sorterDouble;

    // Tablica liczb całkowitych
    std::vector<int> arrInt = {5, 3, 8, 1, 2};

    // Tablica liczb zmiennoprzecinkowych
    std::vector<double> arrDouble = {3.14, 1.1, -2.7, 8.8, 0.0};

    // Sortowanie tablic
    sorterInt.sort(arrInt);
    sorterDouble.sort(arrDouble);

    // Wyświetlenie wyników
    std::cout << "Sorted int array: ";
    for (auto v : arrInt) std::cout << v << " ";
    std::cout << "\n";

    std::cout << "Sorted double array: ";
    for (auto v : arrDouble) std::cout << v << " ";
    std::cout << "\n";

    return 0;
}
