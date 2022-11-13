#pragma once
#define _CRT_SECURE_NO_WARNINGS 0
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <errno.h>

//链表中存储的数据类型
typedef int ListDataType;

typedef struct ListNode
{
	//前一个节点
	struct ListNode* prev;
	//后一个节点
	struct ListNode* next;
	//存储的数据
	ListDataType data;

}ListNode;

//创建一个新节点,并将x存入data中
ListNode* BuyNewNode(ListDataType x);

//返回一个带哨兵位的已初始化的链表
ListNode* InitList();

//尾插数据
void ListPushBack(ListNode* phead, ListDataType x);

//尾删数据
void ListPopBack(ListNode* phead);

//头插数据
void ListPushFront(ListNode* phead, ListDataType x);

//尾删数据
void ListPopFront(ListNode* phead);

//查找指定数据,并返回其地址
ListNode* FindNode(ListNode* phead,ListDataType x);

//随机节点前插入数据
void ListInsert(ListNode* pos, ListDataType x);

//随机节点前删除数据
void ListErase(ListNode* pos);

//销毁链表
void ListDestory(ListNode* phead);
