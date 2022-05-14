//
// Created by 10526 on 2022/4/26.
//

#ifndef GAME_OF_LIFE_MAIN_H
#define GAME_OF_LIFE_MAIN_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <SDL2/SDL.h>

//int Length;
//int Width;

//SDL_Window *window;
//SDL_Surface *screen;

int cell_judge(int cell_survive,int neighbour_survive);
void game(char *file, int iteration);

void show_map(SDL_Window *window, SDL_Surface *screenSurface);
void show_grid(SDL_Window *window, SDL_Surface *screen, int c, int d);
void show_survive(SDL_Window *window, SDL_Surface *screen, int a, int b);

SDL_Window SDL_window();
SDL_Surface SDL_surface();
void SDL_event();
int SDL_quit();

int load_cell(FILE *file);
void initGrid(int *length, int *width, char *file);
void save(int length, int width, char *filename, SDL_Window *window, SDL_Surface *screen);
#endif //GAME_OF_LIFE_MAIN_H
