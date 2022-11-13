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

//��ʼ��contact
void contactinit(struct contact* pcontact);
//�����ϵ��
void Adddata(struct contact* pcontact);
//��ʾ������ϵ��
void showdata(const struct contact* pcontact);
//ɾ��ָ������ϵ��
void deldata(struct contact* pcontact);
//����ָ������ϵ��
void quedata(const struct contact* pcontact);
//�޸�ָ����ϵ��
void modifydata(struct contact* pcontact);
//��ͨѶ¼�е���ϵ������
void sortdata(struct contact* pcontact);
//���ͨѶ¼�����Ƿ���㣬������
void ChackCapacity(contact* pcontact);
//����data�е����ݵ�data.bat��
void SaveData(contact* pcontact);
//�ͷ���ϵ�ˣ�dataָ�룩��ָ��Ŀɱ��ڴ�ռ�
void Free(contact* pcontact);