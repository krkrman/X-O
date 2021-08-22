#include <stdio.h>
#include <stdlib.h>

enum Player {xPlayer, oPlayer};
enum Winner { xPlayerWinner, oPlayerWinner, draw, gameIsNotFinishedYet};
char board[3][3];


void initBoard();
void play(enum Player);
int checkAvailability(int, int);
void putMark(enum Player,int,int );
void printBoard();
enum Winner checkWinner();
enum Player changePlayer(enum Player);

int main()
{

    printf("Welcome to the game !\n\n");
    enum Player player = xPlayer;
    enum Winner winner = gameIsNotFinishedYet;
    initBoard();
    while(winner == gameIsNotFinishedYet)
    {
        play(player);
        printBoard();
        winner = checkWinner(winner, player);
        player = changePlayer(player);
    }
    printf("========================================\n");
    printf("========================================\n");
    switch(winner)
    {
    case xPlayerWinner:
        printf("Winner is X player");
        break;
    case oPlayerWinner:
        printf("Winner is O player");
        break;
    case draw:
        printf("Draw");
        break;
    }

    return 0;
}

void initBoard()
{
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            board[i][j] = 'z';
        }
    }
}

void play(enum Player player)
{
    int x,y;
    if(player == xPlayer)
        printf("X Player turn\n");
    else
        printf("O Player turn\n");

    printf("Enter row: ");
    scanf("%d",&x);
    printf("Enter column: ");
    scanf(" %d",&y);
    // if chosen before play again
    int isAvailable = checkAvailability(x,y);
    if(!isAvailable)
    {
        printf("This Place is taken before \n\n\n");
        play(player);
    }
    if(x >2 || x<0 ||y >2 || y<0)
    {
        printf("Out of scope \n\n\n");
        play(player);
    }
    putMark(player, x,y);
}

int checkAvailability(int x, int y)
{
    if(board[x][y] == 'X' || board[x][y] == 'O')
        return 0;
    else
        return  1;
}

char checkScope(int x , int y){

}

void putMark(enum Player player,int x,int y)
{
    if(player == xPlayer)
        board[x][y] = 'X';
    else
        board[x][y] = 'O';
}

void printBoard()
{
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

enum Winner checkWinner()
{
    int x = 0,o=0;
    // check rows
    for(int i = 0; i<3; i++)
    {
        x = 0;
        o=0;
        for(int j = 0; j<3; j++)
        {
            if(board[i][j] == 'X')
                x++;
            else if(board[i][j] == 'O')
                o++;

            if(x == 3)
                return xPlayerWinner;
            else if(o == 3)
                return oPlayerWinner;
        }
    }

    // check cols
    for(int i = 0; i<3; i++)
    {
        x = 0;
        o=0;
        for(int j = 0; j<3; j++)
        {
            if(board[j][i] == 'X')
                x++;
            else if(board[j][i] == 'O')
                o++;

            if(x == 3)
                return xPlayerWinner;
            else if(o == 3)
                return oPlayerWinner;
        }
    }
    x = 0;
    o=0;

    // check diagonal
    for(int i = 0; i<3; i++)
    {
        if(board[i][i] == 'X')
            x++;
        else if(board[i][i] == 'O')
            o++;

        if(x == 3)
            return xPlayerWinner;
        else if(o == 3)
            return oPlayerWinner;
    }
    x = 0;
    o=0;

    // check reverse diagonal
    for(int i = 0; i<3; i++)
    {
        if(board[i][2-i] == 'X')
            x++;
        else if(board[i][2-i] == 'O')
            o++;

        if(x == 3)
            return xPlayerWinner;
        else if(o == 3)
            return oPlayerWinner;
    }
    x = 0;
    o=0;
    // check draw
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(board[i][j] == 'z')
                return gameIsNotFinishedYet;
        }
    }
    return draw;
}

enum Player changePlayer(enum Player player)
{
    if(player == xPlayer)
        return oPlayer;
    else
        return xPlayer;
}
