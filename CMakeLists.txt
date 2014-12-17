cmake_minimum_required (VERSION 2.8)
include(CheckCXXCompilerFlag)

project (multithread C CXX)

CHECK_CXX_COMPILER_FLAG(-std=c++11 HAS_CXX14_FLAG)
CHECK_CXX_COMPILER_FLAG(-std=c++14 HAS_CXX14_FLAG)
CHECK_CXX_COMPILER_FLAG(-Os HAS_OSIZE_FLAG)
CHECK_CXX_COMPILER_FLAG(-O2 HAS_O2_FLAG)
CHECK_CXX_COMPILER_FLAG(-O3 HAS_O3_FLAG)
CHECK_CXX_COMPILER_FLAG(-Ofast HAS_OFAST_FLAG)
CHECK_CXX_COMPILER_FLAG(-flto HAS_FLTO_FLAG)
CHECK_CXX_COMPILER_FLAG(-Wall HAS_WALL)

if(HAS_CXX14_FLAG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
elseif(HAS_CXX11_FLAG)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

#if(HAS_OSIZE_FLAG)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os")
#endif()

#if(HAS_O2_FLAG)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
#endif()

if(HAS_O3_FLAG)
   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

#if(HAS_FLTO_FLAG)
#   set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto")
#endif()

#if(HAS_OFAST_FLAG)
#    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")
#endif()

if(HAS_WALL)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
endif()


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -flto")


add_executable(multithread_basic main.cpp)
add_executable(client_server client.cpp server.cpp network_main.cpp client.h server.h)
add_executable(benchmark benchmark_main.cpp bsearch.cpp benchmark_utils.cpp benchmark_utils.h bsearch.h)
