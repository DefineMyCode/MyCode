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
	printf("***1.姓名      2.性别***\n");
	printf("***3.年龄      4.电话***\n");
	printf("***5.住址      0.默认***\n");
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
		printf("扩容成功\n");
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
		printf("扩容成功\n");
	}
		printf("请输入联系人姓名：");
		scanf("%s", pcontact->data[pcontact->sz].name);
		printf("请输入联系人性别：");
		scanf("%s", pcontact->data[pcontact->sz].sex);
		printf("请输入联系电话号码：");
		scanf("%s", pcontact->data[pcontact->sz].tele);
		printf("请输入联系人年龄：");
		scanf("%d", &pcontact->data[pcontact->sz].age);
		printf("请输入联系人住址：");
		scanf("%s", pcontact->data[pcontact->sz].addr);
	pcontact->sz++;
	printf("添加成功\n");
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
		printf("通讯录为空，请添加联系人后再试\n");
	}
	else
	{
		char name[MAX_NAME];
		int ret = 0;
		printf("请输入联系人姓名：");
		scanf("%s", name);
		if (-1 == (ret = Findbyname(pcontact, name)))
		{
			printf("未查找到该联系人\n");
		}
		else
		{
			for (;ret< pcontact->sz;ret++)
			{
				pcontact->data[ret] = pcontact->data[ret + 1];
			}
			pcontact->sz--;
			printf("删除成功\n");
		}
	}
}

void quedata(const struct contact* pcontact)
{
	if (pcontact->sz == 0)
	{
		printf("通讯录为空，请添加联系人后再试\n");
	}
	else
	{
		char name[MAX_NAME];
		int ret=0;
		printf("请输入联系人姓名：");
		scanf("%s", name);
		ret=Findbyname(pcontact, name);
		if (ret == -1)
		{
			printf("未查找到该联系人\n");
		}
		else
		{
			printf("%-20s\t%-10s\t%-3s\t%-12s\t%-60s\n",
				"姓名", "性别", "年龄", "电话号码", "住址");
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
		printf("通讯录为空，请添加联系人后再试\n");
	}
	else
	{
		char name[MAX_NAME];
		int ret;
		printf("请输入要修改的联系人姓名：");
		scanf("%s", name);
		ret=Findbyname(pcontact, name);
		if (ret == -1)
			printf("未查找到该联系人\n");
		else
		{
			printf("请输入联系人姓名：");
			scanf("%s", pcontact->data[ret].name);
			printf("请输入联系人性别：");
			scanf("%s", pcontact->data[ret].sex);
			printf("请输入联系电话号码：");
			scanf("%s", pcontact->data[ret].tele);
			printf("请输入联系人年龄：");
			scanf("%d", &pcontact->data[ret].age);
			printf("请输入联系人住址：");
			scanf("%s", pcontact->data[ret].addr);
			printf("修改成功\n");
		}
	}
}

void sortdata(struct contact* pcontact)
{
	if (pcontact->sz == 0)
	{
		printf("通讯录为空，请添加联系人后再试\n");
	}
	else if(pcontact->sz == 1) 
	{
		printf("排序成功\n");
	}
	else
	{
		int input = 0;
		menu_sort();
		scanf("%d", &input);
		switch (input)
		{
		case name:qsort(pcontact->data, pcontact->sz, sizeof(pcontact->data[0]), compare_name);
			printf("排序成功\n");
			break;
		case sex:qsort(pcontact->data, pcontact->sz, sizeof(pcontact->data[0]), compare_sex);
			printf("排序成功\n");
			break;
		case age:qsort(pcontact->data, pcontact->sz, sizeof(pcontact->data[0]), compare_age);
			printf("排序成功\n");
			break;
		case tele:qsort(pcontact->data, pcontact->sz, sizeof(pcontact->data[0]), compare_tele);
			printf("排序成功\n");
			break;
		case addr:qsort(pcontact->data, pcontact->sz, sizeof(pcontact->data[0]), compare_addr);
			printf("排序成功\n");
			break;
		case nochange:
			printf("排序成功\n");
			break;
		default:printf("暂无该排序方式\n");
		}
	}
}

void showdata(const struct contact* pcontact)
{
	if (pcontact->sz == 0)
	{
		printf("通讯录为空，请添加联系人后再试\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-10s\t%-3s\t%-12s\t%-60s\n",
			"姓名", "性别", "年龄", "电话号码", "住址");
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