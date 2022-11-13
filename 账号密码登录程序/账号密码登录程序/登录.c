#include "登录.h"
void menu()
{
	system("title DCSGO");
	printf("****************************************\n");
	printf("*** 0.退出                1.登录     ***\n");
	printf("*** 2.注册                3.修改密码 ***\n");
	printf("****************************************\n");
	printf("请选择:\n");
}


int CheckCapacity(data* pdata)
{
	usr* p = pdata->data;
	if (pdata->size == pdata->capacity)
	{
		realloc(pdata->data,(OnceAdd+pdata->capacity)*sizeof(usr));
		if (pdata->data == NULL)
		{
			perror("扩容");
			pdata->data = p;
			return 1;
		}
		else
		{
			pdata->capacity += OnceAdd;
			printf("扩容成功\n");
			p = NULL;
			return 0;
		}
	}
	return 0;
}
int InitData(data* pdata)
{
	FILE* fid = fopen("id.dat","rb");
	FILE* fpasword=fopen("pasword.dat", "rb");
	usr tmp = { 0 };
	if (fid == NULL)
	{
		perror("open id");
		return 1;
	}
	else if(fpasword == NULL)
	{
		perror("open pasword");
		return 1;
	}
	else
	{
		//为data创建初始容量
		pdata->capacity = DATA_capacity;
		pdata->data = (usr*)malloc(DATA_capacity * sizeof(usr));
		if (pdata->data == NULL)
		{
			perror("malloc data");
			return 1;
		}
		pdata->size = 0;
		//将id.dat和pasword.dat中的数据读入到data中
		while (fread(&tmp.usr_id,USR_ID_LEN, 1, fid) && 
			   fread(&tmp.usr_pasword,USR_PASWORD,1,fpasword))
		{
			pdata->data[pdata->size] = tmp;
			pdata->size++;
			if (CheckCapacity(pdata))
				return 1;
		}
		fclose(fid);
		fid = NULL;
		fclose(fpasword);
		fpasword = NULL;
		return 0;
	}
	
}

void ChangePasword(data* pdata)
{
	system("title 修改密码");
	system("cls");
	
	char VerCode[VERCODE+1];
	char id[USR_ID_LEN];
	char pasword[USR_PASWORD];
	char input[VERCODE+1];
	int ret = 0;
	int i = 0;
	char ch[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	while(1)
	{
		for (i = 0;i < VERCODE;i++)
		{
			int j = rand()%52;
			VerCode[i] = ch[j];
		}
		VerCode[i] = '\0';
		printf("验证码是：%s\n",VerCode);
		printf("请输入验证码：\n");
		scanf("%s", input);
		if (!strcmp(input, VerCode))
		{
			printf("请输入要修改的账号：\n");
			scanf("%s", id);
			ret = CheckId(pdata, id);
			if (ret == -1)
			{
				printf("输入的账号不存在\n");
				continue;
			}
			else
			{
				printf("要将该账号的密码修改为：\n");
				scanf("%s", pasword);
				strcpy(pdata->data[ret].usr_pasword, pasword);
				printf("修改成功\n");
				break;
			}
		}
		else
			printf("验证码输入错误\n");
		
	}
	system("cls");
}

int Conserve(data* pdata)
{
	FILE* fid = fopen("id.dat", "wb");
	FILE* fpasword = fopen("pasword.dat", "wb");
	if (fid == NULL)
	{
		perror("w open fid");
		return 1;
	}
	else if (fpasword == NULL)
	{
		perror("w open fpasword");
		return 1;
	}
		int i = 0;
		for (i = 0;i < pdata->size;i++)
		{
			fwrite(pdata->data[i].usr_id, USR_ID_LEN, 1, fid);
			fwrite(pdata->data[i].usr_pasword, USR_PASWORD, 1, fpasword);
		}
		if(i) 
			printf("保存成功\n");
		fclose(fid);
		fid = NULL;
		fclose(fpasword);
		fpasword = NULL;
		return 0;
}

void Free(data* pdata)
{
	free(pdata->data);
}

int CheckId(data* pdata, char* in_id)
{
	int i = 0;
	if (pdata->size == 0)
	{
		return -1;
	}
	for (i = 0;i < pdata->size;i++)
	{
		if(!strcmp(pdata->data[i].usr_id,in_id))
			return i;
	}
	return -1;
}


void Register(data* pdata)
{
	system("title 登录");
	system("cls");
	
	if (pdata->size == 0)
	{
		printf("暂无用户信息\n");
		return;
	}
	usr tmp = { 0 };
	int ret = 0;
	int i = 0;
	while (1)
	{
		printf("请输入账号：\n");
		scanf("%s", tmp.usr_id);
		ret = CheckId(pdata,tmp.usr_id);
		if (ret != -1)
		{
			printf("请输入密码：\n");
			scanf("%s", tmp.usr_pasword);
			if (!strcmp(pdata->data[ret].usr_pasword, tmp.usr_pasword))
			{
				printf("登录成功,欢迎\n");
				Sleep(1000);
				break;
			}		
			else
			{
				system("cls");
				printf("密码错误\n");
				i++;
				continue;
			}
				
		}
		else
		{
			system("cls");
			printf("该账号不存在\n");
			i++;
		}
	}
	system("cls");
}

void Enroll(data* pdata)
{
	system("title 注册");
	system("cls");
	char id[USR_ID_LEN];
	char pasword[USR_PASWORD];
	while (1)
	{
		printf("请输入账号：\n");
		scanf("%s", id);
		//检查账号是否被注册
		if (CheckId(pdata, id) == -1)
		{
			strcpy(pdata->data[pdata->size].usr_id, id);
			printf("请设置密码：\n");
			scanf("%s",pasword);
			strcpy(pdata->data[pdata->size].usr_pasword, pasword);
			pdata->size++;
			if(CheckCapacity(pdata)) 
				return;
			break;
		}
		else
		{
			system("cls");
			printf("该账号已被注册\n");
		}
	}
	system("cls");
}