#include "main.h"
#include "game.h"

void save(int length, int width, char *filename, SDL_Window *window, SDL_Surface *screenSurface,int **p_cell){
    int i,j;
    FILE *file;
//    if(!user_p){
//        return;
//    }
    if ((file= fopen(filename,"w+")) == NULL){
        printf("Failed to open the save file.\n");
        exit(1);
    }
    file = fopen(filename,"w+");
//    for(i = 0; i < width; i ++){
//        for(j = 0; j < length;j++){
//            if(){
//                show_cell(window,screenSurface, 200*i, 200*j);
//            }
//        }
//    }
//    printf("%d",width);
//    printf("%d",length);
    for(i = 0; i < width; ++i){
        for(j = 0; j < length; ++j){
            int m = 0;
            fprintf(file,"%d",m);
            fprintf(file,"%d",p_cell[i][j]);
            //printf("%d\n",p_cell[i][j]);
        }
        fprintf(file,"\n");
    }
    fclose(file);
}//Store the map result in a file


