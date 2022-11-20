#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <assert.h>
void left_move1(char* arr,int const k)
{	
	assert(arr != NULL);
	int j = 0;
	for (j = 0;j < k;j++)
	{
		char tmp = *arr;
		int i = 0;
		while (arr[i + 1] != '\0')
		{
			arr[i] = arr[i + 1];
			i++;
		}
		arr[i] = tmp;
	}
}
void reserve(char* left,char* right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (right-left>=1)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}
void left_move2(char* arr, int const k)//三步逆序法
{
	assert(arr != NULL);
	int len=strlen(arr);
	reserve(arr, arr + k - 1);
	reserve(arr + k, arr + len - 1);
	reserve(arr, arr + len - 1);
}
int is_move(char* arr, char* arr1)
{
	int len = strlen(arr);
	int len1 = strlen(arr1);
	int i=0;
	if (len != len1)
	{
		return 0;
	}
	if (!strcmp(arr, arr1))
	{
		return 1;
	}
	for (i = 0;i < len - 1;i++)
	{
		int ret=0;
		left_move2(arr, 1);
		ret=strcmp(arr, arr1);
		if (ret == 0)
		{
			return 1;
		}
	}
	return 0;
}
int is_move1(char* arr, char* arr1)
{
	int len = strlen(arr);
	int len1 = strlen(arr1);
	if (len != len1)
		return 0;
	//在arr后追加一个arr
	strncat(arr, arr, len);
	//判断arr1是不是arr的子串
	char* ret = strstr(arr, arr1);//返回子串在arr中的起始位置
	if (ret == NULL)
		return 0;
	else
		return 1;
}
int main()
{
	char arr[40] = "abcdefg";
	//left_move2(arr, 2);
	char arr1[] = "cdefgab";
	if (is_move1(arr, arr1))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	//printf("左旋后: %s\n", arr);
	return 0;
}