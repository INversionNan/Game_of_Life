#include "main.h"

#define M 100
#define  N 100
int Map1[M][N] = {0};
int Map2[M][N] = {0};

int load_cell(FILE *file, int length, int width){
    int i, j;
    char ch = '\0';
    rewind(file);
    for(i = 0; i < length; i++){
        for (j = 0; j < width; j++) {
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

    if ((filename = fopen(file,"r")) == NULL){
        filename = fopen(file,"w+");
    } else{
        filename = fopen(file,"r");
    }

    if(!fgets(read,150,filename)){
        printf("The file is empty!\n");
        printf("Please modify file contents to complete initialization.");
        //return -1;
    }
//    printf("%s",read);
    for(int i = 0;i < strlen(read) && (read[i] != '\r' && read[i] !='\n'); i++){
        if(read[i] == '0' || read[i] == '1'){
            count++;
        }
    }
    printf("%d\n",count);
    *width = count;
    //printf("%d\n",width);
//    for (int j = 0; j < ; ++j) {
//
//    }
    //printf("%d",count);

    for(count = 0; fgets(read,150,filename) != NULL; count++);
    *length = count + 1;
    //printf("%d\n",*length);

    //window = SDL_window(*length, *width);
    //screenSurface = SDL_surface(window);
    //printf("11111111111\n");
    rewind(filename);
    for(int j = 0; j < *width; ++j){
        //printf("11111111111\n");
//        printf("%s\n",read);
        fgets(read,150,filename);
        //printf("%s\n",read);
        p_begin[j] = (int *) malloc(sizeof (int)*(count+1));
        for(int i = 0;i < *length && (read[i] != '\r' && read[i] !='\n'); ++i){
            //printf("%c\n",read[i]);
            if(read[i] == '0' || read[i] == '1'){
                p_begin[j][i] = read[i] - '0';
                //printf("%d\n",p_begin[j][i]);
            }else{
                printf("Your input is wrong. Please input 1 on behalf of survive, 0 on behalf of death.\n");
                break;
            }
            //printf("%d\n",p_begin[j][i]);
//            if(p_begin[j][i] == 1){
//                //printf("111111\n");
//                show_grid(window, screenSurface, 200 * i, 200 * j);
//            } else{
//                continue;
//            }
        }
    }
    //printf("11111111111\n");
    fclose(filename);
    //printf("11111111111\n");
    //return 0;
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
