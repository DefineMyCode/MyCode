#include "List.h"

ListNode* InitList()
{
	ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
	phead->prev = phead;
	phead->next = phead;
	return phead;
}

ListNode* BuyNewNode(ListDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	if (newnode)
	{
		newnode->data = x;
		return newnode;
	}
	else
	{
		//�½ڵ㿪��ʧ��,�жϳ���
		printf("%s\n", strerror(errno));
		exit(-1);
	}
}

ListNode* FindNode(ListNode* phead, ListDataType x)
{
	assert(phead);
	assert(phead->next!=phead);//������û������
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		if (x == cur->data)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void ListPushBack(ListNode* phead, ListDataType x)
{
	assert(phead);//�ڱ�λ������ΪNULL

	ListInsert(phead, x);
}

void ListPopBack(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//��������Ҫ������
	ListErase(phead->prev);
}

void ListPushFront(ListNode* phead, ListDataType x)
{
	assert(phead);
	
	ListInsert(phead->next, x);
}

void ListPopFront(ListNode* phead)
{
	assert(phead);
	assert(phead->next != phead);//��������Ҫ������
	ListErase(phead->next);
}

void ListInsert(ListNode* pos, ListDataType x)
{
	assert(pos);
	ListNode* newnode = BuyNewNode(x);
	ListNode* posPrev = pos->prev;
	posPrev->next = newnode;
	newnode->next = pos;
	newnode->prev = posPrev;
	pos->prev = newnode;
}

void ListErase(ListNode* pos)
{
	assert(pos);
	ListNode* posPrev = pos->prev;
	ListNode* posNext = pos->next;
	free(pos);
	
	posPrev->next = posNext;
	posNext->prev = posPrev;
}

void ListDestory(ListNode* phead)
{
	assert(phead);

	ListNode* cur = phead->next;
	while (cur != phead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(phead);
}