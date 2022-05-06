#include "main.h"

#define Length 5
#define Width 5
int cell[Length][Width];

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

void initMap(int Map[Length][Width]){
    int i , j;
    for(i = 0; i < Length; i++){
        for (j = 0; j < Width; j++) {
            if(Map[i][j] == 0){
                printf("");
            } else printf("");
        }
    }

}
