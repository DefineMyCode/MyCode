#include "��¼.h"
int main()
{
	int input = 0;
	data Data;	
	
	srand((unsigned int)time(NULL));
	if(InitData(&Data))
	{
		return -1;
	}
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case EXIT: Conserve(&Data);    Free(&Data);
			break;
		case REGISTER:Register(&Data);   Fun();
			break;
		case ENROLL:Enroll(&Data);
			break;
		case CHANGEPASWORD:ChangePasword(&Data);
			break;
		default: printf("�ù�����δ����\n");
		}
	} while (input);
	return 0;
}