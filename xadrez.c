#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

/*
Chess Challenge - MateCheck
The goal is to practice loops structures and functions to create a basic system to move chess pieces.
*/

typedef struct piece
{
    int id;
    int move;
    int squares;
    int x;
    int y;
}piece;

piece tower;
piece horse;
piece queen;
piece bispho;

// Global variables
#define HORSE_MOVE 2
#define MAX_MOVE 7
char restart;

// Functions prototypes
void move_forward(int y);
void move_backward(int y);
void move_left(int x);
void move_right(int x);
void move_diagonal(int squares, int move);
void move_l(int x);
void title(char *text);

int main()
{

    do
    {
        int piece = 0;
        
        title("GAME START");
        printf("In this chess game, we have these pieces:\n");
        printf("[1] Bispho\n");
        printf("[2] Tower\n");
        printf("[3] Queen\n");
        printf("[4] Horse\n");
        printf("Which piece you wanto to move? ");
        scanf("%i", &piece);
        
        switch (piece)
        {
            case 1:
                // Bispho
                do
                {
                    printf("\n");
                    printf("How many squares do you want to 'walk'? ");
                    scanf("%i", &bispho.squares);
                }
                while (bispho.squares > MAX_MOVE);
                
                printf("\n");
                printf("Bisphos just make diagonal moviments.\n");
                printf("[1] Diagonal left-up\n");
                printf("[2] Diagonal left-down\n");
                printf("[3] Diagonal right-up\n");
                printf("[4] Diagonal right-down\n");
                printf("Which moviment do you want to do? ");
                scanf("%i", &bispho.move);

                move_diagonal(bispho.squares, bispho.move);

                break;
            
            case 2:
                // Tower
                do
                {
                    printf("\n");
                    printf("How many squares do you want to 'walk'? ");
                    scanf("%i", &tower.squares);
                }
                while (tower.squares > MAX_MOVE);
                
                printf("\n");
                printf("Tower can make foreward, backward, lef and right moviments.\n");
                printf("[1] Forward\n");
                printf("[2] Backward\n");
                printf("[3] Left\n");
                printf("[4] Right\n");
                printf("Which moviment do you want to do? ");
                scanf("%i", &tower.move);

                switch (tower.move)
                {
                case 1:
                    move_forward(tower.squares);
                    break;
                case 2:
                    move_backward(tower.squares);
                    break;
                case 3:
                    move_right(tower.squares);
                    break;
                case 4:
                    move_left(tower.squares);
                    break;
                default:
                    printf("Invalid option.\n");
                    break;
                }
                break;
            case 3:
                // Queen
                do
                {
                    printf("\n");
                    printf("How many squares do you want to 'walk'? ");
                    scanf("%i", &queen.squares);
                }
                while (queen.squares > MAX_MOVE);
                
                printf("\n");
                printf("Queen can make diagonal, foreward, backward, lef and right moviments.\n");
                printf("[1] Forward\n");
                printf("[2] Backward\n");
                printf("[3] Left\n");
                printf("[4] Right\n");
                printf("[5] Diagonal\n");
                printf("Which moviment do you want to do? ");
                scanf("%i", &queen.move);

                switch (queen.move)
                {
                case 1:
                    move_forward(queen.squares);
                    break;
                case 2:
                    move_backward(queen.squares);
                    break;
                case 3:
                    move_right(queen.squares);
                    break;
                case 4:
                    move_left(queen.squares);
                    break;
                case 5:
                    printf("\n");
                    printf("[1] Diagonal left-up\n");
                    printf("[2] Diagonal left-down\n");
                    printf("[3] Diagonal right-up\n");
                    printf("[4] Diagonal right-down\n");
                    printf("To which direction? \n");
                    scanf("%i", &queen.move);

                    move_diagonal(queen.squares, queen.move);
                    break;
                default:
                    printf("Invalid option.\n");
                    break;
                }
                break;
            case 4:
                // Horse
                printf("\n");
                printf("Horses just make L moviments.\n");
                printf("[1] Forward-left  (↰)\n");
                printf("[2] Forward-right (↱)\n");
                printf("[3] Backward-left (↵)\n");
                printf("[4] Backward-right(↳)\n");
                printf("Which moviment do you want to do? ");
                scanf("%i", &horse.move);
                
                move_l(horse.move);
                break;
                
            default:
                printf("Invalid option. Use just numbers between menu range.");
                break;
        }
        
        title("THE END");
        printf("Play again [y/n]? ");
        scanf(" %c", &restart);
    }
    while(restart == 'y');
}

// Functions

void move_forward(int y)
{
    if (y != 0)
    {
        printf("Forward (↑)\n");
        move_forward(y - 1);
    }
}

void move_backward(int y)
{
    if (y != 0)
    {
        printf("Backward (↓)\n");
        move_backward(y - 1);
    }
}

void move_left(int x)
{
    for(int i = 0; i < x; i++)
    {
        printf("Left (←)\n");
    }
}

void move_right(int x)
{
    for(int i = 0; i < x; i++)
    {
        printf("Right (→)\n");
    }
}

void move_diagonal(int squares, int move)
{
    int moviment = squares;

    if (move == 1)
    {
        // Left-up
        do
        {
            printf("Diagonal (↖︎)\n");
            moviment--;
        } 
        while (moviment != 0);
    }
    if (move == 2)
    {
        // Left-down
        do
        {
            printf("Diagonal (↙︎)\n");
            moviment--;
        } 
        while (moviment != 0);
    }
    if (move == 3)
    {
        // Right-up
        do
        {
            printf("Diagonal (↗︎)\n");
            moviment--;
        } 
        while (moviment != 0);
    }
    if (move == 4)
    {
        // Right-down
        do
        {
            printf("Diagonal (↘︎)\n");
            moviment--;
        } 
        while (moviment != 0);
    }
}

void move_l(int x)
{
    if (x == 1)
    {
        // ↰
        move_forward(HORSE_MOVE);
        move_left(HORSE_MOVE - 1);
    }
    if (x == 2)
    {
        // ↱
        move_forward(HORSE_MOVE);
        move_right(HORSE_MOVE - 1);
    }
    if (x == 3)
    {   
        // ↵
        move_backward(HORSE_MOVE);
        move_left(HORSE_MOVE - 1);
    }
    if (x == 4)
    {
        // ↳
        move_backward(HORSE_MOVE);
        move_right(HORSE_MOVE - 1);
    }
}

void title(char *text)
{
    printf("\n");
    printf("------------ %s ------------\n", text);
    printf("\n");
}