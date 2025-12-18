cmake_minimum_required(VERSION 3.10)
project(MSH_M4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MSH_M4)

target_include_directories(MSH_M4
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/external
        src
)

target_sources(MSH_M4
    PRIVATE
        src/MSH_M4.cpp
        src/StateManager.cpp
        src/State.cpp
        src/ConcreteHistoryIterator.cpp
    
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include/MSH_M4.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/IState.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/IStateManager.h
)

include(CTest)
enable_testing()

