#include "main.h"

#define M 100
#define  N 100
int Map1[M][N] = {0};
int Map2[M][N] = {0};

int load_cell(FILE *file){
    int i, j;
    char ch = '\0';
    for(i = 0; i < Length; i++){
        for (j = 0; j < Width; j++) {
            fscanf(file,"%c",&ch);
            if(ch == '0'){
                Map1[i][j] = 0;
                Map2[i][j] = 0;
            } else{
                Map1[i][j] = 1;
                Map2[i][j] = 1;
            }
        }
        fscanf(file,"%c",&ch);
    }

}

void initGrid(int *length, int *width, char *file){
    SDL_Window *window = NULL;
    SDL_Surface *screenSurface = NULL;
    FILE *filename;
    char read[200];
    int count;
    int **p_begin = (int **)malloc(sizeof (int *));
    window = SDL_window();
    screenSurface = SDL_surface();
    if ((filename = fopen(file,"r")) == NULL){
        printf("Failed to open the map file.\n");
    } else{
        filename = fopen(file,"r") == NULL;
    }
    if(!fgets(read,150,filename)){
        printf("The file is empty!\n");
        printf("Please modify file contents to complete initialization.");
    }
    for(int i = 0;i < strlen(read) && (read[i] != '\r' || read[i] !='\n'); i++){
        if(read[i] == '0' || read[i] == '1'){
            count++;
        }
    }
    *width = count;
//    for (int j = 0; j < ; ++j) {
//
//    }
    for(count = 0; fgets(read,150,filename) != NULL; count++);
    *length = count + 1;
    rewind(filename);
    for(int j = 0; fgets(read,150,filename) != NULL; j++){
        p_begin[j] = (int *) malloc(sizeof (int)*(count+1));
        for(int i = 0;i < strlen(read) &&(read[i] != '\r' || read[i] !='\n'); ++i){
            if(read[i] == '0' || read[i] == '1'){
                p_begin[j][i] = read[i] - '0';
            } else{
                printf("Your input is wrong. Please input 1 on behalf of survive, 0 on behalf of death.\n");
            }
            if(p_begin[j][i]){
                show_cell(window, screenSurface, 200 * i, 200 * j);
            } else{
                continue;
            }
        }
    }
    fclose(filename);
}

//void initMap(int Map[Length][Width]){
//    int i , j;
//    for(i = 0; i < Length; i++){
//        for (j = 0; j < Width; j++) {
//            if(Map[i][j] == 0){
//                printf("");
//            } else printf("");
//        }
//    }
//}
