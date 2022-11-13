#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 60
#define	Capacity 3
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
typedef struct peoinfo
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
	int age;
}peoinfo;
typedef struct contact
{
	int CapacityContact;
	int sz;
	struct peoinfo* data;
}contact;
enum
{
	EXIT,
	add,
	del,
	query,
	modify,
	sort,
	show
};

//初始化contact
void contactinit(struct contact* pcontact);
//添加联系人
void Adddata(struct contact* pcontact);
//显示所有联系人
void showdata(const struct contact* pcontact);
//删除指定的联系人
void deldata(struct contact* pcontact);
//查找指定的联系人
void quedata(const struct contact* pcontact);
//修改指定联系人
void modifydata(struct contact* pcontact);
//将通讯录中的联系人排序
void sortdata(struct contact* pcontact);
//检查通讯录容量是否充足，并扩充
void ChackCapacity(contact* pcontact);
//保存data中的数据到data.bat中
void SaveData(contact* pcontact);
//释放联系人（data指针）所指向的可变内存空间
void Free(contact* pcontact);