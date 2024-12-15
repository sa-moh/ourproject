
#include <stdio.h>
# include <conio.h>
#include <windows.h>

const int a= 17;
const int b = 17;
char board[a][b] ;
int checkBoard[a][b] = {0};
int p;


//functions

// these are some functions for changing color.
void green(){
    printf("\033[0;32m");
}
void red(){
    printf("\033[0;31m");
}
void blue(){
    printf("\033[0;34m");
}
void reset(){
    printf("\033[0m");
}

// when a number is larger than  the given is entered. it gives an error and beeps.
void BeepError(){
    Beep(400, 1000);
    printf("ops,your coordinates are invalid!try again.\n");
}



int sugestion_move(sartX,startY,endX,endY){
    if (startX<=endX && startY <= endY ){
            if (downMove())
            else if (rightMove())
            else if (upMove())
            else if (leftMove())
    }
    else if (startX<=endX && startY >= endY ){
            if (downMove())
            else (leftMove())
            else if (rightMove())
            else if (upMove())
    }
    else if (startX >= endX && startY <= endY ){
            if (rightMove())
            else if (upMove())
            else if (downMove())
            else if (leftMove())
    }
    else if (startX >= endX && startY >= endY ){
            if (upMove())
            else if (leftMove())
            else if (rightMove())
            else if (downMove())

    }
}
int upMove( char board[][b], char checkBoard[][b],int &currentMoveX,int &currentMoveY){
    p = board[currentMoveX-1][currentMoveY];
    if (p != 'X' && p != 'C' && checkBoard[currentMoveX-1][currentMoveY] == 0){
            checkBoard[currentMoveX-1][currentMoveY] = 1;
            currentMoveX --;
            retuen 1;
    }
    return 0;
}


int downMove( char board[][b], char checkBoard[][b],int &currentMoveX,int &currentMoveY){
    p = board[currentMoveX+1][currentMoveY];
    if (p != 'X' && p != 'C' && checkBoard[currentMoveX+1][currentMoveY] == 0){
            checkBoard[currentMoveX+1][currentMoveY] = 1;
            currentMoveX ++;
            retuen 1;
    }
    return 0;
}

int rightMove( char board[][b], char checkBoard[][b],int &currentMoveX,int &currentMoveY){
    p = board[currentMoveX][currentMoveY+1];
    if (p != 'X' && p != 'C' && checkBoard[currentMoveX][currentMoveY+1] == 0){
            checkBoard[currentMoveX][currentMoveY+1] = 1;
            currentMoveY ++;
            retuen 1;
    }
    return 0;
}

int leftMove( char board[][b], char checkBoard[][b],int &currentMoveX,int &currentMoveY){
    p = board[currentMoveX][currentMoveY+1];
    if (p != 'X' && p != 'C' && checkBoard[currentMoveX][currentMoveY-1] == 0){
            checkBoard[currentMoveX][currentMoveY-1] = 1;
            currentMoveY--;
            retuen 1;
    }
    return 0;
}





int main() {

    int row, column;
    int startX, endX;
    int startY, endY;


    int i,j;

    int x,y;
    int number_center;
    int number_village;
    int number_block;

    int gold_product;
    int food_product;
    int village_info[288][4];
    int blocked_info[288][2]


    printf("welcome to our game.\n");
    printf("Please enter the number of rows and columns:\n"); // the numbers of rows and columns depend on the user's decision.
    scanf("%d%d",&row,&column);


    for(i=0 ; i<row;i++){                            // by default, we consider all houses as '1'
        for (j=0;j<column;j++) board[i][j]='1';
    }


    printf("Please type coordinates of center%d:\n",i+1);
    scanf("%d%d",&endx,&endy);
    if(x > row || y > column){
        BeepError();
        i--;
        continue;
    }
    board[x-1][y-1]='C';


    printf("Please enter number of villages:\n");
    scanf("%d",&number_village);
    for(int i=0;i<number_village;i++){
        printf("Please enter coordinates of village%d:\n",i+1);
        scanf("%d%d",&x,&y);
        if(x > row || y > column){
            BeepError();
            i--;
            continue;
        }
        board[x-1][y-1] = 'V';
        village_info[i][0]=x;
        village_info[i][1]=y;
        printf("Please enter gold production rate of village%d:\n",i+1);
        scanf("%d",&gold_product);
        village_info[i][2]=gold_product;
        printf("Please enter food production rate of village%d:\n",i+1);
        scanf("%d",&food_product);
        village_info[i][3]=food_product;
    }


    printf("Please enter number of blocked houses:\n");
    scanf("%d",&number_block);
    for (int i = 0;i<number_block;i++){
        printf("Please enter coordinates of blocked houses%d:\n",i+1);
        scanf("%d%d",&x,&y);
        if(x > row || y > column){
            BeepError();
            i--;
            continue;
        }
        board[x-1][y-1] = 'X';
    }





for (i=0;i<number_village;i++){

}
















/*
    for (i = 0 ;i<row;i++){
        for (int j =0; j<column;j++){


            if (board[i][j] == 'C'){                       // the color of centers is blue.
                blue();
                printf("%c ",board[i][j]);

            }
            else if(board[i][j] == 'V'){                   // the color of village is green.
                green();
                printf("%c ",board[i][j]);

            }
            else if(board[i][j] == 'X'){                   //the color of blocked houses is red.
                red();
                printf("%c ",board[i][j]);

            }
            else {                                        // the color of ways is black.
                reset();
                printf("%c ",board[i][j]);

            }

        }
        printf("\n");
    }


*/

    return 0;
}
