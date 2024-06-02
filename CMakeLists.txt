cmake_minimum_required(VERSION 3.10)

# Назва проекту
project(SP_136M_Automotive)

# Встановити стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(SOURCES
    SP_136M_Automotive/SP_136M_Automotive.cpp)

add_executable(SP_136M_Automotive ${SOURCES})

