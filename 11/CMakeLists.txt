cmake_minimum_required (VERSION 2.6)

# Projektname
project(Collections3)

# Füge Source-Files hinzu
set(SRC_FILES program.cpp)
set(SRC_FILES duck.cpp ${SRC_FILES})

# Erzeuge Binary
add_executable(Collection3Test ${SRC_FILES})