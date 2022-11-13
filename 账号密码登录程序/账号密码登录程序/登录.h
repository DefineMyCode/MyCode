#define _CRT_SECURE_NO_WARNINGS 1
#define USR_ID_LEN 20
#define USR_PASWORD 20
#define DATA_capacity 3
#define OnceAdd 2
#define VERCODE 6
//头文件
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "业务.h"
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
	EXIT,//0退出
	REGISTER,//1登录
	ENROLL,//2注册
	CHANGEPASWORD//3修改密码
};

//函数声明

void menu();
//初始化数据
int InitData(data* pdata);
//保存当前数据
int Conserve(data* pdata);


//释放堆区中开辟的动态内存
void Free(data* pdata);
//检查容量
int CheckCapacity(data* pdata);
//修改密码
void ChangePasword(data* pdata);
//登录
void Register(data* pdata);

//注册
void Enroll(data* pdata);
//检查账号是否存在，存在返回1，不存在返回0
int CheckId(data* pdata,char* in_id);