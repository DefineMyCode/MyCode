#include <stdio.h>

//���ֲ���target��һ�γ��ֵ�λ�� ��߽� [ )
int BinaryLeft1(int arr[], int target,int n)
{
	int L = 0, R = n;
	int mid;
	while (L < R)
	{
		mid = L + (R - L) / 2;
		if (arr[mid] >= target)
			R = mid;
		else
			L = mid + 1;
	}
	//������Ԫ�ض�С��targetʱL���ƶ���R
	//��L==n ��ʱarr[L]��Խ�������
	if (L == n)
		return -1;
	return arr[L] == target ? L : -1;
}

//[ ]
int BinaryLeft2(int arr[], int target, int n)
{
	int L = 0, R = n - 1;
	int mid;
	while (L <= R)
	{
		mid = L + (R - L) / 2;
		if (arr[mid] >= target)
			R = mid - 1;
		else
			L = mid + 1;
	}
	if (L == n)
		return -1;
	return arr[L] == target ? L : -1;
}

int BinaryRight(int arr[], int target, int n)
{
	int L = 0, R = n;
	int mid;
	while (L < R)
	{
		mid = L + (R - L) / 2;
		if (arr[mid] <= target)
			L = mid + 1;
		else
			R = mid;
	}
	//������Ԫ�ض�����targetʱL���ߵ�0��
	//��ʱarr[L-1]�ͻ�Խ�����
	if (L - 1 < 0)
		return -1;
	return arr[L - 1] == target ? L - 1 : -1;
}

int main()
{
	//[4,7,7,8,8,10],8
	int arr[] = { 4,7,7,8,8,10 };
	int target = 8;
	//for (int i = 0;i < 11;i++)
	//{
	//	target = i;
	//	printf("%d��һ�γ�����[ %d ]\n", target, BinaryRight(arr, target, sizeof(arr) / sizeof(arr[0])));
	//}
	printf("%d��һ�γ�����[ %d ]", target, BinaryRight(arr, target, sizeof(arr) / sizeof(arr[0])));
	return 0;
}