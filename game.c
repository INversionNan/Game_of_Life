#include "main.h"
#include "game.h"

int **p_next;
int **p_begin;
int **p_cell;

void freeAll(){
    free(p_begin);
    free(p_next);
    //free(p_cell);
}//free the pointer all functions used

void show_map(SDL_Window *window, SDL_Surface *screenSurface){
    SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format,0xFF, 0xFF, 0xFF));
    SDL_UpdateWindowSurface(window);
}//Show the map

void show_grid(SDL_Window *window, SDL_Surface *screenSurface, int a, int b,int Length, int Width){
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
    SDL_Rect array = {a,b,value,value};
    SDL_FillRect(screenSurface,&array, SDL_MapRGB(screenSurface->format, 218, 112, 214));
    SDL_UpdateWindowSurface(window);
}//Show the background and survive cell

void show_dead(SDL_Window *window, SDL_Surface *screenSurface, int a, int b,int Length, int Width){
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
    SDL_Rect array = {a,b,value,value};
    SDL_FillRect(screenSurface,&array, SDL_MapRGB(screenSurface->format, 255, 255, 255));
    SDL_UpdateWindowSurface(window);
}//Show the background and survive cell

void show_survive(SDL_Window *window, SDL_Surface *screenSurface, int c, int d,int Length, int Width){
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
    for(int i = 0; i < c + 1; ++i){
        SDL_Rect grid_1 = {i * value,0 ,1, d * value};
        SDL_FillRect(screenSurface,&grid_1, SDL_MapRGB(screenSurface->format, 138 , 43 , 226));
        SDL_UpdateWindowSurface(window);
    }
    for(int j = 0; j < d + 1; ++j){
        SDL_Rect grid_2 = {0, j * value , c * value , 1};
        SDL_FillRect(screenSurface,&grid_2, SDL_MapRGB(screenSurface->format, 138 , 43 , 226));
        SDL_UpdateWindowSurface(window);
    }
}//Show the line and grid pattern



void cell_change(int Length, int Width){
//    int NeighborNumber;
//    for(int i = 0; i < Length; ++i){
//        for (int j = 0; j < Width; ++j) {
//
//        }
//    }
    //The normal condition in the middle of map
    for(int m = 1; m < Width - 1; ++m){
        for(int n = 1; n < Length - 1; ++n){
            p_next[m][n] = cell_judge(p_begin[m][n],
                                      p_begin[m - 1][n] + p_begin[m - 1][n - 1] + p_begin[m - 1][n + 1]+
                                      p_begin[m + 1][n] + p_begin[m + 1][n + 1] + p_begin[m + 1][n - 1]+
                                      p_begin[m][n + 1]+p_begin[m][n - 1]);
        }
    }

    //Edges
    for(int i = 1; i < Length - 1; ++i){
        p_next[0][i] = cell_judge(p_begin[0][i],p_begin[0][i + 1] +p_begin[0][i - 1]+
                                                p_begin[1][i + 1]+p_begin[1][i - 1] + p_begin[1][i]);
        p_next[Width - 1][i] = cell_judge(p_begin[Width - 1][i],p_begin[Width - 2][i] +
                                                                p_begin[Width - 1][i-1] + p_begin[Width - 1][i + 1] + p_begin[Width - 2][i - 1] + p_begin[Width - 2][i + 1]);
    }
    for(int j = 1; j < Width - 1; ++j){
        p_next[j][0] = cell_judge(p_begin[j][0],p_begin[j - 1][0] + p_begin[j + 1][0] +
                                                p_begin[j][1] + p_begin[j + 1][1] + p_begin[j - 1][1]);
        p_next[j][Length - 1] = cell_judge(p_begin[j][Length - 1],p_begin[j - 1][ Length - 1]+
                                                                  p_begin[j + 1][Length - 1] + p_begin[j][Length - 2] + p_begin[j - 1][Length - 2]+ p_begin[j + 1][Length - 2]);
    }

    //Corners
    p_next[0][0] = cell_judge(p_begin[0][0],
                              p_begin[0][1] + p_begin[1][1] + p_begin[1][0]);
    p_next[0][Length - 1] = cell_judge(p_begin[0][Length - 1],
                                       p_begin[0][Length - 2] + p_begin[1][Length - 1]+p_begin[1][Length - 2]);
    p_next[Width - 1][0] = cell_judge(p_begin[Width - 1][0],
                                      p_begin[Width - 2][1] + p_begin[Width - 1][1]+p_begin[Width - 2][0]);
    p_next[Width - 1][Length - 1] = cell_judge(p_begin[Width - 1][Length - 1],
                                               p_begin[Width - 2][Length - 1] +p_begin[Width - 1][Length - 2] + p_begin[Width - 2][Length - 2]);
}//change the cell in the map

void cell_init(int Length, int Width,SDL_Window *window, SDL_Surface *screenSurface,char *filename,int **p_grid, int a, int b){
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
    FILE *file = fopen(filename,"w+");
    for(int i = 0; i < Width; ++i){
        for (int j = 0; j < Length; ++j) {
            fprintf(file,"%d",p_grid[i][j]);
            p_cell[i][j] = p_grid[i][j];
//            if(p_grid[i][j] == 1){
//                show_grid(window, screenSurface, 150 * j, 150 * i);
//                show_survive(window, screenSurface, Length, Width);
//            }else{
//                show_dead(window, screenSurface, 150 * j, 150 * i);
//                show_survive(window, screenSurface, Length, Width);
//            }
        }
        fprintf(file,"\n");
        memset(p_next[i],0,sizeof (p_next[i]));
    }
    if(p_grid[a][b] == 1){
        show_grid(window, screenSurface, value * b, value * a,Length,Width);
        show_survive(window, screenSurface, Length, Width,Length,Width);
    }else{
        show_dead(window, screenSurface, value * b, value * a,Length,Width);
        show_survive(window, screenSurface, Length, Width,Length,Width);
    }
    fclose(file);
}// init the cell map

void cell_copy(int Length, int Width,SDL_Window *window, SDL_Surface *screenSurface,char *filename){
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
    FILE *file = fopen(filename,"w+");
    for(int i = 0; i < Width; ++i){
        for (int j = 0; j < Length; ++j) {
            fprintf(file,"%d",p_next[i][j]);
            p_cell[i][j] = p_begin[i][j];
            if(p_next[i][j] == 1){
                show_grid(window, screenSurface, value * j, value * i,Length,Width);
            }
        }
        fprintf(file,"\n");
        memset(p_next[i],0,sizeof (p_next[i]));
    }
    fclose(file);
    //printf("1111111\n");
}// Assign the value to the cell pointer

//void read(int length, int width, char *filename){
//    FILE *file = fopen(filename,"w+");
//    p_begin = (int **)malloc(sizeof (int *)*width);
//    p_next = (int **) malloc(sizeof (int *)*width);
//    p_cell = (int **) malloc(sizeof (int *)*width);//Dynamically allocate the space of a two-dimensional array
//    for(int i = 0; i < width; ++i){
//        p_cell[i] = (int *) malloc(length * sizeof (int) );
//        memset(p_cell[i],0,sizeof (p_cell[i]));
//        p_begin[i] = (int *) malloc(length * sizeof (int) );
//        memset(p_cell[i],0,sizeof (p_begin[i]));
//    }
//    for(int i = 0; i < width; ++i){
//        for (int j = 0; j < length; ++j) {
//            p_cell[i][j] = p_begin[i][j];
//        }
//    }
//    fclose(file);
//}

void interface(){
    printf("Please enter your choice\n");
    printf("1)Initialize the map by modifying the file\n");
    printf("2)Initialize the map by mouse click\n");
    printf("3)Quit\n");
    printf("Option:");
    // user choice interface
}

void choice(){
    printf("\nWhich way do you want to play:\n\n");
    printf("Please enter your choice\n");
    printf("1)By keyboard event\n");
    printf("2)By auto play\n");
    printf("3)Quit\n");
    printf("Option:");
    //Key event choice interface
}

void end(){
    printf("Game is over!\n");
    exit(0);
}// End information

void save_game(int length, int width, char *filename){
    int i,j;
    FILE *file;
//    if(!user_p){
//        return;
//    }
    if ((file= fopen(filename,"w+")) == NULL){
        printf("Failed to open the save file.\n");
        exit(1);
    }
//    for(i = 0; i < width; i ++){
//        for(j = 0; j < length;j++){
//            if(){
//                show_cell(window,screenSurface, 200*i, 200*j);
//            }
//        }
//    }
    for(i = 0; i < width; ++i){
        for(j = 0; j < length; ++j){
            fprintf(file,"%d",p_begin[i][j]);
        }
        fprintf(file,"\n");
    }
    fclose(file);
}//Store the map result in a file


void game_way(char *file, int iteration){
    char d = '4';
    while(d != '3' && d != '2' && d != '1'){
        while (1){
            choice();
            int count_2 = 0;
            scanf("%c",&d);
            while(getchar()!='\n') count_2 ++;
            if(count_2 > 0){
                printf("\nSorry, the option you enter was invalid, please try again.\n\n");
                continue;
            }else{
                break;
            }
        }
        switch (d) {
            case '1':
                game_file(file,iteration);
                SDL_Quit();break;// modify file mode
            case '2':
                game_auto(file,iteration);
                SDL_Quit(); break;//mouse click mode
            case '3':
                SDL_Quit();break;//exit program
            default:
                printf("\nSorry, the option you enter was invalid, please try again.\n");
                break;
        }
    }
}// Players want to play which way to continue the game


void user_choice(char *file, int iteration){
    char a = '4';
    while(a != '3' && a != '2' && a != '1'){
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
            case '1':
                game_way(file,iteration);
                SDL_Quit();break;// modify file mode
            case '2':
                game_click(file,iteration);
                SDL_Quit(); break;//mouse click mode
            case '3':
                SDL_Quit();
                exit(0);break;//exit program
            default:
                printf("\nSorry, the option you enter was invalid, please try again.\n");
                break;
        }
    }
}

void game_file(char *file, int iteration){
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;//Initial the window and screen pointer

    int Length;// Map length
    int Width;//Map width
    char line[200];

    initGrid(&Length,&Width,file);// initial the grid map (read the file and get the length and with)

    p_begin = (int **)malloc(sizeof (int *)*Width);
    p_next = (int **) malloc(sizeof (int *)*Width);
    p_cell = (int **) malloc(sizeof (int *)*Width);//Dynamically allocate the space of a two-dimensional array
    //printf("11111111111\n");
    //Width = 6, Length = 5
//    printf("%d\n",Width);
//    printf("%d\n",Length);
    window = SDL_window(Length, Width);// Get a window
//    printf("11111111111\n");
    screenSurface = SDL_surface(window);// Get a screen surface
    //if(initGrid(&Length,&Width,file) == -1){
    //printf("");
    //}// init the game of life
    //printf("11111111111\n");
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
    for(int i = 0; i < Width; ++i){
        p_next[i] = (int *) malloc(Length * sizeof (int) );
        memset(p_next[i],0,sizeof (p_next[i]));
    }
    for(int i = 0; i < Width; ++i){
        p_cell[i] = (int *) malloc(Length * sizeof (int) );
        memset(p_cell[i],0,sizeof (p_cell[i]));
    }//Dynamically allocate the space of a two-dimensional array

    //Show the cell and read information in the file, initial the grid[i][j](p_begin)
    FILE *filename = fopen(file,"r");
    rewind(filename);
    //printf("%d\n",Width);
    for(int i = 0; i < Width; ++i){
        fflush(stdin);
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
                show_grid(window, screenSurface, value * j, value * i,Length,Width);
            } else{
                continue;
            }
        }
    }
    fclose(filename);
    //printf("11111111111\n");
    show_survive(window, screenSurface, Length, Width,Length,Width);// Draw the game of life map
    //printf("11111111111\n");

    bool success = true;// True or false to implement the SQL event
    int count_play = 0;// Playing number counter
    SDL_event(success);// The first SQL event

    //The circle of SDL event
    while(1){
        count_play++;
//        if(iteration < 0){
//            break;
//        }
        show_map(window,screenSurface);
        cell_change(Length,Width);
        //save(Length, Width, file, window, screenSurface,p_next);
        //save_game(Length,Width,file);
        cell_copy(Length,Width,window,screenSurface,file);
        show_survive(window, screenSurface, Length, Width,Length,Width);

        FILE *fp_1 = fopen(file,"r");
        rewind(fp_1);
        for(int i = 0; i < Width; ++i){
            fflush(stdin);
            fgets(line,150,fp_1);
            for(int j = 0; j < Length && (line[j] != '\r' && line[j] !='\n'); ++j){
                p_cell[i][j] = line[j] - '0';
            }
        }
        fflush(stdin);
        fclose(fp_1);

        SDL_event(success);

        if(game_over(Length,Width,iteration,count_play)){//Judge whether the game is over or not
//            printf("1111\n");
            break;
        } else{
            FILE *fp = fopen(file,"r");
            rewind(fp);
            for(int i = 0; i < Width; ++i){
                fflush(stdin);
                fgets(line,150,fp);
                for(int j = 0; j < Length && (line[j] != '\r' && line[j] !='\n'); ++j){
                    p_begin[i][j] = line[j] - '0';
                }
            }
            fclose(fp);
            //printf("11111111111\n");
        }// If game is not ended, then assign the value to p_begin to compare with p_next and store information;
    }

    freeAll();// free the pointer

    //SDL_UpdateWindowSurface(window);
    //save(Length, Width, window, screenSurface,file);//save the result in the file

    SDL_quit(window);// Quit the window
    printf("\nGame is over! Thank you for having a good time!\n\n");// Game is over information
}// The game framework by key event

void game_auto(char *file, int iteration){
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;//Initial the window and screen pointer

    int Length;// Map length
    int Width;//Map width
    char line[200];

    initGrid(&Length,&Width,file);// initial the grid map (read the file and get the length and with)

    p_begin = (int **)malloc(sizeof (int *)*Width);
    p_next = (int **) malloc(sizeof (int *)*Width);
    p_cell = (int **) malloc(sizeof (int *)*Width);//Dynamically allocate the space of a two-dimensional array
    //printf("11111111111\n");
    //Width = 6, Length = 5
//    printf("%d\n",Width);
//    printf("%d\n",Length);
    window = SDL_window(Length, Width);// Get a window
//    printf("11111111111\n");
    screenSurface = SDL_surface(window);// Get a screen surface
    //if(initGrid(&Length,&Width,file) == -1){
    //printf("");
    //}// init the game of life
    //printf("11111111111\n");
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
    for(int i = 0; i < Width; ++i){
        p_next[i] = (int *) malloc(Length * sizeof (int) );
        memset(p_next[i],0,sizeof (p_next[i]));
    }
    for(int i = 0; i < Width; ++i){
        p_cell[i] = (int *) malloc(Length * sizeof (int) );
        memset(p_cell[i],0,sizeof (p_cell[i]));
    }//Dynamically allocate the space of a two-dimensional array

    //Show the cell and read information in the file, initial the grid[i][j](p_begin)
    FILE *filename = fopen(file,"r");
    rewind(filename);
    //printf("%d\n",Width);
    for(int i = 0; i < Width; ++i){
        fflush(stdin);
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
                show_grid(window, screenSurface, value * j, value * i,Length,Width);
            } else{
                continue;
            }
        }
    }
    fclose(filename);
    //printf("11111111111\n");
    show_survive(window, screenSurface, Length, Width,Length,Width);// Draw the game of life map
    //printf("11111111111\n");

    bool success = false;// True or false to implement the SQL event
    int count_play = 0;// Playing number counter
    SDL_event(success);// The first SQL event

    //The circle of SDL event
    while(1){
        count_play++;
//        if(iteration < 0){
//            break;
//        }
        show_map(window,screenSurface);
        cell_change(Length,Width);
        //save(Length, Width, file, window, screenSurface,p_next);
        //save_game(Length,Width,file);
        cell_copy(Length,Width,window,screenSurface,file);
        show_survive(window, screenSurface, Length, Width,Length,Width);

        FILE *fp_1 = fopen(file,"r");
        rewind(fp_1);
        for(int i = 0; i < Width; ++i){
            fflush(stdin);
            fgets(line,150,fp_1);
            for(int j = 0; j < Length && (line[j] != '\r' && line[j] !='\n'); ++j){
                p_cell[i][j] = line[j] - '0';
            }
        }
        fflush(stdin);
        fclose(fp_1);

        SDL_event(success);

        if(game_over(Length,Width,iteration,count_play)){//Judge whether the game is over or not
//            printf("1111\n");
            break;
        } else{
            FILE *fp = fopen(file,"r");
            rewind(fp);
            for(int i = 0; i < Width; ++i){
                fflush(stdin);
                fgets(line,150,fp);
                for(int j = 0; j < Length && (line[j] != '\r' && line[j] !='\n'); ++j){
                    p_begin[i][j] = line[j] - '0';
                }
            }
            fclose(fp);
            //printf("11111111111\n");
        }// If game is not ended, then assign the value to p_begin to compare with p_next and store information;
    }

    freeAll();// free the pointer

    //SDL_UpdateWindowSurface(window);
    //save(Length, Width, window, screenSurface,file);//save the result in the file

    SDL_quit(window);// Quit the window
    printf("\nGame is over! Thank you for having a good time!\n\n");// Game is over information
}// The game framework by key event

void game_click(char *file, int iteration){
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;//Define a window and screen pointer

    int Length;// Map length
    int Width;//Map width
    char line[200];
    int b,c;
    bool get = true;
    char ch[200];
    while(get){
        printf("\nPlease enter the length of the life of game:");
        fgets(ch,150,stdin);
        for(b = 0; b < strlen(ch);b++){
            if(ch[b] == '\r' || ch[b] == '\n') break;
            if(ch[b] >= '0' && ch[b] <= '9'){
                get = false;
            }else{
                printf("\nYour input is wrong.\n");
                break;
            }
        }
    }//Get the length of the game
    Length = atoi(ch);
    get = true;
    while(get){
        printf("\nPlease enter the width of the life of game:");
        fgets(ch,150,stdin);
        for(c = 0; c < strlen(ch);c++){
            if(ch[c] == '\r' || ch[c] == '\n') break;
            if(ch[c] >= '0' && ch[c] <= '9'){
                get = false;
            }else{
                printf("\nYour input is wrong.\n");
                break;
            }
        }
    }//Get the width of the game
    Width = atoi(ch);//Get the width of the game

    p_begin = (int **)malloc(sizeof (int *)*Width);
    p_next = (int **) malloc(sizeof (int *)*Width);
    p_cell = (int **) malloc(sizeof (int *)*Width);//Dynamically allocate the space of a two-dimensional array

    for(int i = 0; i < Width; ++i){
        p_begin[i] = (int *) malloc(Length * sizeof (int));
    }
    for(int j = 0; j < Width; ++j){
        p_next[j] = (int *) malloc(Length * sizeof (int));
        memset(p_next[j],0,sizeof (p_next[j]));
    }
    for(int k = 0; k < Width; ++k){
        p_cell[k] = (int *) malloc(Length * sizeof (int));
        memset(p_cell[k],0,sizeof (p_cell[k]));
    }//Dynamically allocate the space of a two-dimensional array

    window = SDL_window(Length, Width);// Get a window
    screenSurface = SDL_surface(window);// Get a screen surface
    show_map(window,screenSurface);
    show_survive(window, screenSurface, Length, Width,Length,Width);
    int x = 0;
    int y = 0;
    int count_play = 0;

    bool success = true;
    SDL_mouseevent(success,NULL, &x,&y,p_begin,Length,Width,window,screenSurface,file);
    show_map(window,screenSurface);
    show_survive(window, screenSurface, Length, Width,Length,Width);

    FILE *fp_2 = fopen(file,"r");
    rewind(fp_2);
    for(int i = 0; i < Width; ++i){
        fflush(stdin);
        fgets(line,150,fp_2);
        for(int j = 0; j < Length && (line[j] != '\r' && line[j] !='\n'); ++j){
            p_begin[i][j] = line[j] - '0';
        }
    }
    fflush(stdin);

    while(1){
        count_play++;
//        if(iteration < 0){
//            break;
//        }
        show_map(window,screenSurface);
        cell_change(Length,Width);
        //save(Length, Width, file, window, screenSurface,p_next);
        //save_game(Length,Width,file);
        cell_copy(Length,Width,window,screenSurface,file);
        show_survive(window, screenSurface, Length, Width,Length,Width);

        FILE *fp_1 = fopen(file,"r");
        rewind(fp_1);
        for(int i = 0; i < Width; ++i){
            fflush(stdin);
            fgets(line,150,fp_1);
            for(int j = 0; j < Length && (line[j] != '\r' && line[j] !='\n'); ++j){
                p_cell[i][j] = line[j] - '0';
            }
        }

        SDL_mouseevent(success,NULL, &x,&y,p_cell,Length,Width,window,screenSurface,file);

        if(gameover(Length,Width,iteration,count_play)){
//            printf("1111\n");
            break;
        } else{
            FILE *fp = fopen(file,"r");
            rewind(fp);
            for(int i = 0; i < Width; ++i){
                fflush(stdin);
                fgets(line,150,fp);
                for(int j = 0; j < Length && (line[j] != '\r' && line[j] !='\n'); ++j){
                    p_begin[i][j] = line[j] - '0';
                }
            }
            fclose(fp);
        }
    }
    freeAll();
    //SDL_UpdateWindowSurface(window);
    //save(Length, Width, window, screenSurface,file);//save the result in the file
    SDL_quit(window);
    printf("\nGame is over! Thank you for having a good time!\n\n");// Game is over information
}// The game framework

bool game_over(int Length, int Width,int iteration,int num){
    int count_num = 0;
    int count_last = 0;
//    for(int i = 0; i < Width; ++i){
//        for(int j = 0; j < Length; ++j){
//            p_cell[i][j] = p_begin[i][j];
//        }
//    }
    for(int i = 0; i < Width; ++i){
        for(int j = 0; j < Length; ++j){
            if(p_cell[i][j] == 0){
                count_num++;
            }
        }
    }
    for(int i = 0; i < Width; ++i){
        for(int j = 0; j < Length; ++j){
            if(p_cell[i][j] == p_begin[i][j]){
                count_last++;
            }
        }
    }
    //iteration ++;
    if(num == iteration || count_num == Length * Width || count_last == Length * Width){
        if(count_last == Length * Width){
            printf("\nAll cells in the map have maintained a constant state\n");
        }
        if(count_num == Length * Width){
            printf("\nAll cells in the map have died.\n");
        }
        if(num == iteration){
            printf("\nThe number of iterations you defined is exhausted\n");
        }
        return true;
    }
    return false;
}// Judge game is over or not from iteration, map is the same as last and all cell is dead

bool gameover(int Length, int Width,int iteration,int num){
    int count_num = 0;
//    for(int i = 0; i < Width; ++i){
//        for(int j = 0; j < Length; ++j){
//            p_cell[i][j] = p_begin[i][j];
//        }
//    }
    for(int i = 0; i < Width; ++i){
        for(int j = 0; j < Length; ++j){
            if(p_cell[i][j] == 0){
                count_num++;
            }
        }
    }
    //iteration ++;
    if(num == iteration || count_num == Length * Width){
        if(count_num == Length * Width){
            printf("\nAll cells in the map have died.\n");
        }
        if(num == iteration){
            printf("\nThe number of iterations you defined is exhausted\n");
        }
        return true;
    }
    return false;
}// Judge game is over or not from iteration, map is the same as last and all cell is dead
