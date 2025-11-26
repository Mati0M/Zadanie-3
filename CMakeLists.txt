cmake_minimum_required(VERSION 3.10)
project(MergeSortProject)

set(CMAKE_CXX_STANDARD 17)

# ========================
# Dodanie źródeł programu
# ========================
add_executable(merge_sort_app
    src/main.cpp
)

# ========================
# Dodanie testów GoogleTest
# ========================
add_subdirectory(googletest)

include_directories(
    googletest/googletest/include
    src
)

add_executable(merge_sort_tests
    tests/MergeSortTests.cpp
)

target_link_libraries(merge_sort_tests
    gtest
    gtest_main
)
