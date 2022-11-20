#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct student {
	char name[15];
	char sex[10];//man woman
	int age;

}Stu;
int cmp_int(const void*e1, const void*e2)
{
	return (*(int*)e1) - (*(int*)e2);
}
int cmp_double(const void*e1,const void*e2)
{
	if ((*(double*)e1) - (*(double*)e2) > 0)
		return 1;
	else if ((*(double*)e1) - (*(double*)e2) == 0)
		return 0;
	else
		return -1;
}
int cmp_Stu_age(const void*e1, const void*e2)
{
	return ((Stu*)e1)->age - ((Stu*)e2)->age;//(struct student*)
}
int cmp_Stu_name(const void*e1, const void*e2)
{
	return strcmp(((Stu*)e1)->name, ((Stu*)e2)->name);
}
int cmp_Stu_sex(const void*e1, const void*e2)
{
	return strcmp(((Stu*)e1)->sex, ((Stu*)e2)->sex);
}
//自己实现的bubbling_sort
//交换任意两个元素
void swap(char* e1,char* e2,const int sz_oneof)
{
	int i = 0;
	for (i = 0;i < sz_oneof;i++)
	{
		char tmp = *e1;
		*e1 = *e2;
		*e2 = tmp;
		e1++;
		e2++;		
	}
}
void bubbling_sort(void* base, const int sz, const int sz_oneof, int(*cmp_fun)(const void*e1,const void*e2))
{
	int i = 0;
	int j = 0;
	for (i = 0;i < sz - 1;i++)
	{
		
		for (j = 0;j < sz - 1 - i;j++)
		{
			if (cmp_fun((char*)base + sz_oneof * j, (char*)base + sz_oneof * (j+1)) > 0)
			{
				//交换两个元素
				swap((char*)base+sz_oneof*j, (char*)base + sz_oneof * (j + 1),sz_oneof);
			}
		}
	}
}
int main()
{
	int i=0;
	int int_arr[] = { 1,3,5,7,9,0,2,4,6,8 };
	int sz_int_arr = sizeof(int_arr) / sizeof(int_arr[0]);
	double double_arr[] = { 1.13145201,0.12537,2.5,-9.787878,-0.120001,3.1415926,2.5001 };
	int sz_double_arr = sizeof(double_arr) / sizeof(double_arr[0]);
	Stu s1[] = { {"zhangsan","man",35},{"xiaoli","woman",18} ,{"lisi","man",25},{"zhangting","woman",19} };
	int sz_Stu_s1 = sizeof(s1) / sizeof(s1[0]);
	//qsort排序
	printf("qsort排序\n");
	qsort(int_arr, sz_int_arr, sizeof(int_arr[0]), cmp_int);
	printf("整型数组排序结果:\n");
	for (i = 0;i < sz_int_arr;i++)
	{
		printf("%d ", int_arr[i]);
	}
	printf("\n");
	qsort(double_arr, sz_double_arr, sizeof(double_arr[0]), cmp_double);
	printf("double数组排序结果:\n");
	for (i = 0;i < sz_double_arr;i++)
	{
		printf("%-2.9lf ", double_arr[i]);
	}
	printf("\n");
	qsort(s1, sz_Stu_s1, sizeof(s1[0]), cmp_Stu_age);
	printf("结构体s1按年龄排序结果:\n");
	printf("姓名            性别       年龄\n");
	for (i = 0;i < sz_Stu_s1;i++)
	{
		printf("%-15s %-10s %-3d", s1[i].name, s1[i].sex, s1[i].age);
		printf("\n");
	}
	printf("\n");
	qsort(s1, sz_Stu_s1, sizeof(s1[0]), cmp_Stu_name);
	printf("结构体s1按姓名排序结果:\n");
	printf("姓名            性别       年龄\n");
	for (i = 0;i < sz_Stu_s1;i++)
	{
		printf("%-15s %-10s %-3d", s1[i].name, s1[i].sex, s1[i].age);
		printf("\n");
	}
	printf("\n");
	qsort(s1, sz_Stu_s1, sizeof(s1[0]), cmp_Stu_sex);
	printf("结构体s1按性别排序结果:\n");
	printf("姓名            性别       年龄\n");
	for (i = 0;i < sz_Stu_s1;i++)
	{
		printf("%-15s %-10s %-3d", s1[i].name, s1[i].sex, s1[i].age);
		printf("\n");
	}
	

	//冒泡实现所有类型的数组排序
	printf("冒泡实现所有类型的数组排序\n");
	bubbling_sort(int_arr, sz_int_arr, sizeof(int_arr[0]), cmp_int);
	printf("整型数组排序结果:\n");
	for (i = 0;i < sz_int_arr;i++)
	{
		printf("%d ", int_arr[i]);
	}
	printf("\n");
	bubbling_sort(double_arr, sz_double_arr, sizeof(double_arr[0]), cmp_double);
	printf("double数组排序结果:\n");
	for (i = 0;i < sz_double_arr;i++)
	{
		printf("%-2.9lf ", double_arr[i]);
	}
	printf("\n");
	bubbling_sort(s1, sz_Stu_s1, sizeof(s1[0]), cmp_Stu_age);
	printf("结构体s1按年龄排序结果:\n");
	printf("姓名            性别       年龄\n");
	for (i = 0;i < sz_Stu_s1;i++)
	{
		printf("%-15s %-10s %-3d", s1[i].name, s1[i].sex, s1[i].age);
		printf("\n");
	}
	printf("\n");
	bubbling_sort(s1, sz_Stu_s1, sizeof(s1[0]), cmp_Stu_name);
	printf("结构体s1按姓名排序结果:\n");
	printf("姓名            性别       年龄\n");
	for (i = 0;i < sz_Stu_s1;i++)
	{
		printf("%-15s %-10s %-3d", s1[i].name, s1[i].sex, s1[i].age);
		printf("\n");
	}
	printf("\n");
	bubbling_sort(s1, sz_Stu_s1, sizeof(s1[0]), cmp_Stu_sex);
	printf("结构体s1按性别排序结果:\n");
	printf("姓名            性别       年龄\n");
	for (i = 0;i < sz_Stu_s1;i++)
	{
		printf("%-15s %-10s %-3d", s1[i].name, s1[i].sex, s1[i].age);
		printf("\n");
	}
	return 0;
}