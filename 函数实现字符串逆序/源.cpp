
#include <stdio.h>
#include <string.h>
void reverse(char* arr)
{
	int len = strlen(arr);
	char tmp = *arr;
	*arr = *(arr + len - 1);
	*(arr + len - 1) = '\0';
	if (len >= 2)
		reverse(arr + 1);
	*(arr + len - 1) = tmp;
}
int main()
{
	char arr[] = "abcdefg";
	printf("����ǰ��%s\n", arr);
	reverse(arr);
	printf("�����%s\n", arr);	
	return 0;
}