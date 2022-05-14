#include "main.h"
#define printERROR(text) printf("%s ERROR: %s\n",text, SDL_GetError())
SDL_Window SDL_window(){
    int Length;//Map length
    int Width;//Map width
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printERROR("Initialization failed");
    }else{
        window = SDL_CreateWindow("LifeGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Length*100, Width*100, SDL_WINDOW_SHOWN);
    }
    if(!window){
        printERROR("Window could not initialized");
        return -1;
    }
    scree = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format,0xFF,0xFF,0xFF));
    SDL_UpdateWindowSurface(window);
    return window;
}

SDL_Surface SDL_surface(){
    int Length;//Map length
    int Width;//Map width
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printERROR("Initialization failed");
    }else{
        window = SDL_CreateWindow("LifeGame", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Length*100, Width*100, SDL_WINDOW_SHOWN);
    }
    if(!window){
        printERROR("Window could not initialized");
        return -1;
    }
    scree = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format,0xFF,0xFF,0xFF));
    SDL_UpdateWindowSurface(window);
    return screenSurface;
}

void SDL_event(int choice){
    int num ;
    if(choice){
        while(1){
            SDL_Event event;//event
            if(SDL_WaitEvent(&event)){
                if(event.type == SDL_QUIT){
                    break;
                } else if(event.type == SDL_KEYDOWN){
                    if(event.key.keysym.sym == SDLK_ESCAPE){
                        break;
                    }
                }else if(event.type == SDL_KEYUP){

                }
            }
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            SDL_PumpEvents();
            if(state[SDL_SCANCODE_DOWN]){

            }
        }
    }
}

int SDL_quit(){
    SDL_DestroyWindow(window);
    SDL_Quit();
}
int main(int argc, char *argv[]) {
    int i, j, iteration;
    char file[1000];
    char empty[1000];
    if(argc > 1){
        int length_1 = strlen(argv[1]);
        if(length_1 < 4 || (argv[1][length_1 - 1]) != 't' || (argv[1][length_1 - 3]) != 't'|| (argv[1][length_1 - 2]) != 'x'|| (argv[1][length_1 - 4]) != '.'){
            do{
                printf("Wrong fiename! Please enter a file name ending in txt:");
                fgets(file, 200, stdin);
                for(i = strlen(file); file[i-1] == '\n' ||file[i-1] == '\r' ; i--){
                    file[i-1] = '\0';
                }
                while (fgets(empty,150,stdin));
            }
        }while(file[strlen(file) - 1] != 't' || file[strlen(file) - 2] != 'x' || file[strlen(file) - 3] != 't' || file[strlen(file) - 4] != '.' ||){

        };
    }else{
        strcpy(file,argv[1]);
    }
    if(argc > 2){
        int length_2 = strlen(argv[2]);

    }
    game(file,iteration);
    return 0;
}
