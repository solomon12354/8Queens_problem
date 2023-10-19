#include <stdio.h>
#include <stdlib.h>

void printBoard(int size, int board[size][size]){
    for(int i=0;i<size;i++){
        printf("|");
        for(int j=0;j<size;j++){
            if(board[i][j] == 1){
                printf("Q");
            }else if(board[i][j] == 0){
                printf(" ");
            }else if(board[i][j] == -1){
                printf(" ");
            }
            printf("|");
        }
        printf("\n");
        for(int j=0;j<=size;j++){
            printf("+ ");
        }
        printf("\n");
    }
}
int total = 0;
void queens(int n, int size, int board[size][size]){

    if(n == size){
        printBoard(size, board);
        printf("\n\n");
        total++;
        return;
    }
    int checkerboard[size][size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            checkerboard[i][j] = board[i][j];
        }
    }

    for(int i=0;i<size;i++){
        if(checkerboard[n][i] == 0){
            checkerboard[n][i] = 1;
            for(int j = 0; j < 8;j++){
                if(i != j){
                    if(checkerboard[n][j] == 1){
                        return;
                    }
                    checkerboard[n][j] = -1;
                }
                if(n != j){
                    if(checkerboard[j][i] == 1){
                        return;
                    }
                    checkerboard[j][i] = -1;
                }
            }
            if(n > i){
                if((n + i) > (size - 1)){
                    int x = size - 1;
                    int y = (n + i) - x;
                    for(; y < 8; x--, y++){

                        if(x != n && y != i){
                            if(checkerboard[x][y] == 1){
                                //printBoard(size, checkerboard);
                                //printf("n = %d\n",n);
                                return;
                            }
                            checkerboard[x][y] = -1;
                        }
                    }
                }else if((n + i) < (size - 1)){
                    int x = n + i;
                    int y = 0;
                    for(; x >= 0; x--, y++){

                        if(x != n && y != i){
                            if(checkerboard[x][y] == 1){
                                //printBoard(size, checkerboard);
                                //printf("n = %d\n",n);
                                return;
                            }
                            checkerboard[x][y] = -1;
                        }
                    }
                }else{
                    int x = 7;
                    int y = 0;
                    for(; x >= 0; x--, y++){
                        if(x != n && y != i){
                            if(checkerboard[x][y] == 1){
                                //printBoard(size, checkerboard);
                                //printf("n = %d\n",n);
                                return;
                            }
                            checkerboard[x][y] = -1;
                        }
                    }

                }
                int x = n - i;
                int y = 0;
                for(; x < 8 && y < 8; x++, y++){

                    if(x != n && y != i){
                        if(checkerboard[x][y] == 1){
                            //printBoard(size, checkerboard);
                            //printf("n = %d\n",n);
                            return;
                        }
                        checkerboard[x][y] = -1;
                    }
                }

            }else if(n < i){
                if((n + i) > (size - 1)){
                    int x = size - 1;
                    int y = (n + i) - x;
                    for(; y < 8; x--, y++){

                        if(x != n && y != i){
                            if(checkerboard[x][y] == 1){
                                //printBoard(size, checkerboard);
                                //printf("n = %d\n",n);
                                return;
                            }
                            checkerboard[x][y] = -1;
                        }
                    }
                }else if((n + i) < (size - 1)){
                    int x = n + i;
                    int y = 0;
                    for(; x >= 0; x--, y++){

                        if(x != n && y != i){
                            if(checkerboard[x][y] == 1){
                                //printBoard(size, checkerboard);
                                //printf("n = %d\n",n);
                                return;
                            }
                            checkerboard[x][y] = -1;
                        }
                    }
                }else{
                    int x = 7;
                    int y = 0;
                    for(; x >= 0; x--, y++){
                        if(x != n && y != i){
                            if(checkerboard[x][y] == 1){
                                //printBoard(size, checkerboard);
                                //printf("n = %d\n",n);
                                return;
                            }
                            checkerboard[x][y] = -1;
                        }
                    }

                }
                int x = 0;
                int y = i - n;
                for(; x < 8 && y < 8; x++, y++){
                    if(x != n && y != i){
                        if(checkerboard[x][y] == 1){
                            //printBoard(size, checkerboard);
                            //printf("n = %d\n",n);
                            return;
                        }
                        checkerboard[x][y] = -1;
                    }
                }
            }else{
                for(int x = 0;x < size;x++){
                    if(x != n){
                        if(checkerboard[x][x] == 1){
                            //printBoard(size, checkerboard);
                            //printf("n = %d\n",n);
                            return;
                        }
                        checkerboard[x][x] = -1;
                    }
                }
                if(n < size/2){
                    int x = n * 2;
                    int y = 0;
                    for(; x >=0;x--,y++){
                        if(x != n){
                            if(checkerboard[x][y] == 1){
                                //printBoard(size, checkerboard);
                                //printf("n = %d\n",n);
                                return;
                            }
                            checkerboard[x][y] = -1;
                        }
                    }
                }else{
                    int x = size - 1;
                    int y = x - n * 2;
                    for(; y < size;x--,y++){
                        if(x != n){
                            if(checkerboard[x][y] == 1){
                                //printBoard(size, checkerboard);
                                //printf("n = %d\n",n);
                                return;
                            }
                            checkerboard[x][y] = -1;
                        }
                    }
                }
            }
            queens(n+1, size, checkerboard);
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    checkerboard[i][j] = board[i][j];
                }
            }
        }
    }
    return;

}

int main()
{
    int checkerboard[8][8] = {0};
    //printBoard(8,checkerboard);
    queens(0,8,checkerboard);
    printf("\ntotal = %d \n",total);
    return 0;
}
