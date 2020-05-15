cmake_minimum_required(VERSION 3.15)
project(graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(graph main.cpp DenseGraph.h SparseGraph.h Helper.h ReadGraph.h Component.h Path.h ShortestPath.h)
