#define _CRT_SECURE_NO_WARNINGS 1
#define USR_ID_LEN 20
#define USR_PASWORD 20
#define DATA_capacity 3
#define OnceAdd 2
#define VERCODE 6
//ͷ�ļ�
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "ҵ��.h"
typedef struct usr
{
	char usr_id[USR_ID_LEN];
	char usr_pasword[USR_PASWORD];
}usr;
typedef struct usr_data
{
	int size;
	int capacity;
	usr* data;
}data;
enum
{
	EXIT,//0�˳�
	REGISTER,//1��¼
	ENROLL,//2ע��
	CHANGEPASWORD//3�޸�����
};

//��������

void menu();
//��ʼ������
int InitData(data* pdata);
//���浱ǰ����
int Conserve(data* pdata);


//�ͷŶ����п��ٵĶ�̬�ڴ�
void Free(data* pdata);
//�������
int CheckCapacity(data* pdata);
//�޸�����
void ChangePasword(data* pdata);
//��¼
void Register(data* pdata);

//ע��
void Enroll(data* pdata);
//����˺��Ƿ���ڣ����ڷ���1�������ڷ���0
int CheckId(data* pdata,char* in_id);