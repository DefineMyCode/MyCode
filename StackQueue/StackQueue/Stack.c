#include "Stack.h"

//��ʼ��ջ
void StackInit(ST* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

//����ջ(�ͷŶ�������)
void StackDestroy(ST* ps)
{
	assert(ps);
	assert(ps->data);
	free(ps->data);
	ps->data = NULL;
	ps->top = 0;
	ps->capacity = 0;
}

//ѹջ(��������)
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

//��ջ(ɾ������)
void StackPop(ST *ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

//����ջ��Ԫ��
STDataType StackTop(ST* ps)
{
	assert(ps);
	assert(!StackEmpty(ps));
	return ps->data[ps->top - 1];
}

//���ջ���Ƿ�������,û�з���true,��֮����false
bool StackEmpty(ST *ps)
{
	assert(ps);
	
	return ps->top == 0;
}

//����ջ������һ��Ԫ��
int StackSize(ST *ps)
{
	assert(ps);
	//assert(!StackEmpty(ps));
	return ps->top;
}