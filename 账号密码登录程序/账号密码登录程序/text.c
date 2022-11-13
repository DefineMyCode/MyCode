#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void game1()
{
	int input;
	srand((unsigned int)time(NULL));
	do {
		
		menu();//打印菜单
		scanf("%d", &input);
		switch (input)
		{
		case 0:break;
		case 1:game();break;//开始游戏
		default:printf("暂未开放该功能，请重新输入\n");
		}
		} while (input);
}