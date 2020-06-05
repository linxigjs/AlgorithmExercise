cmake_minimum_required(VERSION 3.9)
project(AlgorithmExercise)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread" )

add_executable(OneProducerOneConsumer OneProducerOneConsumer.cpp repository.h)

add_executable(OneProducerManyConsumers OneProducerManyConsumers.cpp repository.h)

add_executable(ManyProducersOneConsumer ManyProducersOneConsumer.cpp repository.h)

