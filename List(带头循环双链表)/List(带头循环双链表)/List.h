#pragma once
#define _CRT_SECURE_NO_WARNINGS 0
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

//�����д洢����������
typedef int ListDataType;

typedef struct ListNode
{
	//ǰһ���ڵ�
	struct ListNode* prev;
	//��һ���ڵ�
	struct ListNode* next;
	//�洢������
	ListDataType data;

}ListNode;

//����һ���½ڵ�,����x����data��
ListNode* BuyNewNode(ListDataType x);

//����һ�����ڱ�λ���ѳ�ʼ��������
ListNode* InitList();

//β������
void ListPushBack(ListNode* phead, ListDataType x);

//βɾ����
void ListPopBack(ListNode* phead);

//ͷ������
void ListPushFront(ListNode* phead, ListDataType x);

//βɾ����
void ListPopFront(ListNode* phead);

//����ָ������,���������ַ
ListNode* FindNode(ListNode* phead,ListDataType x);

//����ڵ�ǰ��������
void ListInsert(ListNode* pos, ListDataType x);

//����ڵ�ǰɾ������
void ListErase(ListNode* pos);

//��������
void ListDestory(ListNode* phead);
