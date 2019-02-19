cmake_minimum_required(VERSION 3.9)
project(AlgorithmExercise)

set(CMAKE_CXX_STANDARD 11)

file(GLOB_RECURSE APP_HEADER_FILES ./ "*.h*")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(EdgeWeightedDigraph main1.cpp DirectedEdge.h EdgeWeightedDigraph.h DijkstraSP.h)

add_executable(Topological main2.cpp Topological.h)

add_executable(AcycliSP main3.cpp Topological.h AcyclicSP.h)

add_executable(AcycliLP main4.cpp Topological.h AcyclicLP.h)

add_executable(ParallelTaskSchedule main5.cpp ParallelTaskSchedule.h)

add_executable(BellmanFordSP main6.cpp ${APP_HEADER_FILES})

add_executable(Shorter main7.cpp ${APP_HEADER_FILES})