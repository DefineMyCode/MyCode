#include <stdio.h>
int check_sys()
{
	int a=1;
	return *((char*)&a);
}
int main()
{
	if (check_sys() == 1)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	return 0;
}