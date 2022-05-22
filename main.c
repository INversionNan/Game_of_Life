#include "main.h"
#include "game.h"

int main(int argc, char *argv[]) {
    int i, j, k, iteration;
    char it[200];
    char ch[4];
    char file[1000];
    char empty[1000];
    bool get = true;
    if(argc > 2) {
        int length_1 = strlen(argv[1]);
        if (length_1 < 4 || (argv[1][length_1 - 1]) != 't' || (argv[1][length_1 - 3]) != 't' ||
            (argv[1][length_1 - 2]) != 'x' || (argv[1][length_1 - 4]) != '.') {
            do {
                printf("Wrong firename! Please enter a file name ending in txt:");
                fgets(file, 200, stdin);
                if (file[strlen(file) - 1] != '\n') while (getchar() != '\n');
                for (i = strlen(file); file[i - 1] == '\n' || file[i - 1] == '\r'; i--) {
                    file[i - 1] = '\0';
                }
            } while (file[strlen(file) - 1] != 't' || file[strlen(file) - 2] != 'x' || file[strlen(file) - 3] != 't' ||
                     file[strlen(file) - 4] != '.');
        } else {
            strcpy(file, argv[1]);
        }
        while (1) {
            printf("\nDo you want to increase the number of iterations:(Y/N)");
            fgets(ch, 4, stdin);
            for (int l = strlen(ch); ch[l - 1] == '\n' || ch[l - 1] == '\r'; l--) {
                ch[l - 1] = '\0';
            }
            if (strcmp(ch, "N") == 0) {
                break;
            } else if (strcmp(ch, "Y") == 0) {
                while (get) {
                    printf("\nPlease enter the iteration of the life of game:");
                    fgets(it, 150, stdin);
                    for (int b = 0; b < strlen(it); b++) {
                        if (it[b] == '\r' || it[b] == '\n') break;
                        if (it[b] >= '0' && it[b] <= '9') {
                            get = false;
                        } else {
                            printf("\nYour input is wrong.\n");
                            break;
                        }
                    }
                }
                iteration = atoi(it);
                break;
            }else{
                printf("\nYour input is wrong.\n");
            }
        }
    }
    if(argc > 2){
        int length_2 = strlen(argv[2]);
        for(j = 0; j < length_2; ++j){
            if(argv[2][j] < '0' || argv[2][j] > '9'){
                break;
            }
        }
        if(j == length_2){
            iteration = atoi(argv[2]);
        } else{
            while(1){
                printf("Wrong iteration number! Please enter a correct number:");
                fgets(empty,150,stdin);
                if(empty[strlen(empty) - 1] != '\n') while(getchar()!='\n');
                for(j = strlen(empty); empty[j - 1] == '\n' || empty[j - 1] == '\r'; j--){
                    empty[j - 1] = '\0';
                }
                for (k = 0; k < strlen(empty); ++k) {
                    if(empty[k] < '0' || empty[k] > '9'){
                        break;
                    }
                }
                if(k == strlen(empty)){
                    iteration = atoi(empty);
                    break;
                }
            }
        }
    }// Command line operation
//    char *file = "game.txt";
//    int iteration = 10;
    user_choice(file,iteration);// Player wants to play which mode

    return 0;
}
