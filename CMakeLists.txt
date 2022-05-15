cmake_minimum_required(VERSION 3.21)
project(Game_of_Life C)

set(CMAKE_C_STANDARD 99)

add_executable(Game_of_Life main.c initial.c save.c main.h game.c lifegame.c game.h)
