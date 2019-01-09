cmake_minimum_required(VERSION 3.9)
project(AlgorithmExercise)

set(CMAKE_CXX_STANDARD 11)

add_executable(DepthFirstSearch main1.cpp Graph.h DepthFirstSearch.h)

add_executable(DepthFirstPaths main2.cpp Graph.h DepthFirstPaths.h)

add_executable(BreadthFirstPaths main3.cpp Graph.h BreadthFirstPaths.h)

add_executable(CC main4.cpp Graph.h ConnectedComponent.h)

add_executable(Cycle main5.cpp Graph.h Cycle.h)
