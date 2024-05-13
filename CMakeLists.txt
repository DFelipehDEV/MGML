cmake_minimum_required(VERSION 3.10)
project(mgml)

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/event.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/log.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/transpiler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/language.cpp
)
add_executable(mgml ${SOURCE})
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug)
endif()

file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/examples" DESTINATION "${CMAKE_BINARY_DIR}/examples/${CMAKE_BUILD_TYPE}")

if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET mgml PROPERTY CXX_STANDARD 20)
endif()
