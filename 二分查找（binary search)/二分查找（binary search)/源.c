#include <stdio.h>
#include <stdlib.h>
int BinarySearch(double* arr,int count,double num)
{
	int left = 0;
	int right = count - 1;
	int mid = (left + right) / 2;
	while (left<right)
	{
		if (num > arr[mid])//�������
		{
			left = mid + 1;
			mid = (left + right) / 2;
		}
		else if (num < arr[mid])
		{
			right = mid - 1;
			mid = (left + right) / 2;
		}
		else
		{
			return mid;
		}
	}
	return -1;	
}
int main()
{
	double arr[] = { 1.12,3.14,5.864,5.888,7.666,9.99999,11.001 };//����
	double num = 5.888;
	int size = sizeof(arr) / sizeof(arr[0]);
	int ret = BinarySearch(arr, size, num);
	if (-1 == ret)
	{
		printf("û����arr���ҵ�%lf", num);
	}
	else
	{
		printf("�ҵ��ˣ�%lf���±�Ϊ%d��λ�ô�\n", num, ret);
	}
	return 0;
}