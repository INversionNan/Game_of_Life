#include "main.h"
//#include "game.h"

int **p_next;
int **p_begin;
int **p_cell;

void show_map(SDL_Window *window, SDL_Surface *screenSurface){
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format,0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
}

void show_grid(SDL_Window *window, SDL_Surface *screenSurface, int a, int b){
    SDL_Rect array = {a,b,150,150};
    SDL_FillRect(screenSurface,&array, SDL_MapRGB(screenSurface->format, 218, 112, 214));
    SDL_UpdateWindowSurface(window);
}

void show_survive(SDL_Window *window, SDL_Surface *screenSurface, int c, int d){
    for(int i = 0; i < c + 1; ++i){
        SDL_Rect grid_1 = {i * 150,0 ,1, d * 150};
        SDL_FillRect(screenSurface,&grid_1, SDL_MapRGB(screenSurface->format, 138 , 43 , 226));
        SDL_UpdateWindowSurface(window);
    }
    for(int j = 0; j < d + 1; ++j){
        SDL_Rect grid_2 = {0, j * 150 , c * 150 , 1};
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

    for(int m = 1; m < Width - 1; ++m){
        for(int n = 1; n < Length - 1; ++n){
            p_next[m][n] = cell_judge(p_begin[m][n],p_begin[m - 1][n] + p_begin[m - 1][n - 1] + p_begin[m - 1][n + 1] + p_begin[m + 1][n] + p_begin[m + 1][n + 1] + p_begin[m + 1][n - 1] + p_begin[m][n + 1]+p_begin[m][n - 1]);
        }
    }
    //Edges
    for(int i = 1; i < Width - 1; ++i){
        p_next[0][i] = cell_judge(p_begin[0][i],p_begin[0][i + 1] +p_begin[0][i - 1]+p_begin[1][i + 1]+p_next[1][i - 1] + p_begin[1][i]);
        p_next[Width - 1][i] = cell_judge(p_begin[Width - 1][i],p_begin[Width - 2][i] + p_begin[Width - 1][i-1] + p_begin[Width - 1][i + 1] + p_begin[Width - 2][i - 1] + p_begin[Width - 2][i + 1]);
    }
    for(int j = 1; j < Length - 1; ++j){
        p_next[j][0] = cell_judge(p_begin[j][0],p_begin[j - 1][0] + p_begin[j + 1][0] + p_begin[j][1] + p_begin[j + 1][1] + p_begin[j - 1][1]);
        p_next[j][Length - 1] = cell_judge(p_begin[j][Length - 1],p_begin[j - 1][ Length - 1]+p_begin[j + 1][Length - 1] + p_begin[j][Length - 2] + p_begin[j - 1][Length - 2]+ p_begin[j + 1][Length - 2]);
    }

    //Corners
    p_next[0][0] = cell_judge(p_begin[0][0],
                              p_begin[0][1] + p_begin[1][1] + p_begin[1][0]);
    p_next[0][Width - 1] = cell_judge(p_begin[0][Width - 1],
                                      p_begin[0][Width - 2] + p_begin[1][Width - 1]+p_begin[1][Width - 2]);
    p_next[Length - 1][0] = cell_judge(p_begin[Length-1][0],
                                       p_begin[Length-2][1] + p_begin[Length - 1][1]+p_begin[Length-2][0]);
    p_next[Length - 1][Width - 1] = cell_judge(p_begin[Length - 1][Width - 1],
                                               p_begin[Length - 2][Width - 1] +p_begin[Length - 1][Width - 2] + p_begin[Length - 2][Width - 2]);

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
    //printf("11111111111\n");
    window = SDL_window(Length, Width);// Get a window
    //printf("11111111111\n");
    screenSurface = SDL_surface(window);// Get a screen surface
    //if(initGrid(&Length,&Width,file) == -1){
    //printf("");
    //}// init the game of life
    //printf("11111111111\n");
    FILE *filename = fopen(file,"r");
    rewind(filename);

    for(int i = 0; i < Width; ++i){
//        printf("%s\n",read);
        fgets(line,150, filename);
        p_begin[i] = (int *) malloc(sizeof (int)*(Length));
        //printf("%s",line);
        for(int j = 0 ; j < Length && (line[j] != '\r' && line[j] !='\n'); ++j){
            //printf("%c\n",line[i]);
            if(line[j] == '0' || line[j] == '1'){
                p_begin[i][j] = line[j] - '0';
                //printf("%d\n",p_begin[i][j]);
            }else{
                printf("Your input is wrong. Please input 1 on behalf of survive, 0 on behalf of death.\n");
                break;
            }
            //printf("%d\n",p_begin[i][j]);
            if(p_begin[i][j] == 1){
                //printf("111111\n");`
                show_grid(window, screenSurface, 150 * j, 150 * i);
            } else{
                continue;
            }
        }
    }
    //printf("11111111111\n");
    show_survive(window, screenSurface, Length, Width);
    //printf("11111111111\n");
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
