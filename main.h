//
// Created by 10526 on 2022/4/26.
//

#ifndef GAME_OF_LIFE_MAIN_H
#define GAME_OF_LIFE_MAIN_H
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

//int Length;
//int Width;
//int choice = 1;
//int dir;
//bool success;

//SDL_Window *window;
//SDL_Surface *screen;

//const int row;
//int col;
//int Map[row][col];

int cell_judge(int cell_survive,int neighbour_survive);
void cell_change(int Length, int Width);
void interface();
void end();
void choice();
void user_choice(char *file, int iteration);
void game_file(char *file, int iteration);
void game_click(char *file, int iteration);
void game_way(char *file, int iteration);
void game_auto(char *file, int iteration);
bool game_over(int Length, int Width,int iteration,int num);


void show_map(SDL_Window *window, SDL_Surface *screenSurface);
void show_grid(SDL_Window *window, SDL_Surface *screen, int c, int d);
void show_survive(SDL_Window *window, SDL_Surface *screen, int a, int b);
void show_dead(SDL_Window *window, SDL_Surface *screenSurface, int a, int b);

SDL_Window *SDL_window(int length, int width);
SDL_Surface *SDL_surface(SDL_Window *window);
void SDL_event(bool keyboard_event);
int SDL_mouseevent(bool mouse_event,void *opaque, int *length, int *width,int **p_init,int Length, int Width,SDL_Window *window, SDL_Surface *screenSurface,char *file);
void SDL_quit(SDL_Window *window);

int load_cell(FILE *file, int length, int width);
void initGrid(int *length, int *width, char *file);
void initMap(int Length, int Width,int **Map);
void save(int length, int width, char *filename, SDL_Window *window, SDL_Surface *screen, int **p_cell);
#endif //GAME_OF_LIFE_MAIN_H
