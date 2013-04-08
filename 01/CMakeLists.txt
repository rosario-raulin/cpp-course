cmake_minimum_required (VERSION 2.6)
project (task1)

set (SRC_DIR src/main.cpp)
set (SRC_DIR src/Adventure.cpp ${SRC_DIR})

add_executable (task1 ${SRC_DIR})

