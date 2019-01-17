cmake_minimum_required(VERSION 3.9)
project(AlgorithmExercise)

set(CMAKE_CXX_STANDARD 11)

add_executable(DirectedDFS main1.cpp Digraph.h DirectedDFS.h)

add_executable(DirectedCycle main2.cpp Digraph.h DirectedCycle.h)

add_executable(DepthFirstOrder main3.cpp Digraph.h DepthFirstOrder.h Topological.h)

add_executable(KosarajuSSC main4.cpp Digraph.h DepthFirstOrder.h KosarajuSSC.h)