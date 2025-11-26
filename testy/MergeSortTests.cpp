#include "gtest/gtest.h"
#include "MergeSort.h"

#include <vector>
#include <algorithm>
#include <random>

/*
    Test: Sortowanie tablicy już posortowanej.
    Algorytm nie powinien zmienić kolejności.
*/
TEST(MergeSortTests, AlreadySorted)
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    MergeSort<int> ms;
    ms.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1,2,3,4,5}));
}

/*
    Test: Tablica posortowana odwrotnie.
*/
TEST(MergeSortTests, ReverseSorted)
{
    std::vector<int> arr = {5,4,3,2,1};
    MergeSort<int> ms;
    ms.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1,2,3,4,5}));
}

/*
    Test: Losowa tablica.
*/
TEST(MergeSortTests, RandomNumbers)
{
    std::vector<int> arr = {10,-3,5,2,8};
    MergeSort<int> ms;
    ms.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-3,2,5,8,10}));
}

/*
    Test: Tylko liczby ujemne.
*/
TEST(MergeSortTests, OnlyNegativeNumbers)
{
    std::vector<int> arr = {-9,-2,-7,-1};
    MergeSort<int> ms;
    ms.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-9,-7,-2,-1}));
}

/*
    Test: Liczby ujemne i dodatnie.
*/
TEST(MergeSortTests, NegativeAndPositive)
{
    std::vector<int> arr = {-5,3,-1,2,0};
    MergeSort<int> ms;
    ms.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-5,-1,0,2,3}));
}

/*
    Test: Pusta tablica – nie powinno być wyjątku.
*/
TEST(MergeSortTests, EmptyArray)
{
    std::vector<double> arr;
    MergeSort<double> ms;
    EXPECT_NO_THROW(ms.sort(arr));
    EXPECT_TRUE(arr.empty());
}

/*
    Test: Tablica jednoelementowa.
*/
TEST(MergeSortTests, SingleElement)
{
    std::vector<int> arr = {42};
    MergeSort<int> ms;
    ms.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{42}));
}

/*
    Test: Tablica z duplikatami.
*/
TEST(MergeSortTests, Duplicates)
{
    std::vector<int> arr = {4,1,3,1,4};
    MergeSort<int> ms;
    ms.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1,1,3,4,4}));
}

/*
    Test: Ujemne liczby z duplikatami.
*/
TEST(MergeSortTests, NegativeWithDuplicates)
{
    std::vector<int> arr = {-2,-5,-2,-1};
    MergeSort<int> ms;
    ms.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-5,-2,-2,-1}));
}

/*
    Test: Mieszane liczby (ujemne, dodatnie, duplikaty).
*/
TEST(MergeSortTests, MixedValuesWithDuplicates)
{
    std::vector<int> arr = {-1,3,0,3,-1,2};
    MergeSort<int> ms;
    ms.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{-1,-1,0,2,3,3}));
}

/*
    Test: Tylko dwa elementy, już posortowane.
*/
TEST(MergeSortTests, TwoElementsSorted)
{
    std::vector<int> arr = {1,2};
    MergeSort<int> ms;
    ms.sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1,2}));
}

/*
    Test: Duża tablica (>100 elementów).
*/
TEST(MergeSortTests, LargeArray100)
{
    std::vector<int> arr;
    for (int i = 100; i >= 1; --i) arr.push_back(i);

    MergeSort<int> ms;
    ms.sort(arr);

    std::vector<int> expected;
    for (int i = 1; i <= 100; ++i) expected.push_back(i);

    EXPECT_EQ(arr, expected);
}

/*
    Test: Duża tablica z ujemnymi, dodatnimi i duplikatami.
*/
TEST(MergeSortTests, LargeArrayMixed100)
{
    std::vector<int> arr;

    // Wstaw zakres -50..50 dwa razy
    for (int i = -50; i <= 50; ++i) arr.push_back(i);
    for (int i = -50; i <= 50; ++i) arr.push_back(i);

    // Losowo wymieszaj tablicę – C++17 kompatybilne
    std::shuffle(arr.begin(), arr.end(),
                 std::mt19937(std::random_device{}()));

    MergeSort<int> ms;
    ms.sort(arr);

    // Oczekiwany wynik
    std::vector<int> expected;
    for (int i = -50; i <= 50; ++i) expected.push_back(i);
    for (int i = -50; i <= 50; ++i) expected.push_back(i);

    EXPECT_EQ(arr, expected);
}
