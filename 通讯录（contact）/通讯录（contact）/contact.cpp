#include "contact.h"
enum
{
	nochange,
	name,
	sex,
	age,
	tele,
	addr
};
static void menu_sort()
{
	printf("************************\n");
	printf("***1.����      2.�Ա�***\n");
	printf("***3.����      4.�绰***\n");
	printf("***5.סַ      0.Ĭ��***\n");
	printf("************************\n");
}
int compare_name(const void * a, const void * b)
{
	return strcmp(((struct peoinfo*)a)->name,((struct peoinfo*)b)->name);
}
int compare_sex(const void * a, const void * b)
{
	return strcmp(((struct peoinfo*)a)->sex, ((struct peoinfo*)b)->sex);
}
int compare_age(const void * a, const void * b)
{
	return (((struct peoinfo*)a)->age - ((struct peoinfo*)b)->age);
}
int compare_tele(const void * a, const void * b)
{
	return strcmp(((struct peoinfo*)a)->tele, ((struct peoinfo*)b)->tele);
}
int compare_addr(const void * a, const void * b)
{
	return strcmp(((struct peoinfo*)a)->addr, ((struct peoinfo*)b)->addr);
}

void ChackCapacity(contact* pcontact)
{
	if (pcontact->sz == pcontact->CapacityContact)
	{
		peoinfo* ret = (peoinfo*)realloc(pcontact->data, (pcontact->CapacityContact += 2) * sizeof(peoinfo));
		if (ret == NULL)
		{
			printf("%s\n", strerror(errno));
		}
		else
		{
			pcontact->data = ret;
		}
		printf("���ݳɹ�\n");
	}
}

void contactinit(struct contact* pcontact)
{
	FILE* fp = fopen("data.dat", "rb");
	if (fp == NULL)
	{
		perror("open data.dat:");
		return;
	}
	else 
	{
		peoinfo* ret = NULL;
		peoinfo tmp = { 0 };
		ret = (peoinfo*)malloc(Capacity * sizeof(peoinfo));
		if (ret == NULL)
		{
			printf("%s\n", strerror(errno));
		}
		else
		{
			pcontact->data = ret;
		}
		pcontact->CapacityContact = Capacity;
		pcontact->sz = 0;
		while (fread(&tmp, sizeof(peoinfo), 1, fp))
		{
			pcontact->data[pcontact->sz] = tmp;
			pcontact->sz++;
			ChackCapacity(pcontact);		
		}
	}
	fclose(fp);
	fp = NULL;
}

void Adddata(struct contact* pcontact)
{
	if (pcontact->sz ==pcontact->CapacityContact)
	{
		peoinfo* ret = (peoinfo*)realloc(pcontact->data,(pcontact->CapacityContact+=2) * sizeof(peoinfo));
		if (ret == NULL)
		{
			printf("%s\n", strerror(errno));
		}
		else
		{
			pcontact->data = ret;
		}
		printf("���ݳɹ�\n");
	}
		printf("��������ϵ��������");
		scanf("%s", pcontact->data[pcontact->sz].name);
		printf("��������ϵ���Ա�");
		scanf("%s", pcontact->data[pcontact->sz].sex);
		printf("��������ϵ�绰���룺");
		scanf("%s", pcontact->data[pcontact->sz].tele);
		printf("��������ϵ�����䣺");
		scanf("%d", &pcontact->data[pcontact->sz].age);
		printf("��������ϵ��סַ��");
		scanf("%s", pcontact->data[pcontact->sz].addr);
	pcontact->sz++;
	printf("��ӳɹ�\n");
}
static int Findbyname(const struct contact* pcontact,char name[MAX_NAME])
{
	int i = 0;
	for (;i < pcontact->sz;i++)
	{
		if(0==strcmp(pcontact->data[i].name,name))
			return i;
	}
	return -1;
}
void deldata(struct contact* pcontact)
{
	if (pcontact->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��������ϵ�˺�����\n");
	}
	else
	{
		char name[MAX_NAME];
		int ret = 0;
		printf("��������ϵ��������");
		scanf("%s", name);
		if (-1 == (ret = Findbyname(pcontact, name)))
		{
			printf("δ���ҵ�����ϵ��\n");
		}
		else
		{
			for (;ret< pcontact->sz;ret++)
			{
				pcontact->data[ret] = pcontact->data[ret + 1];
			}
			pcontact->sz--;
			printf("ɾ���ɹ�\n");
		}
	}
}

void quedata(const struct contact* pcontact)
{
	if (pcontact->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��������ϵ�˺�����\n");
	}
	else
	{
		char name[MAX_NAME];
		int ret=0;
		printf("��������ϵ��������");
		scanf("%s", name);
		ret=Findbyname(pcontact, name);
		if (ret == -1)
		{
			printf("δ���ҵ�����ϵ��\n");
		}
		else
		{
			printf("%-20s\t%-10s\t%-3s\t%-12s\t%-60s\n",
				"����", "�Ա�", "����", "�绰����", "סַ");
			printf("%-20s\t%-10s\t%-3d\t%-12s\t%-60s\n",
				pcontact->data[ret].name,
				pcontact->data[ret].sex,
				pcontact->data[ret].age,
				pcontact->data[ret].tele,
				pcontact->data[ret].addr);
		}
	}
}

void modifydata(struct contact* pcontact)
{
	if (pcontact->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��������ϵ�˺�����\n");
	}
	else
	{
		char name[MAX_NAME];
		int ret;
		printf("������Ҫ�޸ĵ���ϵ��������");
		scanf("%s", name);
		ret=Findbyname(pcontact, name);
		if (ret == -1)
			printf("δ���ҵ�����ϵ��\n");
		else
		{
			printf("��������ϵ��������");
			scanf("%s", pcontact->data[ret].name);
			printf("��������ϵ���Ա�");
			scanf("%s", pcontact->data[ret].sex);
			printf("��������ϵ�绰���룺");
			scanf("%s", pcontact->data[ret].tele);
			printf("��������ϵ�����䣺");
			scanf("%d", &pcontact->data[ret].age);
			printf("��������ϵ��סַ��");
			scanf("%s", pcontact->data[ret].addr);
			printf("�޸ĳɹ�\n");
		}
	}
}

void sortdata(struct contact* pcontact)
{
	if (pcontact->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��������ϵ�˺�����\n");
	}
	else if(pcontact->sz == 1) 
	{
		printf("����ɹ�\n");
	}
	else
	{
		int input = 0;
		menu_sort();
		scanf("%d", &input);
		switch (input)
		{
		case name:qsort(pcontact->data, pcontact->sz, sizeof(pcontact->data[0]), compare_name);
			printf("����ɹ�\n");
			break;
		case sex:qsort(pcontact->data, pcontact->sz, sizeof(pcontact->data[0]), compare_sex);
			printf("����ɹ�\n");
			break;
		case age:qsort(pcontact->data, pcontact->sz, sizeof(pcontact->data[0]), compare_age);
			printf("����ɹ�\n");
			break;
		case tele:qsort(pcontact->data, pcontact->sz, sizeof(pcontact->data[0]), compare_tele);
			printf("����ɹ�\n");
			break;
		case addr:qsort(pcontact->data, pcontact->sz, sizeof(pcontact->data[0]), compare_addr);
			printf("����ɹ�\n");
			break;
		case nochange:
			printf("����ɹ�\n");
			break;
		default:printf("���޸�����ʽ\n");
		}
	}
}

void showdata(const struct contact* pcontact)
{
	if (pcontact->sz == 0)
	{
		printf("ͨѶ¼Ϊ�գ��������ϵ�˺�����\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-10s\t%-3s\t%-12s\t%-60s\n",
			"����", "�Ա�", "����", "�绰����", "סַ");
		for (i = 0;i < pcontact->sz;i++)
		{
			printf("%-20s\t%-10s\t%-3d\t%-12s\t%-60s\n",
				pcontact->data[i].name,
				pcontact->data[i].sex,
				pcontact->data[i].age,
				pcontact->data[i].tele,
				pcontact->data[i].addr);
		}
	}
}

void SaveData(contact* pcontact)
{
	FILE* fp = fopen("data.dat", "wb");
	if (fp == NULL)
	{
		perror("open data.dat");
		return;
	}
	else
	{
		fwrite(pcontact->data, sizeof(peoinfo), pcontact->sz, fp);
	}
	fclose(fp);
	fp = NULL;
}

void Free(contact* pcontact)
{
	free(pcontact->data);
	pcontact->data = NULL;
}