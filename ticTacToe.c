/* Hello World program */

#include <stdio.h>
#include <stdbool.h>



typedef enum
{
SQUARE_NONE = 0,
SQUARE_X    = 1,
SQUARE_O    = 2
} Square;


char printBoard[100] = "\n\r_1_|_2_|_3_\n\r_4_|_5_|_6_\n\r 7 | 8 | 9\n\r";

Square gameBoard[3][3];


int boardMoveScore[3][3];

void determineBoardMoveScores(Square perspective)
{
    //Recursive Mumbo Jumbo to score each square based on decision tree and whether it's winning or losing
    

}


void clearGameBoard()
{
    int row, col;
    for(row = 0; row < 3; row++)
    {
        for(col = 0; col < 3; col++)
        {
            gameBoard[row][col] = SQUARE_NONE;
        }
    }
}


void printGameBoard()
{
    int row, col;
    printf("\n\r");
    for(row = 0; row < 3; row++)
    {
        for(col = 0; col < 3; col++)
        {
            char squareStateStr[100];
            switch(gameBoard[row][col])
            {
                case SQUARE_X:
                    sprintf(squareStateStr, "X");
                    break;
                case SQUARE_O:
                    sprintf(squareStateStr, "O");
                    break;
                case SQUARE_NONE:
                default:
                    sprintf(squareStateStr, "%d", (row*3 + col + 1));
                    break;
            }


            if(row < 2)
                printf("_%s_", squareStateStr);
            else
                printf(" %s ", squareStateStr);

            if(col < 2)
                printf("|");
            else
                printf("\n");
        }
    }
}

void getUserPlay(char* player, int* rowResult, int* colResult)
{
    int i, row, col;
    printf("Player %s, Move: ", player);
    scanf("%d", &i);

    row = (i - 1) / 3;
    col = i - row*3 - 1;

    *rowResult = row;
    *colResult = col;
}

int ticTacToe(bool userFirst)
{
    int row, col;
    if(userFirst)
    {
        char p[10];
        sprintf(p, "X");   
        getUserPlay(p, &row, &col);
        // printf("%d %d \n\r", row, col);

        gameBoard[row][col] = SQUARE_X;

        printGameBoard();
    }else
    {

    }
}

int main()
{
    clearGameBoard();
    printGameBoard();
    ticTacToe(true);
    return 0;
}