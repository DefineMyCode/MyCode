#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	//栈中最后一个元素的下一个元素位置
	int top;
	//栈的容量
	int capacity;
	//存储数据的一维数组指针
	STDataType* data;
}ST;

//初始化栈
void StackInit(ST* ps);

//销毁栈(释放堆区数据)
void StackDestroy(ST* ps);

//压栈(存入数据)
void StackPush(ST *ps, STDataType x);

//出栈(删除数据)
void StackPop(ST *ps);

//返回栈顶元素
STDataType StackTop(ST* ps);

//检查栈中是否有数据,没有返回true,反之返回false
bool StackEmpty(ST *ps);

//返回栈顶的下一个元素
int StackSize(ST *ps);

