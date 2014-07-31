project (multithread C CXX)
cmake_minimum_required (VERSION 3.0)

set(CMAKE_CXX_FLAGS "-std=c++11 -pthread -Os")

add_executable(multithread_basic main.cpp)
add_executable(client_server client.cpp server.cpp network_main.cpp)
add_executable(benchmark benchmark.cpp )
