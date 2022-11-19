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
		printf("Ð¡¶Ë\n");
	}
	else
	{
		printf("´ó¶Ë\n");
	}
	return 0;
}