cmake_minimum_required(VERSION 3.10)
project(EXGML)

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/event.cpp
)
add_executable(EXGML ${SOURCE})

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET EXGML PROPERTY CXX_STANDARD 20)
endif()
