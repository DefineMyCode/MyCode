#define NEXT 10

#include <stdio.h>
#include <string.h>
//#include <stdlib.h>
void build_next(char* substr,int next[NEXT])
{
	int prefix_len = 0;//当前共同后缀的长度
	int i = 1;
	int len_sub = strlen(substr);
	while (i <len_sub)
	{
		if (substr[prefix_len] == substr[i])
		{
			prefix_len++;
			next[i] = prefix_len;
			i++;
		}
		else
		{
			if (prefix_len == 0)
			{
				next[i] = 0;
				i++;
			}
			else
			{
				prefix_len = next[prefix_len - 1];
			}
		}
	}
}
int kmp_search(char *str,char *substr)
{
	int next[NEXT] = { 0 };
	build_next(substr,next);
	int i = 0;//主串中的指针
	int j = 0;//子串中的指针
	int str_len = strlen(str);
	int sub_len=strlen(substr);
	while (i <str_len)
	{
		if (str[i] == substr[j])
		{
			i++;
			j++;
		}
		else if (j > 0)
		{
			j = next[j - 1];
		}
		else
		{
			i++;
		}
		if (j ==sub_len)/*匹配成功*/
			return i - j;
	}
	return -1;
}
int main()
{
	char str[] = "ABABABCAA";
	char substr[] = "BCAA";
	int tip=kmp_search(str, substr);
	if (tip == -1)
	{
		printf("no");
	}
	else
	{
		printf("yes,on %d", tip);
	}
	return 0;
}