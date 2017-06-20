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


int getCellMoveScore(GameBoard gb, int row, int col, Player perspective, Player turn);

void getComputerPlay(GameBoard gb, Player p, int * row, int * col);

void clearGameBoard();

void printGameBoard(GameBoard gb);

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
long int entries;
//Input: Current game board, proposed next move, whos turn, whos perspective
//Return: value of the proposed next move
int getCellMoveScore(GameBoard gb, int row, int col, Player perspective, Player turn)
{
    entries++;

    if(entries > 5)
        return 0;

    printGameBoard(gb);

    printf("Ent: %ld, Try r: %d, c: %d", entries, row, col);

    if(gb.cells[row][col] != PLAYER_NONE)
    {
        return 0;
    }

    gb.cells[row][col] = turn;

    Player opponent = perspective == PLAYER_X? PLAYER_O:PLAYER_X;

    GameStatus win, loss;

    win  = perspective == PLAYER_X? STATUS_X:STATUS_O;
    loss = perspective == PLAYER_X? STATUS_O:STATUS_X;

    int cellValue;
    cellValue = 0;

    Player nextTurn = turn == PLAYER_X? PLAYER_O:PLAYER_X;

    int r, c;
    
    switch(getVictoryStatus(&gb))
    {
        case STATUS_X:
            if(win == STATUS_X)
                return 10;
            else
                return -10;
            break;
        case STATUS_O:
            if(win == STATUS_O)
                return 10;
            else
                return -10;
            break;
        case STATUS_DRAW:
            return 0;
            break;
        case STATUS_NONE:
            for(r = 0; r < 3; r++)
            {
                for(c = 0; c < 3; c++)
                {
                    if(gb.cells[r][c] == PLAYER_NONE)
                        cellValue += getCellMoveScore(gb, r, c, perspective, nextTurn);

                }
            }
            return cellValue;
        break;
    }
    return cellValue;
}


void getComputerPlay(GameBoard gb, Player p, int * row, int * col)
{
    int maxScore = -30000;
    int r, c;
    int bestPlayRow, bestPlayCol;
    bestPlayRow = 0;
    bestPlayCol = 0;
    for(r = 0; r < 3; r++)
    {
        for(c = 0; c < 3; c++)
        {
            if(getVictoryStatus(&gb) == STATUS_NONE && gb.cells[r][c] != PLAYER_NONE)
            {
                int thisScore;

                printf("Get Score\n\r");
                thisScore = getCellMoveScore(gb, r, c, p, p);

                if(thisScore > maxScore)
                {
                    maxScore = thisScore;
                    bestPlayRow = r;
                    bestPlayCol = c;
                }
            }
        }
    }

    *row = bestPlayRow;
    *col = bestPlayCol;

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

void getUserPlay(char* player, int* rowResult, int* colResult)
{
    int i, row, col;
    printf("Player %s, Move: ", player);
    scanf("%d", &i);

    ind2Sub(i, &row, &col);

    *rowResult = row;
    *colResult = col;
}

void printGameBoard(GameBoard gb)
{
    int row, col;
    printf("\n\r");
    for(row = 0; row < 3; row++)
    {
        for(col = 0; col < 3; col++)
        {
            char squareStateStr[100];
            switch(gb.cells[row][col])
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


int ticTacToe(bool userFirst)
{
    int row, col;
    if(userFirst)
    {
        Player currentPlayer;
        currentPlayer = PLAYER_X;
        while(getVictoryStatus(&gameBoard) == STATUS_NONE)
        {
            char pStr[10];
            if(currentPlayer == PLAYER_X)
                sprintf(pStr, "X");
            else
                sprintf(pStr, "O");

            switch(currentPlayer)
            {
                case PLAYER_X:
                    getUserPlay(pStr, &row, &col);
                    break;
                case PLAYER_O:
                    getComputerPlay(gameBoard, currentPlayer, &row, &col);
                    break;
                default:
                    printf("Something Went Wrong\n\r");
                    return 0;
                    break;
            }

            gameBoard.cells[row][col] = currentPlayer;

            GameStatus vic;
            vic = getVictoryStatus(&gameBoard);

            printf("Vic Stat: %d\n\r", vic);

            printGameBoard(gameBoard);

            currentPlayer = currentPlayer == PLAYER_X? PLAYER_O:PLAYER_X;

        }

        GameStatus stat;
        stat = getVictoryStatus(&gameBoard);

        printf("Status: %d\n\r", stat);

    }else
    {

    }
}

int main()
{
    entries = 0;
    clearGameBoard();
    printGameBoard(gameBoard);
    ticTacToe(true);
    return 0;
}