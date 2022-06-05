cmake_minimum_required(VERSION 3.14)
project(testplugin)
find_package(fmt REQUIRED)
set(src
    main.cpp
    skill.h
    registry.h
    goto.h
)
add_executable(main ${src})
target_link_libraries(main fmt::fmt)
