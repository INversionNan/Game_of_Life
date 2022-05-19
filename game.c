#include "main.h"
//#include "game.h"

int **p_next;
int **p_begin;
int **p_cell;

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

void cell_change(int Length, int Width){
//    int NeighborNumber;
//    for(int i = 0; i < Length; ++i){
//        for (int j = 0; j < Width; ++j) {
//
//        }
//    }
    p_next[0][0] = cell_judge(p_begin[0][0],
                              p_begin[0][1] + p_begin[1][1] + p_begin[1][0]);
    p_next[0][Width - 1] = cell_judge(p_begin[0][Width - 1],
                                      p_begin[0][Width - 2] + p_begin[1][Width - 1]+p_begin[1][Width - 2]);
    p_next[Length - 1][0] = cell_judge(p_next[Length-1][0],
                                       p_begin[Length-2][1] + p_begin[Length - 1][1]+p_begin[Length-2][0]);
    p_next[Length - 1][Width - 1] = cell_judge(p_next[Length - 1][Width - 1],
                                               p_begin[Length - 2][Width - 1] +p_begin[Length - 1][Width - 2] + p_begin[Length - 2][Width - 2]);

    for(int i = 1; i < Length - 1; ++i){
        p_next[i][0] = cell_judge(p_next[i][0],p_next[i - 1][0] + p_next[i + 1][0] + p_next[i][1]+p_next[i + 1][1]);
    }
    for(int j = 1; j < Width - 1; ++j){
        p_next[0][j] = cell_judge(p_next[0][j],p_next[0][j + 1] +p_next[0][j - 1]+p_next[1][j + 1]+p_next[0][j]);
    }
}//change the cell in the map

void interface(){
    printf("Please enter your choice\n");
    printf("1)Initialize the map by modifying the file\n");
    printf("2)Initialize the map by mouse click\n");
    printf("3)Quit\n");
    printf("Option:");
    // user choice interface
}

void end(){
    printf("Game is over!\n");
    exit(0);
}

void user_choice(char *file, int iteration){
    char a = '1';
    while(a != '3'){
        while (1){
            interface();
            int count = 0;
            scanf("%c",&a);
            while(getchar()!='\n') count ++;
            if(count > 0){
                printf("\nSorry, the option you enter was invalid, please try again.\n\n");
                continue;
            }else{
                break;
            }
        }
        switch (a) {
            case '1':game_file(file,iteration); break;// modify file mode
            case '2':game_click(file,iteration); break;//mouse click mode
            case '3':
                exit(0);break;//exit program
            default:
                printf("\nSorry, the option you enter was invalid, please try again.\n");
                break;
        }
    }
}

void game_file(char *file, int iteration){
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;

    int Length;// Map length
    int Width;//Map width
    char line[200];

    p_begin = (int **)malloc(sizeof (int *));
    p_next = (int **) malloc(sizeof (int *)*Length);
    p_cell = (int **) malloc(sizeof (int *)*Length);//Dynamically allocate the space of a two-dimensional array

    initGrid(&Length,&Width,file);
    window = SDL_window(Length, Width);// Get a window
    screenSurface = SDL_surface(window);// Get a screen surface
    //if(initGrid(&Length,&Width,file) == -1){
    //printf("");
    //}// init the game of life
    printf("11111111111\n");
    for(int j = 0; j < Width; ++j){
//        printf("%s\n",read);
        fgets(line,150,stdin);
        p_begin[j] = (int *) malloc(sizeof (int)*(Length));
        for(int i = 0 ; i < Length && (line[i] != '\r' && line[i] !='\n'); ++i){
            //printf("%c\n",read[i]);
            if(line[i] == '0' || line[i] == '1'){
                p_begin[j][i] = line[i] - '0';
                //printf("%d\n",p_begin[j][i]);
            }else{
                printf("Your input is wrong. Please input 1 on behalf of survive, 0 on behalf of death.\n");
                break;
            }
            if(p_begin[j][i] == 1){
                //printf("111111\n");
                show_grid(window, screenSurface, 200 * i, 200 * j);
            } else{
                continue;
            }
        }
    }
    printf("11111111111\n");
    show_survive(window, screenSurface, Length, Width);
    printf("11111111111\n");
    bool success = true;

    SDL_event(success);

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
        cell_change(Length,Width);
        save(Length, Width, file, window, screenSurface);
        SDL_event(success);
//        if(game_over(Length,Width)){
//            break;
//        } else{
//
//        }
    }
    save(Length, Width, window, screenSurface,file);//save the result in the file
    SDL_quit(window);
}// The game framework

void game_click(char *file, int iteration){
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;

    int Length;// Map length
    int Width;//Map width

    int **p_begin = (int **)malloc(sizeof (int *));
    int **p_next = (int **) malloc(sizeof (int *)*Length);
    int **p_cell = (int **) malloc(sizeof (int *)*Length);//Dynamically allocate the space of a two-dimensional array

    initGrid(&Length,&Width,file);
    //if(initGrid(&Length,&Width,file) == -1){
        //printf("");
    //}// init the game of life
    window = SDL_window(Length, Width);// Get a window
    screenSurface = SDL_surface(window);// Get a screen surface
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
        //SDL_mouseevent(bool mouse_event);
        //game_over();
    }
    save(Length, Width, window, screenSurface,file);//save the result in the file
    SDL_quit(window);
}// The game framework

bool game_over(int Length, int Width,int iteration){
    int count_num;
//    for(int i = 0; i < Length; ++i){
//        for(int j = 0; j < Width; ++j){
//            p_cell[i][j] = p_begin[i][j];
//        }
//
//    }

    return false;
}
