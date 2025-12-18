cmake_minimum_required(VERSION 3.10)
project(MSH_M4 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(MSH_M4)

add_library(EXTERNAL INTERFACE)

target_include_directories(EXTERNAL
    INTERFACE
        ${CMAKE_CURRENT_SOURCE_DIR}/external
)

target_include_directories(MSH_M4
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        EXTERNAL
    
    PRIVATE
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

