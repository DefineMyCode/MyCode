#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int STDataType;

typedef struct Stack
{
	//ջ�����һ��Ԫ�ص���һ��Ԫ��λ��
	int top;
	//ջ������
	int capacity;
	//�洢���ݵ�һά����ָ��
	STDataType* data;
}ST;

//��ʼ��ջ
void StackInit(ST* ps);

//����ջ(�ͷŶ�������)
void StackDestroy(ST* ps);

//ѹջ(��������)
void StackPush(ST *ps, STDataType x);

//��ջ(ɾ������)
void StackPop(ST *ps);

//����ջ��Ԫ��
STDataType StackTop(ST* ps);

//���ջ���Ƿ�������,û�з���true,��֮����false
bool StackEmpty(ST *ps);

//����ջ������һ��Ԫ��
int StackSize(ST *ps);

