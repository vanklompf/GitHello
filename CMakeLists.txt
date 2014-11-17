cmake_minimum_required (VERSION 2.8.11)
include(CheckCXXCompilerFlag)

project (multithread C CXX)


CHECK_CXX_COMPILER_FLAG(-std=c++11 HAS_CXX11_FLAG)
CHECK_CXX_COMPILER_FLAG(-O3 HAS_O3_FLAG)
CHECK_CXX_COMPILER_FLAG(-Wall HAS_WALL)
CHECK_CXX_COMPILER_FLAG(-pthread HAS_PTHREAD)

if(HAS_CXX11_FLAG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

if(HAS_O3_FLAG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

if(HAS_WALL)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()

if(HAS_PTHREAD)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
endif()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")



add_executable(multithread_basic main.cpp)
add_executable(client_server client.cpp server.cpp network_main.cpp)
add_executable(benchmark benchmark.cpp )
