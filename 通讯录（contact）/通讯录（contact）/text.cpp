
#include "contact.h"
void menu()
{
	printf("************************************\n");
	printf("***1.添加联系人      2.删除联系人***\n");
	printf("***3.查找联系人      4.修改联系人***\n");
	printf("***5.排序联系人     6.显示所有联系人\n");
	printf("***0.退出                        ***\n");
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
		default:printf("暂未开放该功能\n");
		}
	} while (input);
	return 0;
}