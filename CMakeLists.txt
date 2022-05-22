cmake_minimum_required(VERSION 3.21)
project(Game_of_Life)

set(CMAKE_C_STANDARD 99)

LINK_LIBRARIES(SDL2)

add_executable(Game_of_Life main.c initial.c save.c game.c sdl.c Daoqi.c)
