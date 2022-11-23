#include <stdio.h>
#include <stddef.h>
#define OFFSETOF(struct_name,member) (int)&(((struct_name*)0)->member)
int main()
{
	typedef struct stu
	{
		char name[20];
		int age;
		char sex[10];
	}sut;
	printf("sut.name:%d\n",offsetof(stu, name));
	printf("sut.age:%d\n",offsetof(stu, age));
	printf("sut.sex:%d\n",offsetof(stu, sex));
	printf("OFFSETOF:\n");
	printf("sut.name:%d\n", OFFSETOF(stu, name));
	printf("sut.age:%d\n", OFFSETOF(stu, age));
	printf("sut.sex:%d\n", OFFSETOF(stu, sex));

	return 0;
}