
#include "contact.h"
void menu()
{
	printf("************************************\n");
	printf("***1.�����ϵ��      2.ɾ����ϵ��***\n");
	printf("***3.������ϵ��      4.�޸���ϵ��***\n");
	printf("***5.������ϵ��     6.��ʾ������ϵ��\n");
	printf("***0.�˳�                        ***\n");
	printf("************************************\n");
}
int main()
{
	struct contact contact;
	contactinit(&contact);
	int input = 0;
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case EXIT:SaveData(&contact);Free(&contact); break;
		case add:Adddata(&contact);
			break;
		case del:deldata(&contact);
			break;
		case query:quedata(&contact);
			break;
		case modify:modifydata(&contact);
			break;
		case sort:sortdata(&contact);
			break;
		case show:showdata(&contact);
			break;
		default:printf("��δ���Ÿù���\n");
		}
	} while (input);
	return 0;
}