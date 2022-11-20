#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
double pow(int n, int k)
{
	if (k == 0)
		return 1;
	else if (k == 1)
		return n;
	else if (k < 0)
		return (1.0 / (pow(n, -k)));
	else 
		return n * pow(n, k - 1);	
}
int main()
{
	int n;
	int k;
	scanf("%d%d", &n,&k);
	if (k == 0 && n == 0)
	{
		printf("0的0次方没有意义\n");

	}
	else
		printf("%d的%d次方为:%g", n, k,pow(n,k));
	return 0;
}