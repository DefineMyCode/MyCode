#include "��¼.h"
void menu()
{
	system("title DCSGO");
	printf("****************************************\n");
	printf("*** 0.�˳�                1.��¼     ***\n");
	printf("*** 2.ע��                3.�޸����� ***\n");
	printf("****************************************\n");
	printf("��ѡ��:\n");
}


int CheckCapacity(data* pdata)
{
	usr* p = pdata->data;
	if (pdata->size == pdata->capacity)
	{
		realloc(pdata->data,(OnceAdd+pdata->capacity)*sizeof(usr));
		if (pdata->data == NULL)
		{
			perror("����");
			pdata->data = p;
			return 1;
		}
		else
		{
			pdata->capacity += OnceAdd;
			printf("���ݳɹ�\n");
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
		//Ϊdata������ʼ����
		pdata->capacity = DATA_capacity;
		pdata->data = (usr*)malloc(DATA_capacity * sizeof(usr));
		if (pdata->data == NULL)
		{
			perror("malloc data");
			return 1;
		}
		pdata->size = 0;
		//��id.dat��pasword.dat�е����ݶ��뵽data��
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
	system("title �޸�����");
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
		printf("��֤���ǣ�%s\n",VerCode);
		printf("��������֤�룺\n");
		scanf("%s", input);
		if (!strcmp(input, VerCode))
		{
			printf("������Ҫ�޸ĵ��˺ţ�\n");
			scanf("%s", id);
			ret = CheckId(pdata, id);
			if (ret == -1)
			{
				printf("������˺Ų�����\n");
				continue;
			}
			else
			{
				printf("Ҫ�����˺ŵ������޸�Ϊ��\n");
				scanf("%s", pasword);
				strcpy(pdata->data[ret].usr_pasword, pasword);
				printf("�޸ĳɹ�\n");
				break;
			}
		}
		else
			printf("��֤���������\n");
		
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
			printf("����ɹ�\n");
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
	system("title ��¼");
	system("cls");
	
	if (pdata->size == 0)
	{
		printf("�����û���Ϣ\n");
		return;
	}
	usr tmp = { 0 };
	int ret = 0;
	int i = 0;
	while (1)
	{
		printf("�������˺ţ�\n");
		scanf("%s", tmp.usr_id);
		ret = CheckId(pdata,tmp.usr_id);
		if (ret != -1)
		{
			printf("���������룺\n");
			scanf("%s", tmp.usr_pasword);
			if (!strcmp(pdata->data[ret].usr_pasword, tmp.usr_pasword))
			{
				printf("��¼�ɹ�,��ӭ\n");
				Sleep(1000);
				break;
			}		
			else
			{
				system("cls");
				printf("�������\n");
				i++;
				continue;
			}
				
		}
		else
		{
			system("cls");
			printf("���˺Ų�����\n");
			i++;
		}
	}
	system("cls");
}

void Enroll(data* pdata)
{
	system("title ע��");
	system("cls");
	char id[USR_ID_LEN];
	char pasword[USR_PASWORD];
	while (1)
	{
		printf("�������˺ţ�\n");
		scanf("%s", id);
		//����˺��Ƿ�ע��
		if (CheckId(pdata, id) == -1)
		{
			strcpy(pdata->data[pdata->size].usr_id, id);
			printf("���������룺\n");
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
			printf("���˺��ѱ�ע��\n");
		}
	}
	system("cls");
}