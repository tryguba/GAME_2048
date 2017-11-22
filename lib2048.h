#ifndef LIB2048_H_INCLUDED
#define LIB2048_H_INCLUDED

int newGame();
int startGame(int Table[4][4], int *score, int *best);
int Game(int Table[4][4], int *score, int *best);
int move(int mode, int array[4][4], int *score);
int endGame(int array[4][4]);
int exitGame(int array[4][4], int score);
int reloadGame(int array[4][4], int *score);
int creatNumber(int array[4][4]);
int Rondom(int min, int max);

void printGame(int array[4][4], int score, int best);
void fprintGame(int array[4][4], char op);
void printStart();
void printMenu();
void printScore(int score, int best);
void printEnd(int score, int best);


#endif
