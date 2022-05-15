//
// Created by 10526 on 2022/5/15.
//

#ifndef GAME_C_GAME_H
#define GAME_C_GAME_H

#include <stdbool.h>

#define LEFT 1
#define UP 1
#define RIGHT 2
#define DOWN 2

int dir;
bool success;
int **p_next;
int **p_begin;
int **p_cell;

#endif //GAME_C_GAME_H
