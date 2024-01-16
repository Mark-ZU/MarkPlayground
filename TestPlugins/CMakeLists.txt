cmake_minimum_required(VERSION 3.4)
project(testplugin LANGUAGES CXX)
find_package(fmt REQUIRED)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/scripts)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/scripts)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(ROCOS_MOD_DIR "rocos_mod/skills" CACHE STRING "Root dir of rocos_mod.")

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/CMakeLists.inc)
init_rocos_mod(${ROCOS_MOD_DIR} MOD_SRC)

#find_package(Python COMPONENTS Interpreter Development)
find_package(pybind11 CONFIG REQUIRED)
message("debug : " ${pybind11_FOUND} " " ${pybind11_VERSION})

set(src
    main.cpp
    skill.h
    registry.h
    ${MOD_SRC}
)
include_directories(
    ${pybind11_INCLUDE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
)
add_executable(main ${src})
target_link_libraries(main fmt::fmt)
add_library(pyrocos MODULE pyrocos.cpp)
set_target_properties(pyrocos PROPERTIES PREFIX "")
target_link_libraries(pyrocos PUBLIC pybind11::module fmt::fmt)
