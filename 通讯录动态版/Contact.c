#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
void initdate(date*people)
{
	people->count = 0;
	people->max = 2;
	people->my_people = (person*)calloc(2, sizeof(person));
	if (people->my_people == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(EXIT_FAILURE);
	}
}
void Desdate(date* people)
{
	free(people->my_people);
	people->my_people = NULL;
	people->max = 0;
	people->count = 0;
}
void Req_mem(date *people)
{
	person*p = (person*)realloc(people->my_people, (people->max += 5)*sizeof(person));
	if (p != NULL)
	{
		people->my_people = p;
		printf("���ݳɹ���\n");
		return;
	}
	else
	{
		printf("%s", strerror(errno));
		exit(EXIT_FAILURE);
	}
}
void Dec_mem(date *people)
{
	person*p = (person*)realloc(people->my_people, (people->max -= 5)*sizeof(person));
	if (p != NULL)
	{
		people->my_people = p;
		printf("���ݳɹ���\n");
		return;
	}
	else
	{
		printf("%s", strerror(errno));
		exit(EXIT_FAILURE);
	}
}
static int find_date(date*people, char name[])
{
	assert(people);
	int i = 0;
	for (i = 0; i < people->count; i++)
	{
		if (strcmp(name, people->my_people[i].name) == 0)
		{
			return i;
		}
	}
	return -1;
}
void Add(date*people)
{
	assert(people);
	int i = 0;
	if (people->count == MAX)
	{
		printf("ͨѶ¼������\n");
		return;
	}
	if ((people)->count == people->max - 1)
	{
		Req_mem(people);
	}
	if ((people->count) < (people->max))
	{
		printf("������Ҫ��ӵ���ϵ�����֡�\n");
		scanf("%s", (people)->my_people[(people)->count].name);
		printf("������Ҫ�����ϵ���Ա�\n");
		scanf("%s", people->my_people[people->count].sex);
		printf("������Ҫ�����ϵ�����䡣\n");
		scanf("%d", &(people->my_people[people->count].age));
		printf("������Ҫ�����ϵ�˵绰��\n");
		scanf("%s", people->my_people[people->count].tell);
		for (i = 0; i < people->count; ++i)
		{
			if (strcmp(people->my_people[people->count].tell, people->my_people[i].tell) == 0)
			{
				printf("�������ϵ���Ѿ����ڣ������������ӡ�\n");
				system("pause");
				return;
			}
		}
		printf("������Ҫ�����ϵ�˵�ַ��\n");
		scanf("%s", people->my_people[people->count].address);
		printf(" ���ӳɹ���\n");
		(people->count)++;
	}
}
void Del(date*people)
{
	assert(people);
	char name[MAX_NAME] = { 0 };
	int pos = 0;
	if (people->count == 0)
	{
		printf("û�п�ɾ��ϵ�ˣ�ͨѶ¼Ϊ�գ�\n");
		return;
	}
	if ((people)->count == people->max - 10)
	{
		Dec_mem(people);
	}
	printf("��������Ҫɾ������ϵ�˵����֡�\n");
	scanf("%s", name);
	pos = find_date(people, name);
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����,��鿴������ϵ���Ƿ����\n");
		return;
	}
	else
	{
		int i = 0;
		for (i = pos; i < people->count - 1; i++)
		{
			people->my_people[i] = people->my_people[i + 1];
		}
		people->count--;
		printf("ɾ���ɹ���\n");
	}
}
void Find(date*people)
{
	assert(people);
	if (people->count == 0)
	{
		printf("��ͨѶ¼��\n");
		return;
	}
	int fpos = 0;
	char name[MAX_NAME] = { 0 };
	printf("��������Ҫ������ϵ�˵����֡�\n");
	scanf("%s", name);
	fpos = find_date(people, name);
	if (fpos == -1)
	{
		printf("û����Ҫ���ҵ���ϵ�ˡ�\n");
		return;
	}
	else
	{
		printf("|%-15s\t|%-5s\t|%-5s\t|%-15s\t|%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("|%-15s\t|%-5s\t|%-5d\t|%-15s\t|%-20s\n",
			people->my_people[fpos].name
			, people->my_people[fpos].sex
			, people->my_people[fpos].age
			, people->my_people[fpos].tell
			, people->my_people[fpos].address);
	}
	return;
}
void change(date*people)
{
	assert(people);
	if (people->count == 0)
	{
		printf("��ͨѶ¼��\n");
		return;
	}
	int pos = 0;
	char name[MAX_NAME] = { 0 };
	printf("��������Ҫ�޸���ϵ�˵����֡�\n");
	scanf("%s", name);
	pos = find_date(people, name);
	if (pos == -1)
	{
		printf("û����Ҫ�޸ĵ���ϵ�ˡ�\n");
		return;
	}
	else
	{
		printf("��������Ҫ�޸��˵����֡�\n");
		scanf("%s", people->my_people[pos].name);
		printf("��������Ҫ�޸��˵��Ա�\n");
		scanf("%s", people->my_people[pos].sex);
		printf("��������Ҫ�޸��˵����䡣\n");
		scanf("%d", &(people->my_people[pos].age));
		printf("��������Ҫ�޸��˵ĵ绰��\n");
		scanf("%s", people->my_people[pos].tell);
		printf("��������Ҫ�޸��˵ĵ�ַ��\n");
		scanf("%s", people->my_people[pos].address);
		printf("|%-15s\t|%-5s\t|%-5s\t|%-15s\t|%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
		printf("|%-15s\t|%-5s\t|%-5d\t|%-15s\t|%-20s\n",
			people->my_people[pos].name
			, people->my_people[pos].sex
			, people->my_people[pos].age
			, people->my_people[pos].tell
			, people->my_people[pos].address);
	}
	return;
}
void show(date*people)
{
	assert(people);
	int i = 0;
	if (people->count == 0)
	{
		printf("��ͨѶ¼��\n");
		system("pause");
		return;
	}
	printf("|%-15s\t|%-5s\t|%-5s\t|%-15s\t|%-20s\n", "����", "�Ա�", "����", "�绰", "��ַ");
	for (i = 0; i <= people->count - 1; ++i)
	{
		printf("|%-15s\t", people->my_people[i].name);
		printf("|%-5s\t", people->my_people[i].sex);
		printf("|%-5d\t", people->my_people[i].age);
		printf("|%-15s\t", people->my_people[i].tell);
		printf("|%-20s\n", people->my_people[i].address);
	}
	printf("\n");
}
void sort(date*people)
{
	if (people == NULL)
	{
		printf(" ��ͨѶ¼��\n  ");
		return;
	}
	int i = 0;
	for (; i < people->count - 1; ++i)
	{
		int j = 0;
		for (; j<people->count - 1 - i; ++j)
		{
			if (strcmp(people->my_people[j].name, people->my_people[j + 1].name) > 0)
			{
				person tmp = people->my_people[j];
				people->my_people[j] = people->my_people[j + 1];
				people->my_people[j + 1] = tmp;
			}
		}
	}
	show(people);
}
