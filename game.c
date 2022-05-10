#include "main.h"

void show(){

}
void game(){
    int **p_begin = (int **)malloc(sizeof (int *));
    int **p_next = (int **) malloc(sizeof (int *));
    int **p_cell = (int **) malloc(sizeof (int *));
    FILE *file;
    if((file=fopen("map.txt","r"))==NULL){
        file = fopen("map.txt","w+");
    }
    int i,j;
    if(load_cell(file) == -1){

    }
}

