#include "main.h"
#include "game.h"

#define printERROR(text) printf("%s ERROR: %s\n",text, SDL_GetError())

int choice_num = 1;
int dir;
bool success;

SDL_Window *SDL_window(int length, int width){
    int Length = 0;//Map length
    int Width = 0;//Map width
    Length = length;
    Width = width;
    int m,n;
    int value = 150;
    if(Length > 8 || Width > 5){
        if(Width > 5){
            for(m = value; m > 0 ;m--){
                if(m * Width > 700 && m * Width < 800){
                    break;
                }
            }
        }else{
            m = value;
        }
        if(Length > 8){
            for (n = value; n > 0; --n) {
                if(n * Length > 1200 && n * Length < 1300){
                    break;
                }
            }
        }else{
            n = value;
        }
        if(m < n){
            value = m;
        }else{
            value = n;
        }
    }
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;
//    printf("000000000\n");
    //if (SDL_Init(SDL_INIT_EVERYTHING) == -1) { return -1; }
    //printf("11111111111\n");
    if((SDL_Init( SDL_INIT_VIDEO )) <0){
        //printf("999999\n");
        //printf("Initialization failed SDL_Error: %s\n",SDL_GetError());
        printERROR("Initialization failed");
        exit(0);
    }else{
        //printf("2222222222n");
        window = SDL_CreateWindow("Game of Life", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, Length*value, Width*value, SDL_WINDOW_SHOWN);
    }
//    printf("2222222222222\n");
    if(!window){
        printERROR("Window could not initialized");
        //printf("Window could not initialized! SDL_Error: %s\n",SDL_GetError());
        return NULL;
    }
//    printf("33333333333\n");
    screenSurface = SDL_GetWindowSurface(window);
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format,0xFF,0xFF,0xFF));
    SDL_UpdateWindowSurface(window);
    return window;
}//get a window

SDL_Surface *SDL_surface(SDL_Window *window){
    int Length = 0;//Map length
    int Width = 0;//Map width
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
                while(success){
                    const Uint8 *state_1 = SDL_GetKeyboardState(NULL);
                    SDL_PumpEvents();
                    if(state_1[SDL_SCANCODE_UP] || state_1[SDL_SCANCODE_LEFT]){
                        continue;
                    }else{
                        break;
                    }
                }
                break;//Up and Left
            } else if(state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_RIGHT]){
                dir = RIGHT;
                success = true;
                while(success){
                    const Uint8 *state_2 = SDL_GetKeyboardState(NULL);
                    SDL_PumpEvents();
                    if(state_2[SDL_SCANCODE_DOWN] || state_2[SDL_SCANCODE_RIGHT]){
                        continue;
                    }else{
                        break;
                    }
                }
                break;//Down and Right
            }else if(state[SDL_SCANCODE_ESCAPE]){
                success = false;
                SDL_Quit();
                exit(0);//Exit and quit
            }
            //printf("11111111111\n");
        }
        success = false;
    }else{
        int delay = 1500;
//        bool keyevent = true;
//        SDL_Event event;
//        while(keyevent) {
//            while (SDL_PollEvent(&event)) {
//                if (SDL_KEYDOWN == event.type) // SDL_KEYUP
//                {
//                    if (SDLK_DOWN == event.key.keysym.sym) {
//                        if(delay > 0){
//                            delay -= 100;
//                        }
//                        keyevent = false;
//                        break;
//                    } else if (SDLK_UP == event.key.keysym.sym) {
//                        delay += 100;
//                        keyevent = false;
//                        break;
//                    }else if (SDLK_SPACE == event.key.keysym.sym) {
//                        pause();
//                        keyevent = false;
//                        break;
//                    } else if (SDLK_ESCAPE == event.key.keysym.sym) {
//                        keyevent = false;
//                        SDL_Quit();
//                        exit(0);
//                        break;
//                    }
//                }
//            }
//        }
//        printf("%d",delay);
        SDL_Delay( delay ); // time between frames (ms)
    }
    //return;
}// key event one

void SDL_keyevent(bool keyboard_event){
    SDL_Event ev;
    int delay = 1500;
    while(keyboard_event) {
        while (SDL_PollEvent(&ev)) {
            if (SDL_KEYDOWN == ev.type) // SDL_KEYUP
            {
                if (SDLK_DOWN == ev.key.keysym.sym) {
                    if(delay > 0){
                        delay -= 100;
                    }
                    keyboard_event = false;
                    break;
                } else if (SDLK_UP == ev.key.keysym.sym) {
                    if(delay > 0){
                        delay += 100;
                    }
                    keyboard_event = false;
                    break;
                } else if (SDLK_LEFT == ev.key.keysym.sym) {
                    if(delay > 0){
                        delay -= 100;
                    }
                    keyboard_event = false;
                    break;
                } else if (SDLK_RIGHT == ev.key.keysym.sym) {
                    if(delay > 0){
                        delay += 100;
                    }
                    keyboard_event = false;
                    break;
                } else if (SDLK_SPACE == ev.key.keysym.sym) {
                    pause();
                    keyboard_event = false;
                    break;
                } else if (SDLK_ESCAPE == ev.key.keysym.sym) {
                    keyboard_event = false;
                    SDL_Quit();
                    exit(0);
                    break;
                }
            }
        }
    }
}//Key event two

int SDL_mouseevent(bool mouse_event,void *opaque, int *length, int *width,int **p_init,int Length, int Width,SDL_Window *window, SDL_Surface *screenSurface,char *file){
    int m,n;
    int value = 150;
    if(Length > 8 || Width > 5){
        if(Width > 5){
            for(m = value; m > 0 ;m--){
                if(m * Width > 700 && m * Width < 800){
                    break;
                }
            }
        }else{
            m = value;
        }
        if(Length > 8){
            for (n = value; n > 0; --n) {
                if(n * Length > 1200 && n * Length < 1300){
                    break;
                }
            }
        }else{
            n = value;
        }
        if(m < n){
            value = m;
        }else{
            value = n;
        }
    }
    SDL_Event ev;
    int quit = 0;
    //while (!quit)
    while(mouse_event){
        while (SDL_PollEvent(&ev))
        {
            if (SDL_KEYDOWN == ev.type) // SDL_KEYUP
            {
                if (SDLK_DOWN == ev.key.keysym.sym)
                {
                    cell_change(Length,Width);
                    printf("Cell evolution generation ...............\n");
                    mouse_event = false;
                    break;
                }else if (SDLK_UP == ev.key.keysym.sym){
                    cell_change(Length,Width);
                    printf("Cell evolution generation ...............\n");
                    mouse_event = false;
                    break;
                }else if (SDLK_LEFT == ev.key.keysym.sym){
                    cell_change(Length,Width);
                    printf("Cell evolution generation ...............\n");
                    mouse_event = false;
                    break;
                }else if (SDLK_RIGHT == ev.key.keysym.sym){
                    cell_change(Length,Width);
                    printf("Cell evolution generation ...............\n");
                    mouse_event = false;
                    break;
                }else if(SDLK_SPACE == ev.key.keysym.sym){
                    cell_change(Length,Width);
                    printf("Cell evolution generation ...............");
                    mouse_event = false;
                    break;
                }
                else if(SDLK_ESCAPE == ev.key.keysym.sym){
                    mouse_event = false;
                    SDL_Quit();
                    exit(0);
                    break;
                }
            }else if (SDL_MOUSEBUTTONDOWN == ev.type){
                if(SDL_BUTTON_LEFT == ev.button.button)
                {
                    int px = ev.button.x;
                    int py = ev.button.y;
                    *width = px/value;
                    *length = py/value;
                    if(p_init[*length][*width] == 0){
                        p_init[*length][*width] = 1;
                        printf("Position(%d, %d) will be survive...............\n", *length, *width);
                    } else{
                        p_init[*length][*width] = 0;
                        printf("Position(%d, %d) will be dead...............\n", *length, *width);
                    }
                    cell_init(Length,Width,window,screenSurface,file,p_init,*length,*width);
                }
                else if(SDL_BUTTON_RIGHT == ev.button.button)
                {
                    int px = ev.button.x;
                    int py = ev.button.y;
                    *width = px/value;
                    *length = py/value;
                    if(p_init[*length][*width] == 0){
                        p_init[*length][*width] = 1;
                        printf("Position(%d, %d) will be survive...............\n", *length, *width);
                    } else{
                        p_init[*length][*width] = 0;
                        printf("Position(%d, %d) will be dead...............\n", *length, *width);
                    }
                    cell_init(Length,Width,window,screenSurface,file,p_init,*length,*width);
                }
            }
            else if (SDL_MOUSEMOTION == ev.type)
            {
                int px = ev.motion.x;
                int py = ev.motion.y;
                *width = px/value;
                *length = py/value;
                printf("Position(%d, %d) ...............\n", *length, *width);
            }
//            else if(SDL_MOUSEWHEEL == ev.type){
//                if(ev.wheel.y > 0){
//
//                }
//                if(ev.wheel.y < 0){
//
//                }
//            }
            else if (SDL_QUIT == ev.type)
            {
                printf("SDL_QUIT ...............\n");
                return 0;
            }
        }
    }
    return 0;
}// Mouse click and motion event

void SDL_quit(SDL_Window *window){
//    printf("111111111\n");
    SDL_DestroyWindow(window);
//    printf("222222222\n");
//    SDL_Quit();
}//Destroy the window
