#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/* Array to hold the cell status */
char gameBoard[3][3];

/* Function prototypes */
void drawBoard();
int showResult(char ch);
int validateInput(int cell);
void turnPlayerO(int *pCell);
void turnPlayerX(int *pCell);
void getRowCol(int cell, int *pX, int *pY);

int main() {
    int x = 0,
        y = 0,
        row = 0,
        col = 0,
        selectedCell = 0,
        availableCell = 9;
        
    char startChar = '1';
    system("cls");
    
    /* Make all the cell numbered from 1 to 9 */
    for(row = 0; row < 3; row++)
    {
        for(col = 0; col < 3; col++)
        {
            gameBoard[row][col] = startChar++;
        }
    }
    
    /* Now draw gameboard with data in gameBoard[][] array */
    drawBoard();
    
    /* loop for all the cells being played */
    while (availableCell >= 0)
    {
        /* Assume player-1 as X */
        turnPlayerX(&selectedCell);
        
        /* Get row and column from the selected cell */
        getRowCol(selectedCell, &x, &y);
        
        /* Update the gameboard array */
        gameBoard[x][y] = 'X';
        
        /* Decrease the available cell */
        availableCell -= 1;
        
        /* Redraw game board with current data in gameBoard[][] array */
       system("cls");
        drawBoard();
        
        /* Check whether player-1 is winner or not */
        if (showResult('X') == 1)
        {
            break;
        }
        else if(availableCell == 0)
        {
            printf("\n Game Drawn");
            break;
        }
        
        /* Assume player-2 is O */
        turnPlayerO(&selectedCell);
        
        /* Get row and column from the selected cell */
        getRowCol(selectedCell, &x, &y);
        
        /* Update gameboard array */
        gameBoard[x][y] = 'O';
        
        /* Decrease available cell */
        availableCell -= 1;
        
        /* Redraw the gameboard with current data */
        system("cls");
        drawBoard();
        
        /* Check whether player-2 is winner or not */
        if (showResult('O') == 1)
        {
            break;
        }
        else if(availableCell == 0)
        {
            printf("\n Game Drawn");
            break;
        }
    }
    getch();
    return 0;
}

/* Function to draw board with current data */
void drawBoard()
{
    printf("\n TIC TAC TOE");
    printf("\n Digits (1-9) indicates valid cell number\n");
    printf("\n  %c | %c | %c", gameBoard[0][0],gameBoard[0][1],gameBoard[0][2]);
    printf("\n ---|---|---");
    printf("\n  %c | %c | %c", gameBoard[1][0], gameBoard[1][1], gameBoard[1][2]);
    printf("\n ---|---|---");
    printf("\n  %c | %c | %c\n", gameBoard[2][0], gameBoard[2][1], gameBoard[2][2]);
}

/* Function to make player O's move */
void turnPlayerO(int *pCell)
{
    int cell;
    /* loop until player selected a valid cell(Cells with digits) */
    do 
    {
        printf("\n Player O, \n Select valid cell number: ");
        scanf("%d",&cell);
    }while(0 == validateInput(cell));
    
    *pCell = cell;
    
}

/* Function to make player X's move */
void turnPlayerX(int *pCell)
{
    int cell;
    do
    {
        printf("\n Player X, \n Select a valid cell number: ");
        scanf("%d",&cell);
    }while(0 == validateInput(cell));
    
    *pCell = cell;
}

/* Function to calculate row and number from selected cell */
void getRowCol(int cell, int *pX, int *pY)
{
    *pX = (cell - 1) / 3;
    *pY = (cell - 1) % 3;
}

/* Function to check whether selected cell is valid or not.
--> If selected cell is already O or X,
--> If it is not in 1-9, then return 0 to indicate invalid */
int validateInput(int cell)
{
    int row, col;
    
    /* If cell is less than 1 or greater than 9, return 0 */
    if((cell < 1) || (cell > 9))
    {
        return 0;
    }
    
    /* Check if the cell is already occupied */
    getRowCol(cell, &row, &col);
    
    if(('O' == gameBoard[row][col]) || ('X' == gameBoard[row][col]))
    {
        return 0;
    }
    return 1;
}

/* Function to show the winner */
int showResult(char ch)
{
    int status = 0;
    
    /* Check diagonal */
    if(gameBoard[0][0] == ch && gameBoard[1][1] == ch && gameBoard[2][2] == ch)
    {
        printf("\n Player %c is winner", ch);
        status = 1;
    }
    else if(gameBoard[0][2] == ch && gameBoard[1][1] == ch && gameBoard[2][0] == ch)
    {
        printf("\n Player %c is winner", ch);
        status = 1;
    }
    
    /* Check first row */
    else if(gameBoard[0][0] == ch && gameBoard[1][0] == ch && gameBoard[2][0] == ch)
    {
        printf("\n Player %c is winner", ch);
        status = 1;
    }
    
    /* Check second row */
    else if(gameBoard[1][0] == ch && gameBoard[1][1] == ch && gameBoard[1][2] == ch)
    {
        printf("\n Player %c is winner", ch);
        status = 1;
    }
    
    /* Check third row */
    else if(gameBoard[2][0] == ch && gameBoard[2][1] == ch && gameBoard[2][2] == ch)
    {
        printf("\n Player %c is winner", ch);
        status = 1;
    }
    
    /* Check first column */
    else if(gameBoard[0][0] == ch && gameBoard[0][1] == ch && gameBoard[0][2] == ch)
    {
        printf("\n Player %c is winner", ch);
        status = 1;
    }
    
    /* Check second column */
    else if(gameBoard[0][1] == ch && gameBoard[1][1] == ch && gameBoard[2][1] == ch)
    {
        printf("\n Player %c is winner", ch);
        status = 1;
    }
    
    /* Check third column */
    else if(gameBoard[0][2] == ch && gameBoard[1][2] == ch && gameBoard[2][2] == ch)
    {
        printf("\n Player %c is winner", ch);
        status = 1;
    }
    return status;
}