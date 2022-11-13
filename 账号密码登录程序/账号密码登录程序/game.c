#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"
void menu()
{
	printf("**********************\n");
	printf("**1.开始游戏  0.退出**\n");
	printf("**********************\n");
}
void putboard(char arr[ROW][COL], int row, int col)
{
	int i, j;
	printf("\n");
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (j == 0) printf(" %c ", arr[i][j]);
			else printf("| %c ", arr[i][j]);
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0;j < col;j++)
			{
				if (j == 0) printf("---");
				else printf("|---");
			}
		}
		printf("\n");
	}
}

char inspect(char arr[ROW][COL])
{
	int x, y;
	for (x = 0;x < ROW;x++)
	{
		if (arr[x][0] == arr[x][1] && arr[x][1] == arr[x][2] && arr[x][2] != ' ')
		{
			return arr[x][2];
		}
	}
	for (y = 0;y < COL;y++)
	{
		if (arr[0][y] == arr[1][y] && arr[1][y] == arr[2][y] && arr[2][y] != ' ')
		{
			return arr[2][y];
		}
	}
	if (arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[2][2] != ' ')
	{
		return arr[2][2];
	}
	if (arr[0][2] == arr[1][1] && arr[1][1] == arr[2][0] && arr[2][0] != ' ')
	{
		return arr[2][0];
	}
	for (x = 0;x < ROW;x++)
		for (y = 0;y < COL;y++)
			if (arr[x][y] == ' ') return 'C';
	return 'P';
	
}
void playermove(char arr[ROW][COL], int row, int col)
{
	int x, y;
	while (1)
	{
		printf("玩家移动\n");
		printf("请输入坐标:");
		scanf("%d%d", &x, &y);
		if (x<1 || x>ROW || y<1 || y>ROW||arr[x-1][y-1]!=' ')
		{
			printf("输入的坐标非法\n"); 
			continue;
		}
			arr[x-1][y-1] = '*';break;
	}
}
void computermove(char arr[ROW][COL], int row, int col)
{
	int x, y;
	printf("电脑移动\n");
	while (1)
	{	
		x = rand() % row;
		y = rand() % col;
		if (arr[x][y] != ' ')
		{
			continue;
		}
		arr[x][y]= '#';break;
	}
}

void game()
{
	int i, j;
	char arr[ROW][COL];
	for (i = 0;i < ROW;i++)//棋盘初始化
	{
		for (j = 0;j < COL;j++)
		{
			arr[i][j] = ' ';
		}
	}
	putboard(arr, ROW, COL);//打印棋盘
	while (1)
	{	
		char ch;
		playermove(arr, ROW, COL);
		putboard(arr, ROW, COL);
		ch=inspect(arr);
		if (ch == '*')
		{
			printf("玩家赢\n");break;
		}
		else if(ch == '#')
		{
			printf("电脑赢\n");break;
		}
		else if (ch == 'P')
		{
			printf("平局\n");break;
		}
		computermove(arr, ROW, COL);
		putboard(arr, ROW, COL);
		ch = inspect(arr);
		if (ch == '*')
		{
			printf("玩家赢\n");break;
		}
		else if (ch == '#')
		{
			printf("电脑赢\n");break;
		}
		else if (ch == 'P')
		{
			printf("平局\n");break;
		}
	}
}



