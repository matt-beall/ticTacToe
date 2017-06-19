/* Hello World program */

#include <stdio.h>
#include <stdbool.h>



typedef enum
{
SQUARE_NONE = 0,
SQUARE_X    = 1,
SQUARE_O    = 2
} Square;

typedef enum
{
    STATUS_WIN,
    STATUS_LOSS,
    STATUS_NONE
}

char printBoard[100] = "\n\r_1_|_2_|_3_\n\r_4_|_5_|_6_\n\r 7 | 8 | 9\n\r";



int boardMoveScore[3][3];

typedef struct {
    Square cells[3][3];
}GameBoard;

GameBoard gameBoard;


void ind2RC(int index, int* row, int* col);

void rc2Ind(int row, int col, int* index);

int getCellMoveScore(int cellNumber, GameBoard boardState);


void determineBoardMoveScores(Square perspective);

void clearGameBoard();

void printGameBoard();

void getUserPlay(char* player, int* rowResult, int* colResult);

int ticTacToe(bool userFirst);



void ind2RC(int index, int* row, int* col)
{
    *row = (index - 1) / 3;
    *col = index - (*row)*3 - 1;
}

void rc2Ind(int row, int col, int* index)
{
    *index = row*3 + col + 1;
}

int getCellMoveScore(int cellNumber, GameBoard boardState)
{
    GameBoard nextMoveGameBoard;
    nextMoveGameBoard = boardState;
    int cellValue;
    cellValue = 0;

    switch(getVictoryStatus(boardState))
    {
        case STATUS_WIN:
            cellValue = 10;
            return cellValue;
            break;
        case STATUS_LOSS:
            cellValue = -10;
            return cellValue;
            break;
        case STATUS_NONE:
        default:
            break;
    }

    int row, col;
    for(row = 0; row < 3; row++)
    {
        for(col = 0; col < 3; col++)
        {
            //YOU ARE HERE!!!!!
            cellValue += getCellMoveScore()
        }
    }
    return cellValue;
}


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