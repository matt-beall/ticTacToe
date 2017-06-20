/* Hello World program */

#include <stdio.h>
#include <stdbool.h>
#include "types.h"
#include "gameState.h"


char printBoard[100] = "\n\r_1_|_2_|_3_\n\r_4_|_5_|_6_\n\r 7 | 8 | 9\n\r";



int boardMoveScore[3][3];


GameBoard gameBoard;


void ind2Sub(int index, int* row, int* col);

void sub2Ind(int row, int col, int* index);


int getCellMoveScore(int cellNumber, GameBoard boardState);

void determineBoardMoveScores(Player perspective);

void clearGameBoard();

void printGameBoard();

void getUserPlay(char* player, int* rowResult, int* colResult);

int ticTacToe(bool userFirst);


void ind2Sub(int index, int* row, int* col)
{
    *row = (index - 1) / 3;
    *col = index - (*row)*3 - 1;
}

void sub2Ind(int row, int col, int* index)
{
    *index = row*3 + col + 1;
}

//Input: Current game board, proposed next move
//Return: value of the proposed next move
int getCellMoveScore(int proposedMove, GameBoard boardState)
{
    GameBoard nextMoveGameBoard;
    nextMoveGameBoard = boardState;
    int cellValue;
    cellValue = 0;

    // switch(getVictoryStatus(boardState))
    // {
    //     case STATUS_WIN:
    //         cellValue = 10;
    //         return cellValue;
    //         break;
    //     case STATUS_LOSS:
    //         cellValue = -10;
    //         return cellValue;
    //         break;
    //     case STATUS_NONE:
    //     default:
    //         break;
    // }

    int row, col;
    for(row = 0; row < 3; row++)
    {
        for(col = 0; col < 3; col++)
        {
            //YOU ARE HERE!!!!!
            // cellValue += getCellMoveScore()
        }
    }
    return cellValue;
}


void determineBoardMoveScores(Player perspective)
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
            gameBoard.cells[row][col] = PLAYER_NONE;
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
            switch(gameBoard.cells[row][col])
            {
                case PLAYER_X:
                    sprintf(squareStateStr, "X");
                    break;
                case PLAYER_O:
                    sprintf(squareStateStr, "O");
                    break;
                case PLAYER_NONE:
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

    ind2Sub(i, &row, &col);

    *rowResult = row;
    *colResult = col;
}

int ticTacToe(bool userFirst)
{
    int row, col;
    if(userFirst)
    {
        int stat = getVictoryStatus(&gameBoard);
        printf("Status: %d\n\r", stat);

        while(getVictoryStatus(&gameBoard) == STATUS_NONE)
        {
            printf("HERE");
            char p[10];
            sprintf(p, "X");
            getUserPlay(p, &row, &col);
            // printf("%d %d \n\r", row, col);

            gameBoard.cells[row][col] = PLAYER_X;

            printGameBoard();
            stat = getVictoryStatus(&gameBoard);
            printf("Status: %d\n\r", stat);
        }
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