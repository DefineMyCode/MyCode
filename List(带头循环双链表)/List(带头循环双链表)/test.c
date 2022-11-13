#include "List.h"

//¥Ú”°¡¥±Ìint
void ListPrint(ListNode* phead)
{
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//≤‚ ‘InitList ListPushBack ListPopBack
void test1()
{
	ListNode* plist = InitList();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	//ListPopBack(plist);
	ListPrint(plist);
	ListDestory(plist);
	plist = NULL;
}

//≤‚ ‘Õ∑≤ÂÕ∑…æ
void test2()
{
	ListNode* plist = InitList();
	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);
	ListPopFront(plist);
	ListPrint(plist);
	//ListPopFront(plist);
	//ListPrint(plist);
	ListDestory(plist);
	plist = NULL;
}

//≤‚ ‘Insert Find
void test3()
{
	ListNode* plist = InitList();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListNode* pos = FindNode(plist, 4);
	ListInsert(pos, 40);
	ListPrint(plist);
	pos = FindNode(plist, 1);
	ListInsert(pos, 10);
	ListPrint(plist);
	pos = FindNode(plist, 3);
	ListInsert(pos, 30);
	ListPrint(plist);
	ListDestory(plist);
	plist = NULL;

}

//≤‚ ‘Erase
test4()
{
	ListNode* plist = InitList();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);
	ListNode* pos;
	pos = FindNode(plist, 3);
	if (pos)
	{
		ListErase(pos);
		ListPrint(plist);
	}
	
	ListDestory(plist);
	plist = NULL;
}

//
void test5()
{
	ListNode* plist = InitList();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);

	ListPopBack(plist);
	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);

	ListPopBack(plist);
	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);
	//ListPopFront(plist);
	//ListPopBack(plist);
	ListPopFront(plist);
	ListPrint(plist);
	ListDestory(plist);
	plist = NULL;
}

//
void test6()
{
	ListNode* plist = InitList();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPrint(plist);
	ListDestory(plist);
	plist = NULL;
}

//÷’º´≤‚ ‘
void testEnd()
{
	ListNode* plist = InitList();
	ListPushBack(plist, 1);
	ListPushBack(plist, 2);
	ListPushBack(plist, 3);
	ListPushBack(plist, 4);
	ListPrint(plist);

	ListPushFront(plist, 1);
	ListPushFront(plist, 2);
	ListPushFront(plist, 3);
	ListPushFront(plist, 4);
	ListPrint(plist);

	ListNode* pos=FindNode(plist, 4);
	if (pos)
	{
		ListInsert(pos, 40);
	}
	ListPrint(plist);
	pos = FindNode(pos, 3);
	if (pos)
	{
		ListInsert(pos, 30);
	}
	ListPrint(plist);

	pos = FindNode(plist, 40);
	if (pos)
	{
		ListErase(pos);
	}
	ListPrint(plist);
	pos = FindNode(plist, 30);
	if (pos)
	{
		ListErase(pos);
	}
	ListPrint(plist);

	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);

	ListPushFront(plist, 20);
	ListPushFront(plist, 10);
	ListPushFront(plist, 0);
	ListPrint(plist);

	ListDestory(plist);
	plist = NULL;
}

int main()
{
	//test1();
	//test2();
	//test3();
	//test4();
	//test5();
	//test6();
	testEnd();
	return 0;
}