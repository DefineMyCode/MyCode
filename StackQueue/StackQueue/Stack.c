#include "Stack.h"

//初始化栈
void StackInit(ST* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

//销毁栈(释放堆区数据)
void StackDestroy(ST* ps)
{
	assert(ps);
	assert(ps->data);
	free(ps->data);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

//压栈(存入数据)
void StackPush(ST *ps, STDataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		STDataType* tmp = ps->data;
		int newCapacity = ps->capacity;
		newCapacity = newCapacity > 0 ? 2 * newCapacity : 4;
		tmp = (STDataType*)realloc(tmp,sizeof(STDataType)*newCapacity);
		if (tmp)
		{
			ps->data = tmp;
			ps->capacity = newCapacity;		
		}
		else
		{
			printf("realloc fail\n");
			exit(-1);
		}
	}	
	ps->data[ps->top] = x;
	ps->top++;
}

//出栈(删除数据)
void StackPop(ST *ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

//返回栈顶元素
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->data[ps->top - 1];
}

//检查栈中是否有数据,没有返回true,反之返回false
bool StackEmpty(ST *ps)
{
	assert(ps);
	
	return ps->top == 0;
}

//返回栈顶的下一个元素
int StackSize(ST *ps)
{
	assert(ps);
	//assert(!StackEmpty(ps));
	return ps->top;
}