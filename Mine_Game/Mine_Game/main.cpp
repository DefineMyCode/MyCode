#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <graphics.h>
#include <mmsystem.h>//������ý���豸�ӿ�ͷ�ļ�
#pragma comment(lib,"winmm.lib") //���ؾ�̬��

#define	ROW 20	    //���������
#define COL 20	    //���������
#define ROWS ROW+2  //ʵ�ʵ�����
#define COLS COL+2	//ʵ�ʵ�����
#define MINE 100     //��
#define SIZE 35

int map[ROWS][COLS];//0
IMAGE img[12];
int count = 0;      //�����ĸ��Ӹ���

void mnue_MineCle()
{
	printf("          ɨ��        \n");
	printf("**********************\n");
	printf("***   0.�˳���Ϸ   ***\n");
	printf("***   1.��ʼ��Ϸ   ***\n");
	printf("***   2.�����Ͼ�   ***\n");
	printf("**********************\n");
}

//����map[x][y]��Χ�м�����
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

//��ʼ��map
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

	//�򵥵ļ���
	for (x = 1;x <= ROW;x++)
	{
		for (y = 1;y <= COL;y++)
		{
			map[x][y] += 20;
		}
	}
}

//��ӡmap
void PutMap(int map[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	for (x = 1;x <= row;x++)
	{
		for (y = 1;y <= row;y++)
		{
			//printf("%2d ", map[x][y]);
			/*********************************************
			Ԫ��                ͼƬ
			-1                  img[9] ��
			0-8                        ����
			19-28               img[10]�հ�ͼƬ
			>30                 img[11]���ͼƬ
			*********************************************/
			if (map[x][y] == -1)
			{
				putimage((x - 1)*SIZE, (y - 1)*SIZE, &img[9]);       //��
			}
			else if (map[x][y] >= 0 && map[x][y] <= 8)
			{
				putimage((x - 1)*SIZE, (y - 1)*SIZE, &img[map[x][y]]);//����
			}
			else if (map[x][y] >= 19 && map[x][y] <= 28)
			{
				putimage((x - 1)*SIZE, (y - 1)*SIZE,&img[10]);//�հ�ͼƬ
			}
			else if (map[x][y] > 30)
			{
				putimage((x - 1)*SIZE, (y - 1)*SIZE, &img[11]);//���ͼƬ
			}
		}
		printf("\n");
	}
}

//����map[x][y]��Χ�Ŀ�
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
	//����һ�������Ϣ
	MOUSEMSG msg = { 0 };
	int x = 0, y = 0;
	while (1)
	{
		msg = GetMouseMsg();
		switch (msg.uMsg)
		{
		case WM_LBUTTONDOWN:        //����ɨ��  �հ�ͼƬ
			
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
		case WM_RBUTTONDOWN:        //���һ���հ�ͼƬ  ȡ��һ�����ͼƬ
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
	HWND hwnd=initgraph(ROW*SIZE, COL*SIZE, SHOWCONSOLE);//���ش��ھ��
	PutMap(map, ROW, COL);
	count = 0;
	while (1)
	{
		PutMap(map, ROW, COL);
		if (PalyGame() == -1)
		{
			int x, y;
			MessageBox(hwnd, L"��ȵ����ˣ���Ϸ����", L"", MB_OK);
			
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
			MessageBox(hwnd, L"��ɹ��Ķ㿪��������", L"", MB_OK);
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
		HWND hwnd = initgraph(ROW*SIZE, COL*SIZE, SHOWCONSOLE);//���ش��ھ��
		PutMap(map, ROW, COL);
		
		while (1)
		{
			PutMap(map, ROW, COL);
			if (PalyGame() == -1)
			{
				int x, y;
				MessageBox(hwnd, L"��ȵ����ˣ���Ϸ����", L"", MB_OK);
				
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
				MessageBox(hwnd, L"��ɹ��Ķ㿪��������", L"", MB_OK);
				break;
			}
		}
	}
	else
	{
		printf("�����Ͼ����ݣ��˳����򲻻ᱣ�����ݣ�\n");
	}
}

int main()
{
	int input = 0;
	int i = 0;
	srand((unsigned int)time(NULL));
	//��������
	
	
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
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 2:MineCleagain();
			break;
		case 1:MineCle();
			break;
		case 0:
			break;
		default:printf("�����������������\n");
			break;
		}
	} while (input);
	

	return 0;
}