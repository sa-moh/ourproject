#include <stdio.h>
# include <conio.h>
#include <windows.h>

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



int main() {
    const int a= 17;
    const int b = 17;
    char board[a][b] ;
    int row, column;

    int i,j;

    int x,y;
    int number_center;
    int number_village;
    int number_block;

    int gold_product;
    int food_product;
    int village_info[288][4];


    printf("welcome to our game.\n");
    printf("Please enter the number of rows and columns:\n"); // the numbers of rows and columns depend on the user's decision.
    scanf("%d%d",&row,&column);


    for(i=0 ; i<row;i++){                            // by default, we consider all houses as '1'
        for (j=0;j<column;j++) board[i][j]='1';
    }



    printf("Please enter number of centers:\n");
    scanf("%d",&number_center);
    for(i=0;i<number_center;i++){
        printf("Please type coordinates of center%d:\n",i+1);
        scanf("%d%d",&x,&y);
        if(x > row || y > column){
            BeepError();
            i--;
            continue;
        }
        board[x-1][y-1]='C';
    }


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




    return 0;
}
