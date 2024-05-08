cmake_minimum_required(VERSION 3.10)
project(mgml)

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/event.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/log.cpp
)
add_executable(mgml ${SOURCE})

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET mgml PROPERTY CXX_STANDARD 20)
endif()
