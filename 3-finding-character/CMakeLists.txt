cmake_minimum_required(VERSION 3.23)
project(3_finding_character C)

set(CMAKE_C_STANDARD 23)

add_executable(3_finding_character main.c)
target_link_libraries(3_finding_character m)
