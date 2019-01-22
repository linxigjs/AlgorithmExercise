cmake_minimum_required(VERSION 3.9)
project(AlgorithmExercise)

set(CMAKE_CXX_STANDARD 11)

add_executable(LazyPrim main1.cpp Edge.h EdgeWeightedGraph.h LazyPrimMST.h)

add_executable(PrimMST main2.cpp Edge.h EdgeWeightedGraph.h PrimMST.h)

add_executable(KruskalMST main3.cpp Edge.h EdgeWeightedGraph.h KruskalMST.h UnionFind.h)
