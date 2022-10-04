cmake_minimum_required(VERSION 3.23)
project(2_removing_odds C)

set(CMAKE_C_STANDARD 23)

add_executable(2_removing_odds main.c)
target_link_libraries(2_removing_odds m)
