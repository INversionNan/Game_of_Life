#include "main.h"

void show(){

}
void game(){
    FILE *file;
    if((file=fopen("map.txt","r"))==NULL){
        file = fopen("map.txt","w+");
    }
    int i,j;
    if(load_cell(file) == -1){

    }
}

