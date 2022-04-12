cmake_minimum_required(VERSION 3.21)
project(SortAlgoCpp11)

set(CMAKE_CXX_STANDARD 11)

add_executable(BubbleSort BubbleSort.cpp SortHelper.cpp SortHelper.h)
add_executable(QuickSort QuickSort.cpp SortHelper.cpp SortHelper.h)
