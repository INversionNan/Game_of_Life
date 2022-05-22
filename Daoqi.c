#include "main.h"
#include "game.h"

int cell_judge(int cell_survive,int neighbour_survive){
    //If the beginning cell is survival
    if(cell_survive == 1){
        if(neighbour_survive > 3 || neighbour_survive <= 1){
            return 0;
        } else{
            return 1;
        }
    }
    //If the beginning cell is dead
    if(cell_survive == 0){
        if(neighbour_survive == 3){
            return 1;
        } else{
            return 0;
        }
    }
}//judge whether this cell survives or not; 0 is death, 1 is survival.


