cmake_minimum_required(VERSION 3.10)
project(MergeSortProject)

set(CMAKE_CXX_STANDARD 17)

# Wymuś dynamiczny runtime /MDd dla MSVC
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")
endif()

# Foldery
include_directories(src)
include_directories(testy)

# GoogleTest
add_subdirectory(googletest)

# Aplikacja
add_executable(merge_sort_app
    src/main.cpp
    src/MergeSort.h
)

# Testy – MUSI być dodany MergeSort.h
add_executable(merge_sort_tests
    testy/MergeSortTests.cpp
    src/MergeSort.h
)

target_link_libraries(merge_sort_tests gtest gtest_main)
