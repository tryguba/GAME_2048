#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include "lib2048.h"

int startGame(int Table[4][4], int *score, int *best)
{
    int i, j, besttemp, played = 0;
    char p;

    FILE *fp;
    fp = fopen("best_log.txt", "r");

    if(fp)
    {
        fscanf(fp,"%d", &besttemp);
        fclose(fp);
        if(*best < besttemp)
            *best = besttemp;
    }
    printMenu();
    while(1)
    {
        p = getch();
             if(p == 'N' || p == 'n')
            break;
        else if(p == 'R' || p == 'r')
            break;
        else if(p == 'Y' || p == 'y')
            break;
        else if(p == 'E' || p == 'e')
            break;
    }
    switch(p)
    {
    case 'n':
        ;
    case 'N':
        played = 1;
        for(i=0; i<4; i++)
        {
            for(j=0;j<4;j++)
            {
                Table[i][j] = 0;
            }
        }
        creatNumber(Table);
        creatNumber(Table);
        Game(Table, score, best);
        break;

    case 'r':
        ;
    case 'R':
        played = 1;
        if(reloadGame(Table, score))
            Game(Table, score, best);
        else
        {
            for(i=0; i<4; i++)
            {
                for(j=0;j<4;j++)
                {
                    Table[i][j] = 0;
                }
            }
            creatNumber(Table);
            creatNumber(Table);
            Game(Table, score, best);
        }
        break;

    case 'y':
        ;
    case 'Y':
        printScore(*score, *best);
        break;

    case 'e':
        ;
    case 'E':
        if(played != 1)
        {
            reloadGame(Table, score);
            exitGame(Table, *score);
        }
        fp = fopen("best_log.txt", "w");
        if(fp)
        {
            fprintf(fp,"%d", *best);
            fclose(fp);
        }

        exit(1);
        break;
    }

    if(p == 'Y' || p == 'y')
        startGame(Table, score, best);
}

int Game(int Table[4][4], int *score, int *best)
{
    int exitgame = 0;
    int endgame;
    int moved = 0;
    int p;
    if(*score > *best)
        *best = *score;

    /* start game */
    do
    {
        int i, j;

        if(*score > *best)
            *best = *score;
        printGame(Table, *score, *best);
        fprintGame(Table,p);
        p = getKey();
        switch(p)
        {
        case 1:
            moved = move(1, Table, score);
            break;

        case 2:
            moved = move(2, Table, score);
            break;

        case 3:
            moved = move(3, Table, score);
            break;

        case 4:
            moved = move(4, Table, score);
            break;

        case 5:
            exitGame(Table, *score);
            exitgame = 1;
            break;
        }

    //if there is a going, creating a number
        if(moved == 1)
            creatNumber(Table);
        moved = 0;

    }while(endGame(Table) && !exitgame);
    system("cls");
        printGame(Table, *score, *best);

    if(*score > *best)
        *best = *score;
    endGame(Table);
    printEnd(*score, *best);
    startGame(Table, score, best);
}

int move(int mode, int array[4][4], int *score)
{
    int i, j, z, moved = 0;
    if((mode /4) > 1 && (mode /4)<0)
        return 0;
    else
    {
        switch(mode)
        {
        //going from left to right
        case 1:
            for(i=0; i<4;i++)
            {
                /* add */
                j = 0;
                while(j <= 2)
                {
                    if(array[i][j] != 0)
                    {
                        z = j + 1;
                        while(z <= 3)
                        {
                            if(array[i][j] == array[i][z])
                            {
                                *score = *score + array[i][j];
                                array[i][j] = array[i][j] + array[i][z];
                                array[i][z] = 0;
                                j = z + 1;
                                moved = 1;
                                break;
                            }
                            else if(array[i][z] == 0)
                                z++;
                            else
                            {
                                j = z;
                                break;
                            }
                        }
                        j = z;
                    }
                    else
                        j++;
                }


                /* move Together */
                j=1;
                while(j<=3)
                {
                    if(array[i][j] != 0)
                    {
                        if(array[i][j-1] == 0)
                        {
                            array[i][j-1] = array[i][j];
                            array[i][j] = 0;
                            j = 1;
                            moved = 1;
                        }
                        else
                            j++;
                    }
                    else
                        j++;
                }
            }
            break;
            // going from right to left
        case 2:
            for(i=0; i<4;i++)
            {
                /* add */
                j = 3;
                while(j >= 1)
                {
                    if(array[i][j] != 0)
                    {
                        z = j -1;
                        while(z >= 0)
                        {
                            if(array[i][z] == array[i][j])
                            {
                                *score = *score + array[i][j];
                                array[i][j] = array[i][j] + array[i][z];
                                array[i][z] = 0;
                                j = z -1;
                                moved = 1;
                                break;
                            }
                            else if (array[i][z] == 0)
                                z--;
                            else
                            {
                                j = z;
                                break;
                            }
                        }
                        j = z;
                    }
                    else
                        j--;
                }

                /* move together */
                j = 2;
                while(j >= 0)
                {
                    if(array[i][j] != 0)
                    {
                        if(array[i][j+1] == 0)
                        {
                            array[i][j+1] = array[i][j];
                            array[i][j] = 0;
                            j = 2;
                            moved = 1;
                        }
                        else
                            j--;
                    }
                    else
                        j--;
                }
            }

            break;
            // going from up to down
        case 3:
            for(i=0; i<4;i++)
            {
                /* add */
                j = 0;
                while(j <= 2)
                {
                    if(array[j][i] != 0)
                    {
                        z = j+1;
                        while(z <= 3)
                        {
                            if(array[z][i] == array[j][i])
                            {
                                *score = *score + array[j][i];
                                array[j][i] = array[j][i] + array[z][i];
                                array[z][i] = 0;
                                j = z + 1;
                                moved = 1;
                                break;
                            }
                            else if(array[z][i] == 0)
                            {
                                z++;
                            }
                            else
                            {
                                j = z;
                                break;
                            }
                        }
                        j = z;
                    }
                    else
                        j++;
                }

                /* move together */
                j = 1;
                while(j <= 3)
                {
                    if(array[j][i] != 0)
                    {
                        if(array[j-1][i] == 0)
                        {
                            array[j-1][i] = array[j][i];
                            array[j][i] = 0;
                            j = 1;
                            moved = 1;
                        }
                        else
                            j++;
                    }
                    else
                        j++;
                }
            }
            break;
            // going from down to up
        case 4:
            for(i=0; i<4;i++)
            {
                /* add */
                j = 3;
                while(j >= 1)
                {
                    if(array[j][i] != 0)
                    {
                        z = j -1;
                        while(z >= 0)
                        {
                            if(array[z][i] == array[j][i])
                            {
                                *score = *score + array[j][i];
                                array[j][i] = array[j][i] + array[z][i];
                                array[z][i] = 0;
                                j = z  - 1;
                                moved = 1;
                                break;
                            }
                            else if(array[z][i] == 0)
                            {
                                z--;
                            }
                            else
                            {
                                j = z;
                                break;
                            }
                        }
                        j = z;
                    }
                    else
                        j--;
                }

                /* move together */
                j = 2;
                while( j>= 0)
                {
                    if(array[j][i] != 0)
                    {
                        if(array[j+1][i] == 0)
                        {
                            array[j+1][i] = array[j][i];
                            array[j][i] = 0;
                            j = 2;
                            moved = 1;
                        }
                        else
                            j--;
                    }
                    else
                        j--;
                }
            }
            break;
        }
    }

    if(moved == 1)
        return 1;
    else
        return 0;
}

int endGame(int array[4][4])
{
    int i, j;
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(array[i][j] != 0)
            {
                if((i-1) > 0)
                    if(array[i][j] == array[i-1][j])
                        return 1;
                if((j-1) > 0)
                    if(array[i][j] == array[i][j-1])
                        return 1;
                if((i+1) < 4)
                    if(array[i+1][j] == array[i][j])
                        return 1;
                if((j+1) < 4)
                    if(array[i][j+1] == array[i][j])
                        return 1;
            }
            else
                return 1;
        }
    }
    return 0;
}

int exitGame(int array[4][4], int score)
{
    FILE *fp;
    fp = fopen("last_log.txt", "w");
    fprintf(fp,"%d ", score);
    int i, j;
    for(i=0; i<4; i++)
    {
        fprintf(fp,"\n");
        for(j=0; j<4;j++)
        {
            fprintf(fp,"%d, ", array[i][j]);
        }
    }
    fclose(fp);
    return 1;
}

int reloadGame(int array[4][4], int *score)
{
    FILE *fp;
    fp = fopen("last_log.txt", "r");
    if(fp)
    {
        fscanf(fp,"%d  ", score);
        int i, j;
        for(i = 0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                fscanf(fp,"%d, ", &array[i][j]);
            }
        }
        return 1;
    }
    else
        return 0;
}

int creatNumber(int array[4][4])
{
    int count = 0;
    count ++;
    int upDate[16][2];
    int maxMark = 0;
    int i, j;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            if(array[i][j] == 0)
            {
                upDate[maxMark][1] = i;
                upDate[maxMark][2] = j;
                maxMark++;
            }
        }
    }

    int getRondom = Rondom(1, maxMark);
    if(Rondom(0,9))
        array[upDate[getRondom-1][1]][upDate[getRondom-1][2]] = 2;
    else
        array[upDate[getRondom-1][1]][upDate[getRondom-1][2]] = 4;
        return 1;
}

/* create Rondom number */
int Rondom(int min, int max)
{
    srand(time(NULL));
    int randomNumber= rand() % max;

    if(randomNumber < min)
        randomNumber = randomNumber + min;
    return randomNumber;
}

/* get key */

int getKey()
{
    char ch;

    while(1)
    {
            ch = getch();
            if((ch >= 'A' && ch <= 'Z') || (ch >='a' && ch <= 'z'))
            {
                switch(ch)
                {
                    /* left */
                case 'A':
                    ;
                case 'a':
                    return 1;
                    break;
                    /* right */
                case 'D':
                    ;
                case 'd':
                    return 2;
                    break;
                    /* up */
                case 'W':
                    ;
                case 'w':
                    return 3;
                    break;
                    /* down */
                case 'S':
                    ;
                case 's':
                    return 4;
                    break;

                case 'Q':
                    ;
                case 'q':
                    return 5;
                    break;
                }
            }
            else
            {
                ch = getch();
                switch(ch)
                {
                    /* left */
                case 75:
                    return 1;
                break;
                    /* right */
                case 77:
                    return 2;
                    break;
                    /* up */
                case 72:
                    return 3;
                    break;
                    /* down */
                case 80:
                    return 4;
                    break;
                }
            }
    }

}

