#include "main.h"
#include "game.h"

#define printERROR(text) printf("%s ERROR: %s\n",text, SDL_GetError())

int choice = 1;
int dir;
bool success;

SDL_Window *SDL_window(int length, int width){
    int Length;//Map length
    int Width;//Map width
    Length = length;
    Width = width;
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printERROR("Initialization failed");
    }else{
        window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Length*150, Width*150, SDL_WINDOW_SHOWN);
    }
    if(!window){
        printERROR("Window could not initialized");
        return NULL;
    }
    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format,0xFF,0xFF,0xFF));
    SDL_UpdateWindowSurface(window);
    return window;
}//get a window

SDL_Surface *SDL_surface(SDL_Window *window){
    int Length;//Map length
    int Width;//Map width
//    Length = length;
//    Width = width;
//    SDL_Window *window = NULL;
//    SDL_Surface *screenSurface = NULL;
//    if(SDL_Init(SDL_INIT_VIDEO) < 0){
//        printERROR("Initialization failed");
//    }else{
//        window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Length*200, Width*200, SDL_WINDOW_SHOWN);
//    }
//    if(!window){
//        printERROR("Window could not initialized");
//        return NULL;
//    }
    SDL_Surface *screenSurface = NULL;
    screenSurface = SDL_GetWindowSurface(window);
//    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format,0xFF,0xFF,0xFF));
    SDL_UpdateWindowSurface(window);
    return screenSurface;
}//get a screen surface

SDL_Renderer *SDL_renderer(){
    SDL_Renderer *renderer = NULL;
    return  renderer;
}//get a renderer

void SDL_event(bool keyboard_event){
    int num ;
    if(keyboard_event){
        while(keyboard_event){
            SDL_Event event;//event
//            if(SDL_WaitEvent(&event)){
//                if(event.type == SDL_QUIT){
//                    break;
//                } else if(event.type == SDL_KEYDOWN){
//                    if(event.key.keysym.sym == SDLK_ESCAPE){
//                        break;
//                    }
//                }else if(event.type == SDL_KEYUP){
//
//                }
//            }
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            SDL_PumpEvents();
            if(state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_LEFT]){
                dir = LEFT;
                success = true;
            } else if(state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_RIGHT]){
                dir = RIGHT;
                success = true;
            }else if(state[SDL_SCANCODE_ESCAPE]){
                success = false;
                exit(0);
            }
        }
    }else{
        int delay = 200;
        SDL_Delay( delay ); // time between frames (ms)
    }
    //return;
}

void SDL_mouseevent(bool mouse_event){
    int num ;
    if(mouse_event){
        while(mouse_event){
            SDL_Event event;//event
//            if(SDL_WaitEvent(&event)){
//                if(event.type == SDL_QUIT){
//                    break;
//                } else if(event.type == SDL_KEYDOWN){
//                    if(event.key.keysym.sym == SDLK_ESCAPE){
//                        break;
//                    }
//                }else if(event.type == SDL_KEYUP){
//
//                }
//            }
            const Uint8 *state = SDL_GetKeyboardState(NULL);
            SDL_PumpEvents();
            if(state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_LEFT]){
                dir = LEFT;
                success = true;
            } else if(state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_RIGHT]){
                dir = RIGHT;
                success = true;
            }else if(state[SDL_SCANCODE_ESCAPE]){
                success = false;
                exit(0);
            }
        }
    }else{
        int delay = 200;
        SDL_Delay( delay ); // time between frames (ms)
    }
}

void SDL_quit(SDL_Window *window){
    SDL_DestroyWindow(window);
    SDL_Quit();
}
int main(int argc, char *argv[]) {
//    int i, j, k, iteration;
//    char file[1000];
//    char empty[1000];
//    if(argc > 1){
//        int length_1 = strlen(argv[1]);
//        if(length_1 < 4 || (argv[1][length_1 - 1]) != 't' || (argv[1][length_1 - 3]) != 't'|| (argv[1][length_1 - 2]) != 'x'|| (argv[1][length_1 - 4]) != '.'){
//            do{
//                printf("Wrong fiename! Please enter a file name ending in txt:");
//                fgets(file, 200, stdin);
//                for(i = strlen(file); file[i-1] == '\n' ||file[i-1] == '\r' ; i--){
//                    file[i-1] = '\0';
//                }
//                while (fgets(empty,150,stdin));
//            }while(file[strlen(file) - 1] != 't' || file[strlen(file) - 2] != 'x' || file[strlen(file) - 3] != 't' || file[strlen(file) - 4] != '.');
//        }else{
//            strcpy(file,argv[1]);
//        }
//    }
//    if(argc > 2){
//        int length_2 = strlen(argv[2]);
//        for(j = 0; j < length_2; ++j){
//            if(argv[2][i] < '0' || argv[2][i] > '9'){
//                break;
//            }
//        }
//        if(j == length_2){
//            iteration = atoi(argv[2]);
//        } else{
//            while(1){
//                printf("Wrong iteration number! Please enter a correct number:");
//                fgets(empty,150,stdin);
//                for(j = strlen(empty); empty[j - 1] == '\n' || empty[j - 1] == '\r'; j--){
//                    empty[j - 1] = '\0';
//                }
//                for (k = 0; k < strlen(empty); ++k) {
//                    if(empty[k] < '0' || empty[k] > '9'){
//                        break;
//                    }
//                }
//                if(k == strlen(empty)){
//                    iteration = atoi(empty);
//                    while (fgets(empty,150, stdin));
//                    break;
//                }
//                while (fgets(empty,150,stdin));
//            }
//        }
//    }
    char *file = "game.txt";
    int iteration = 5;
    user_choice(file,iteration);

    return 0;
}