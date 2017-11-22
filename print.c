#include <stdio.h>
#include <stdlib.h>
#include "lib2048.h"

void printGame(int array[4][4], int socre, int best)
{
    int i, j;
    system("cls");
    printf("\n\n\n\n");
       printf("\t\t################################################################################\n");
       printf("\t\t#                                                                              #\n");
       printf("\t\t#    Game 2048                                                                 #\n");
       printf("\t\t#               Score: %-9d              BEST: %-9d                  #\n", socre, best);
       printf("\t\t#                                                                              #\n");
       printf("\t\t#                                                                              #\n");
        for(i=0; i<4; i++)
        {
           printf("\t\t#                     -----------------------------                            #\n");
           printf("\t\t#                   | ");
            for(j=0; j<4; j++)
            {
                if(array[i][j] != 0)
                {
                    printf("|%6d", array[i][j]);
                }
                else
                {
                    printf("|      ");
                }
            }
            printf("| |                          #\n");
        }
       printf("\t\t#                     -----------------------------                            #\n");
       printf("\t\t#                                                                              #\n");
       printf("\t\t#                                                                              #\n");
       printf("\t\t#                                                                              #\n");
       printf("\t\t################################################################################\n");

}


void fprintGame(int array[4][4], char p)
{
    FILE *fp;
    fp = fopen("log.txt", "a");

    fprintf(fp, "\n\np:%c\n", p);
    int i, j;
    for(i=0; i<4; i++)
    {
        fprintf(fp, "  -----------------------------\n");
        fprintf(fp,"| ");
        for(j=0; j<4; j++)
        {
            if(array[i][j] != 0)
            {
                fprintf(fp,"|%6d", array[i][j]);
            }

            else
            {
                fprintf(fp,"|      ");

            }
        }
        fprintf(fp,"| |\n");
    }
    fprintf(fp,"  -----------------------------\n");
    fclose(fp);
}


void printStart()
{
    printf("\n\n\n\n\n");
    printf("\t\t################################################################################\n");
    printf("\t\t##                                                                            ##\n");
    printf("\t\t##                                                                            ##\n");
    printf("\t\t##       ************    ************    **        **    ************         ##\n");
    printf("\t\t##       ************    ************    **        **    ************         ##\n");
    printf("\t\t##                 **    **        **    **        **    **        **         ##\n");
    printf("\t\t##                 **    **        **    **        **    **        **         ##\n");
    printf("\t\t##                 **    **        **    **        **    **        **         ##\n");
    printf("\t\t##       ************    **        **    ************    ************         ##\n");
    printf("\t\t##       ************    **        **    ************    ************         ##\n");
    printf("\t\t##       **              **        **              **    **        **         ##\n");
    printf("\t\t##       **              **        **              **    **        **         ##\n");
    printf("\t\t##       **              **        **              **    **        **         ##\n");
    printf("\t\t##       ************    ************              **    ************         ##\n");
    printf("\t\t##       ************    ************              **    ************         ##\n");
    printf("\t\t##                                                                            ##\n");
    printf("\t\t##                       Any key to start GAME 2048                           ##\n");
    printf("\t\t################################################################################\n");
    getch();
}

void printScore(int score, int best)
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t################################################################################\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#               Your                                                           #\n");
    printf("\t\t#                      Score: %-9d                                        #\n", score);
    printf("\t\t#                      Best:  %-9d                                        #\n", best);
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t################################################################################\n");
    getch();
}




void printEnd(int score, int best)
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t################################################################################\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#    **********  **  **  ******        ******  ***    **  *****     ****       #\n");
    printf("\t\t#    **  **  **  **  **  **  **        **  **  ** *   **  **  **    ****       #\n");
    printf("\t\t#    *   **   *  ******  **            **      ** *   **  **   **    **        #\n");
    printf("\t\t#        **      ******  *****         *****   **  *  **  **    **   **        #\n");
    printf("\t\t#        **      **  **  **            **      **  *  **  **   **              #\n");
    printf("\t\t#        **      **  **  **  **        **  **  **   * **  **  **     **        #\n");
    printf("\t\t#        **      **  **  ******        ******  **    ***  *****      **        #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#               Your                                                           #\n");
    printf("\t\t#                      Score: %-9d                                        #\n", score);
    printf("\t\t#                      Best:  %-9d                                        #\n", best);
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t################################################################################\n");
    getch();
}

void printMenu()
{
    system("cls");
    printf("\n\n\n\n\n");
    printf("\t\t################################################################################\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                     ###   ###  ######  ###   ##  ##   ##                     #\n");
    printf("\t\t#                     ## # # ##  ##      ## #  ##  ##   ##                     #\n");
    printf("\t\t#                     ##  #  ##  ####    ## ## ##  ##   ##                     #\n");
    printf("\t\t#                     ##     ##  ##      ##  # ##  ##   ##                     #\n");
    printf("\t\t#                     ##     ##  ######  ##   ###   #####                      #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                           ***  New Game     (N)                              #\n");
    printf("\t\t#                           ***  Reload Game  (R)                              #\n");
    printf("\t\t#                           ***  Your Score   (Y)                              #\n");
    printf("\t\t#                           ***  Exit         (E)                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t#                                                                              #\n");
    printf("\t\t################################################################################\n");
}
