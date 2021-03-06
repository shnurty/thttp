cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(PROJECT_BIN_DIR ${CMAKE_SOURCE_DIR}/bin)
set(PROJECT_CFG_DIR ${CMAKE_SOURCE_DIR}/conf)
set(PROJECT_GEN_DIR ${CMAKE_SOURCE_DIR}/build)
set(PROJECT_LIB_DIR ${CMAKE_SOURCE_DIR}/lib)
set(PROJECT_SRC_DIR ${CMAKE_SOURCE_DIR}/src)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_DIR})

project(thttp VERSION 0.0.1)
configure_file(${PROJECT_CFG_DIR}/const.h.in ${PROJECT_GEN_DIR}/const.h)
configure_file(${PROJECT_CFG_DIR}/version.h.in ${PROJECT_GEN_DIR}/version.h)

configure_file(${PROJECT_CFG_DIR}/thttp.conf.in ${PROJECT_BIN_DIR}/thttp.conf)

add_subdirectory(${PROJECT_SRC_DIR})
add_executable(thttp ${PROJECT_SRC_DIR}/main.cpp)

target_include_directories(thttp PUBLIC ${PROJECT_GEN_DIR} ${PROJECT_INCLUDE_PATHS} ${PROJECT_SRC_DIR})
target_link_libraries(thttp PUBLIC ${PROJECT_LIBRARIES})

