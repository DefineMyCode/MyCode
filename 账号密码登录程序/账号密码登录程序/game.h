#define ROW 3 //ÐÐ
#define COL 3 //ÁÐ
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void menu();
void putboard(char arr[ROW][COL], int row, int col);
char inspect(char arr[ROW][COL], int x, int y);
void computermove(char arr[ROW][COL], int row, int col);
void playermove(char arr[ROW][COL], int row, int col);
void game();

