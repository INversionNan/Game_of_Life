#include "main.h"
void save(int length, int width, char *filename, SDL_Window *window, SDL_Surface *screenSurface){
    int i,j;
    FILE *file;
//    if(!user_p){
//        return;
//    }
    if ((file= fopen("save.txt","w+")) == NULL){
        printf("Failed to open the save file.\n");
        exit(1);
    }
    for(i = 0; i < width; i ++){
        for(j = 0; j < length;j++){
            if(){
                show_cell(window,screenSurface, 200*i, 200*j);
            }
        }
    }
    fclose(file);
}//Store the map result in a file


