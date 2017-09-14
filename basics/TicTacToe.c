
#include <stdio.h>

char tab[10] = {' ', '_', '_', '_', '_', '_', '_', '_', '_', '_'};
int turn = 0;
int whoStart = 1;

int win(int accessMode);

/*====================================================================*\

 
                          Functions                                 *
 
====================================================================*
 
 Name: draw                                                         *
 
                                                                    *
 
 Role: display the grid and calls win() function.                   *
 
                                                                    *
 
 Arguments: int x -> position on the grid.                          *
 
            int who -> who play.                                    *
 
                                                                    *
 
 infos: int whoStart switch the starting sequence Player/Computer.  *

\*====================================================================*/

void draw(int x, int who)
{
    if (who)
        tab[x] = 'X';
    else
    {
        tab[x] = 'O';
        puts("Computer:");
    }
    printf("\n     %c %c %c\n     %c %c %c\n     %c %c %c\n",
           tab[1], tab[2], tab[3],
           tab[4], tab[5], tab[6],
           tab[7], tab[8], tab[9]);
    win(0);
    whoStart++;
}

/*====================================================================*\

 
 Name: reset                                                        *         
 
                                                                    *
 
 Role: reset the game.                                              *

\*====================================================================*/

void reset()
{
    int i = 0;
    turn = 0;

    for (i = 1; i <= 10; i++)
        tab[i] = '_';
}

/*====================================================================*\

 
 Name: win                                                          *
 
                                                                    *
 
 Roles: Check for winning combinations (accessMode=0).              *
 
        It's also used by Computer to calculate                     *
 
        its next move (accesMode=1).                                *
 
                                                                    *
 
 Arguments: int accessMode -> prevent the execution of              *
 
              a part of the function when accessed for              *
 
              simulations purposes by Computer.                     *
 
                                                                    *
 
 Returned value: int whoWin -> used by evaluate()                   *

\*====================================================================*/

int win(int accessMode)
{
    int whoWin = 0, i = 1, drawGame = 0;
    static int yourScore = 0, computerScore = 0;

    tab[1] + tab[4] + tab[7] == 3 * 'X' ? whoWin = 1 : tab[1] + tab[4] + tab[7] == 3 * 'O' ? whoWin = 2 : tab[2] + tab[5] + tab[8] == 3 * 'X' ? whoWin = 1 : tab[2] + tab[5] + tab[8] == 3 * 'O' ? whoWin = 2 : tab[3] + tab[6] + tab[9] == 3 * 'X' ? whoWin = 1 : tab[3] + tab[6] + tab[9] == 3 * 'O' ? whoWin = 2 : tab[1] + tab[2] + tab[3] == 3 * 'X' ? whoWin = 1 : tab[1] + tab[2] + tab[3] == 3 * 'O' ? whoWin = 2 : tab[4] + tab[5] + tab[6] == 3 * 'X' ? whoWin = 1 : tab[4] + tab[5] + tab[6] == 3 * 'O' ? whoWin = 2 : tab[7] + tab[8] + tab[9] == 3 * 'X' ? whoWin = 1 : tab[7] + tab[8] + tab[9] == 3 * 'O' ? whoWin = 2 : tab[1] + tab[5] + tab[9] == 3 * 'X' ? whoWin = 1 : tab[1] + tab[5] + tab[9] == 3 * 'O' ? whoWin = 2 : tab[3] + tab[5] + tab[7] == 3 * 'X' ? whoWin = 1 : tab[3] + tab[5] + tab[7] == 3 * 'O' ? whoWin = 2 : printf("");
    if (whoWin == 0)
    {
        for (i = 1; i <= 10; i++)
        {
            if (tab[i] == 'X' || tab[i] == 'O')
                drawGame++;
            if (drawGame == 9)
                whoWin = 3;
        }
    }

    if ((whoWin != 0) && (accessMode == 0))
    {
        reset();
        if (whoWin == 3 || whoWin == 1 || whoWin == 2)
        {
            whoWin == 1 ? puts("\nYou Win!"), ++yourScore : whoWin == 2 ? puts("\nComputer Win!"), ++computerScore : puts("\nDraw Game!");
            printf("\nScores:\n You: %d  Computer: %d\n",
                   yourScore, computerScore);
        }
    }
    return whoWin;
}

/*====================================================================*\

 
 Name: evaluate                                                     *
 
                                                                    *
 
 Role: Determine the best next move after turn 4 (in order):        *
 
       - Can Computer win next turn?                                *
 
       - Can Player win next turn?                                  *
 
       - Can Computer play a winning turn+2 position?               *
 
       - Can Player play a winning turn+2 position?                 *
 
       - If none of above, 3 default positions are used.            *
 
                                                                    *
 
 Returned value: int i -> The position to be played,                *
 
                          used by computer().                       *
 
                                                                    *
 
 Infos: defAttack and defDefence are intermediate values            *
 
        used for default positions.                                 *

\*====================================================================*/

int evaluate()
{
    int i = 0, y = 0, eval = 0, flag = 0;
    static int defAttack = 0, defDefence = 0;

    for (i = 1; i <= 10; i++)
    {
        if (tab[i] == '_')
        {
            tab[i] = 'O';
            eval = win(1);
            tab[i] = '_';
            if (eval == 2)
            {
                //  printf("The first evaluate() returned: %d", i);
                return i;
            }
        }
    }
    for (i = 1; i <= 10; i++)
    {
        if (tab[i] == '_')
        {
            tab[i] = 'X';
            eval = win(1);
            tab[i] = '_';
            if (eval == 1)
            {
                // printf("The second evaluate() returned: %d", i);
                return i;
            }
        }
    }
    for (i = 1; i <= 10; i++)
    {
        if (tab[i] == '_')
        {
            tab[i] = 'O';
            for (y = 1; y <= 10; y++)
            {
                if (tab[y] == '_')
                {
                    tab[y] = 'O';
                    eval = win(1);
                    tab[y] = '_';
                    if (eval == 2)
                    {
                        // printf("Third evaluate is flagged with i=%d and y=%d",i,y);
                        flag++;
                    }
                }
                if (flag == 2)
                {
                    //printf("The third evaluate() returned: %d", i);
                    return i;
                    break;
                }
                if (flag == 1)
                {
                    defAttack = i;
                }
            }
            tab[i] = '_';
            flag = 0;
        }
    }

    for (i = 1; i <= 10; i++)
    {
        if (tab[i] == '_')
        {
            tab[i] = 'X';
            for (y = 1; y <= 10; y++)
            {
                if (tab[y] == '_')
                {
                    tab[y] = 'X';
                    eval = win(1);
                    tab[y] = '_';
                    if (eval == 1)
                    {
                        //printf("Fourth evaluate is flagged with i=%d and y=%d",i,y);
                        flag++;
                    }
                }
                if (flag == 2)
                {
                    // printf("The fourth evaluate() returned: %d", i);
                    return i;
                    break;
                }
                else if (flag == 1)
                    defDefence = i;
            }
            tab[i] = '_';
            flag = 0;
        }
    }

    if (tab[defDefence] == '_')
    {
        printf("Default Defence: %d", defDefence);
        return defDefence;
    }

    if (tab[defAttack] == '_')
    {
        printf("Default Attack: %d", defAttack);
        return defAttack;
    }

    else
    {
        for (i = 1; i <= 10; i++)
            if (tab[i] == '_')
            {
                printf("Default position: %d", i);
                return i;
            }
    }
}

/*====================================================================*\

 
 Name: computer                                                     *
 
                                                                    *
 
 Role: Basic Computer behavior.                                     *

\*====================================================================*/

void computer()
{
    if (turn == 1)
        draw(1, 0);

    if ((turn == 2) && (tab[5] == 'X'))
        tab[9] == '_' ? draw(9, 0) : draw(7, 0);

    if ((turn == 2) && (tab[5] != 'X'))
        tab[5] == '_' ? draw(5, 0) : draw(2, 0);

    if ((turn == 3) && (tab[1] == 'O'))
        tab[6] == '_' ? draw(6, 0) : tab[8] == '_' ? draw(8, 0) : draw(5, 0);

    if ((turn == 4) && (tab[5] == 'O') &&
        ((tab[1] == 'X' && tab[9] == 'X') || (tab[3] == 'X' && tab[7] == 'X')))
        tab[8] == '_' ? draw(8, 0) : tab[4] == '_' ? draw(4, 0) : draw(2, 0);

    if ((turn == 4) && (tab[1] == 'X' && tab[5] == 'X'))
        tab[3] == '_' ? draw(3, 0) : draw(7, 0);

    else if (turn > 4)
        draw(evaluate(), 0);
}

/*====================================================================*\

 
 Name: main                                                         *
 
                                                                    *
 
 Role: Main loop.                                                   *
 
                                                                    *
 
 Infos: (L.313) player=0 each turn to avoid unwanted values.        *

\*====================================================================*/

int main(int argc, char *argv[])
{
    int player = 0;

    puts("*** Welcome to TicTacToe ***\nSelect a position by using numbers:");
    puts("\n     1 2 3\n     4 5 6\n     7 8 9");
    while (1)
    {
        turn++, player = 0;
        if (whoStart % 2 == 0)
        {
            while (tab[player] != '_')
            {
                puts("\nYou:");
                scanf("%d", &player);
            }
            draw(player, 1);
        }
        else
            computer();
    }
    puts("\n\n");
    return 0;
}

/*====================================================================*\

 
                        END OF SOURCE CODE                          *

\*====================================================================*/