cmake_minimum_required(VERSION 3.15)
project(TP5)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(TP5 main.cpp shape.h source.cpp)
target_link_libraries(TP5 ${CONAN_LIBS})
