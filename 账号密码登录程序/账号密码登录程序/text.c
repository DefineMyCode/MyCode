#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void game1()
{
	int input;
	srand((unsigned int)time(NULL));
	do {
		
		menu();//��ӡ�˵�
		scanf("%d", &input);
		switch (input)
		{
		case 0:break;
		case 1:game();break;//��ʼ��Ϸ
		default:printf("��δ���Ÿù��ܣ�����������\n");
		}
		} while (input);
}