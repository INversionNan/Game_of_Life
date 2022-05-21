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

#define CLIP_MOUSEOVER 0;
#define CLIP_MOUSEOUT 1;
#define CLIP_MOUSEDOWN 2;
#define CLIP_MOUSEUP 3;
//const int CLIP_MOUSEOVER=0;
//const int CLIP_MOUSEOUT=1;
//const int CLIP_MOUSEDOWN=2;
//const int CLIP_MOUSEUP=3;

void read(int length, int width, char *filename);
void cell_copy(int Length, int Width,SDL_Window *window, SDL_Surface *screenSurface,char *filename);
void cell_init(int Length, int Width,SDL_Window *window, SDL_Surface *screenSurface,char *filename,int **p_grid, int a, int b);
bool gameover(int Length, int Width,int iteration,int num);

//extern int dir;
//extern bool success;
//extern int **p_next;
//extern int **p_begin;
//extern int **p_cell;

#endif //GAME_C_GAME_H
