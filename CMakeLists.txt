cmake_minimum_required(VERSION 3.26)
project(.)

set(CMAKE_CXX_STANDARD 23)

add_executable(. main.cpp
        DataSpace.h
        MarketingPlace.h)
