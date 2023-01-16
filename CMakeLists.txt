cmake_minimum_required(VERSION 3.9)

#find_program(CCACHE_PROGRAM ccache)
#if (${CCACHE_FOUND})
#  set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE})
#  set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE})
#endif()
#message(STATUS "CCACHE ${CCACHE_FOUND}")

if (NOT CMAKE_BUILD_TYPE)
  message (STATUS "No build type selected, default to Release")
  set (CMAKE_BUILD_TYPE "Release")
endif ()
#
#if(WIN32)
#  set(CMAKE_CXX_FLAGS "/O3 /pthread")
#elseif(APPLE)
#  set(CMAKE_CXX_FLAGS "-O3 -pthread")
#else()
#  set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -g -lprofiler -ltcmalloc -DMY_DEBUG")
#  set(CMAKE_CXX_FLAGS "-O3 -pthread")
#endif()

project(libquadtree CXX)


set(CMAKE_CXX_STANDARD 20)

find_package(pybind11 REQUIRED)
#find_package(Eigen3 REQUIRED)
file(GLOB all_SRCS ${CMAKE_CURRENT_SOURCE_DIR}/cpp/*)

#message(WARNING "${all_SRCS}")
pybind11_add_module(libquadtree ${all_SRCS})
set_target_properties(libquadtree PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED TRUE
        CXX_EXTENSIONS FALSE
        POSITION_INDEPENDENT_CODE ON
        C_VISIBILITY_PRESET hidden
        CXX_VISIBILITY_PRESET hidden
        INTERPROCEDURAL_OPTIMIZATION TRUE
        )
target_link_libraries(libquadtree)
