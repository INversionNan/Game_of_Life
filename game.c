#include "main.h"

void show_map(SDL_Window *window, SDL_Surface *screenSurface){
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format,0xFF,0xFF,0xFF));
    SDL_UpdateWindowSurface(window);
}

void show_grid(SDL_Window *window, SDL_Surface *screenSurface, int a, int b){
    SDL_Rect array = {a,b,200,200};
    SDL_FillRect(screenSurface,&array, SDL_MapRGB(screenSurface->format, 0, 0, 0));
    SDL_UpdateWindowSurface(window);
}

void show_survive(SDL_Window *window, SDL_Surface *screenSurface, int c, int d){
    for(int i = 0; i < c + 1; ++i){
        SDL_Rect grid_1 = {i * 200,0 ,1, d * 200};
        SDL_FillRect(screenSurface,&grid_1, SDL_MapRGB(screenSurface->format, 138 , 43 , 226));
        SDL_UpdateWindowSurface(window);
    }
    for(int j = 0; j < d + 1; ++j){
        SDL_Rect grid_2 = {0, j * 200 , c * 200 , 1};
        SDL_FillRect(screenSurface,&grid_2, SDL_MapRGB(screenSurface->format, 138 , 43 , 226));
        SDL_UpdateWindowSurface(window);
    }
}

int cell_judge(int cell_survive,int neighbour_survive){
    if(cell_survive == 1){
        if(neighbour_survive > 3 || neighbour_survive <= 1){
            return 0;
        } else{
            return 1;
        }
    }else if(cell_survive == 0 && neighbour_survive == 3){
        return 1;
    }else return 0;
}//judge whether this cell survives or not; 0 is death, 1 is survival.

void cell_change(int Length, int Width, int Grid[Length][Width]){

    int NeighborNumber;
    for(int i = 0; i < Length; ++i){
        for (int j = 0; j < Width; ++j) {

        }
    }
}//change the cell in the map

void game(char *file, int iteration){
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;

    int Length;// Map length
    int Width;//Map width

    int **p_begin = (int **)malloc(sizeof (int *));
    int **p_next = (int **) malloc(sizeof (int *)*Length);
    int **p_cell = (int **) malloc(sizeof (int *)*Length);//Dynamically allocate the space of a two-dimensional array

    initGrid(&Length,&Width,file);// init the game of life
    window = SDL_window();// Get a window
    screenSurface = SDL_surface();// Get a screen surface
    show_survive(window, screenSurface, Length, Width);
    for(int i = 0; i < Length; ++i){
        p_next[i] = (int *) malloc(Length * sizeof (int) );
        memset(p_next[i],0,sizeof (p_next[i][0]));
    }
    for(int i = 0; i < Length; ++i){
        p_cell[i] = (int *) malloc(Length * sizeof (int) );
        memset(p_cell[i],0,sizeof (p_cell[i][0]));
    }
    while(1){
        if(iteration < 0){
            break;
        }
        show_map(window,screenSurface);

    }
    save(Length, Width, window, screenSurface,file);//save the result in the file
}// The game framework

