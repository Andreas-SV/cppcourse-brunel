cmake_minimum_required (VERSION 2.6)
project (Neurons)

set(CMAKE_CXX_FLAGS "-std=c++11")

#enable_testing()
#add_subdirectory(gtest)
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable (Neurons Neuron.cpp Network.cpp main.cpp)
add_executable (Neurons_unittests Neuron.cpp Network.cpp Neurons_unittests.cpp)

target_link_libraries(Neurons_unittests gtest gtest_main)
add_test(Neurons_unittests Neurons_unittests)

