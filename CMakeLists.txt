cmake_minimum_required(VERSION 3.9)
project(AlgorithmExercise)

set(CMAKE_CXX_STANDARD 11)

add_executable(EdgeWeightedDigraph main1.cpp DirectedEdge.h EdgeWeightedDigraph.h DijkstraSP.h)

add_executable(Topological main2.cpp Topological.h)

add_executable(AcycliSP main3.cpp Topological.h AcyclicSP.h)

add_executable(AcycliLP main4.cpp Topological.h AcyclicLP.h)
