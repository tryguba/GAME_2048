#include <stdio.h>
#include <stdlib.h>

int main()
{
    char p;
    printStart();
    int score = 0, best = 0;
    int Table[4][4] = {NULL};
    startGame(Table, &score, &best);
    return 0;
}
