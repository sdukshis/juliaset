cmake_minimum_required(VERSION 3.8)

project(julia CXX)

add_executable(julia main.cpp netpbm.cpp)

target_compile_features(julia PUBLIC cxx_std_17)
