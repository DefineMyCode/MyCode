#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include <mmsystem.h>//包含多媒体设备接口头文件
#pragma comment(lib,"winmm.lib") //加载静态库

#define	ROW 20	    //输出的行数
#define COL 20	    //输出的列数
#define ROWS ROW+2  //实际的行数
#define COLS COL+2	//实际的列数
#define MINE 100     //雷
#define SIZE 35

int map[ROWS][COLS];//0
IMAGE img[12];
int count = 0;      //翻开的格子个数

void mnue_MineCle()
{
	printf("          扫雷        \n");
	printf("**********************\n");
	printf("***   0.退出游戏   ***\n");
	printf("***   1.开始游戏   ***\n");
	printf("***   2.重玩上局   ***\n");
	printf("**********************\n");
}

//查找map[x][y]周围有几个雷
int FindMine(int x, int y)
{
	int i = x-1, j = y-1;
	int count = 0;
	for (;i <= x + 1;i++)
	{
		for (j = y - 1;j <= y + 1;j++)
		{
			if (map[i][j] == -1)
			{
				count++;
			}
		}
	}
	return count;
}

//初始化map
void InitMap(int map[ROWS][COLS])
{
	int count_mine = MINE;
	int x = 0, y = 0;
	
	for (x = 0;x < ROWS;x++)
	{
		for (y = 0;y < COLS;y++)
		{
			map[x][y] = 0;
		}
	}
	while (count_mine > 0)
	{
		x = rand() % ROW + 1;
		y = rand() % COL + 1;
		if (map[x][y] == 0)
		{
			map[x][y] = -1;
			count_mine--;
		}
	}
	for (x = 1;x <=ROW;x++)
	{
		for (y = 1;y <= COL;y++)
		{
			if(map[x][y] !=-1)
			map[x][y]=FindMine(x, y);
		}
	}

	//简单的加密
	for (x = 1;x <= ROW;x++)
	{
		for (y = 1;y <= COL;y++)
		{
			map[x][y] += 20;
		}
	}
}

//打印map
void PutMap(int map[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	for (x = 1;x <= row;x++)
	{
		for (y = 1;y <= row;y++)
		{
			//printf("%2d ", map[x][y]);
			/*********************************************
			元素                图片
			-1                  img[9] 雷
			0-8                        数字
			19-28               img[10]空白图片
			>30                 img[11]标记图片
			*********************************************/
			if (map[x][y] == -1)
			{
				putimage((x - 1)*SIZE, (y - 1)*SIZE, &img[9]);       //雷
			}
			else if (map[x][y] >= 0 && map[x][y] <= 8)
			{
				putimage((x - 1)*SIZE, (y - 1)*SIZE, &img[map[x][y]]);//数字
			}
			else if (map[x][y] >= 19 && map[x][y] <= 28)
			{
				putimage((x - 1)*SIZE, (y - 1)*SIZE,&img[10]);//空白图片
			}
			else if (map[x][y] > 30)
			{
				putimage((x - 1)*SIZE, (y - 1)*SIZE, &img[11]);//标记图片
			}
		}
		printf("\n");
	}
}

//翻开map[x][y]周围的块
void FindRound(int x,int y)
{
	int i, j;
	for (i = x - 1;i <= x + 1;i++)
	{
		for (j = y - 1;j <= y + 1;j++)
		{
			if (map[i][j] >= 19 && map[i][j] <= 28)
			{
				map[i][j] -= 20;
				count++;
				if (map[i][j] == 0)
				{
					FindRound(i, j);
				}
			}
		}
	}
}

int PalyGame()
{
	//定义一个鼠标消息
	MOUSEMSG msg = { 0 };
	int x = 0, y = 0;
	while (1)
	{
		msg = GetMouseMsg();
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:        //翻开扫雷  空白图片
			
			x = msg.x / SIZE + 1;
			y = msg.y / SIZE + 1;
			
			if (map[x][y] >= 19 && map[x][y] <= 28)
			{
				map[x][y] -= 20;
				count++;
				if (map[x][y] == 0)
				{
					FindRound(x, y);
				}
				
			}
			PutMap(map, ROW, COL);
			return map[x][y];
			break;
		case WM_RBUTTONDOWN:        //标记一个空白图片  取消一个标记图片
			x = msg.x / SIZE + 1;
			y = msg.y / SIZE + 1;
			if (map[x][y] >= 19 && map[x][y] <= 28)
			{
				map[x][y] += 50;
				PutMap(map, ROW, COL);
				
				
			}
			else if (map[x][y] > 30)
			{
				map[x][y] -= 50;
				PutMap(map, ROW, COL);
				
			}
			return map[x][y];
			break;
		}
	}
}

void InitMapaga(int map[ROWS][COLS])
{
	int x, y;
	for (x = 1;x <= ROW;x++)
	{
		for (y = 1;y <= COL;y++)
		{
			if (map[x][y] > 29)
			{
				map[x][y] -= 50;
			}
			else if(map[x][y]>=-1&&map[x][y]<=8)
			{
				map[x][y] += 20;
			}
		}
	}
}
void MineCle()
{
	InitMap(map);
	HWND hwnd=initgraph(ROW*SIZE, COL*SIZE, SHOWCONSOLE);//返回窗口句柄
	PutMap(map, ROW, COL);
	count = 0;
	while (1)
	{
		PutMap(map, ROW, COL);
		if (PalyGame() == -1)
		{
			int x, y;
			MessageBox(hwnd, L"你踩到雷了，游戏结束", L"", MB_OK);
			
			for (x = 1;x <= ROW;x++)
			{
				for (y = 1;y <= COL;y++)
				{
					if (map[x][y] == 19)
					{
						map[x][y] -= 20;
					}
					if (map[x][y] > 28)
					{
						map[x][y] -= 70;
					}
				}
			}
			PutMap(map, ROW, COL);
			break;
		}
		if (ROW * COL - MINE == count)
		{
			PutMap(map, ROW, COL);
			MessageBox(hwnd, L"你成功的躲开了所有雷", L"", MB_OK);
			break;
		}
	}
}

void MineCleagain()
{
	if (count != 0)
	{
		InitMapaga(map);
		count = 0;
		HWND hwnd = initgraph(ROW*SIZE, COL*SIZE, SHOWCONSOLE);//返回窗口句柄
		PutMap(map, ROW, COL);
		
		while (1)
		{
			PutMap(map, ROW, COL);
			if (PalyGame() == -1)
			{
				int x, y;
				MessageBox(hwnd, L"你踩到雷了，游戏结束", L"", MB_OK);
				
				for (x = 1;x <= ROW;x++)
				{
					for (y = 1;y <= COL;y++)
					{
						if (map[x][y] == 19)
						{
							map[x][y] -= 20;
						}
						if (map[x][y] > 28)
						{
							map[x][y] -= 70;
						}
					}
				}
				PutMap(map, ROW, COL);
				break;
			}
			if (ROW * COL - MINE == count)
			{
				PutMap(map, ROW, COL);
				MessageBox(hwnd, L"你成功的躲开了所有雷", L"", MB_OK);
				break;
			}
		}
	}
	else
	{
		printf("暂无上局数据（退出程序不会保存数据）\n");
	}
}

int main()
{
	int input = 0;
	int i = 0;
	srand((unsigned int)time(NULL));
	//加载音乐
	
	
	/*for (i = 0;i < 12;i++)
	{
		LOADIMAGE(i);
	}*/
	loadimage(&img[0], L"./0.jpg", SIZE, SIZE);
	loadimage(&img[1], L"./1.jpg", SIZE, SIZE);
	loadimage(&img[2], L"./2.jpg", SIZE, SIZE);
	loadimage(&img[3], L"./3.jpg", SIZE, SIZE);
	loadimage(&img[4], L"./4.jpg", SIZE, SIZE);
	loadimage(&img[5], L"./5.jpg", SIZE, SIZE);
	loadimage(&img[6], L"./6.jpg", SIZE, SIZE);
	loadimage(&img[7], L"./7.jpg", SIZE, SIZE);
	loadimage(&img[8], L"./8.jpg", SIZE, SIZE);
	loadimage(&img[9], L"./9.jpg", SIZE, SIZE);
	loadimage(&img[10], L"./10.jpg", SIZE, SIZE);
	loadimage(&img[11], L"./11.jpg", SIZE, SIZE);
	
	do
	{
		mnue_MineCle();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 2:MineCleagain();
			break;
		case 1:MineCle();
			break;
		case 0:
			break;
		default:printf("输入错误请重新输入\n");
			break;
		}
	} while (input);
	

	return 0;
}