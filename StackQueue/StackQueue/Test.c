#include "Stack.h"

void test1()
{
	ST st;
	StackInit(&st);
	StackPush(&st, 1);
	StackPush(&st, 2);
	StackPush(&st, 3);
	StackPush(&st, 4);

	printf("%d ", StackTop(&st));
	StackPop(&st);
	printf("%d ", StackTop(&st));
	StackPop(&st);

	StackPush(&st, 5);
	StackPush(&st, 6);

	while (!StackEmpty(&st))
	{
		//printf("%d ", st.data[st.top - 1]);
		printf("%d ", StackTop(&st));
		StackPop(&st);
	}

	StackDestroy(&st);
}



int main()
{
	test1();
	return 0;
}