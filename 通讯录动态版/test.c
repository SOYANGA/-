#define _CRT_SECURE_NO_WARNINGS 1
#include "Contact.h"
void menu()
{
	printf("---------------------     Contact   ---------------------------\n");
	printf("-------------1.�����ϵ��         2.ɾ����ϵ��-----------------\n");
	printf("-------------3.������ϵ��         4.�޸���ϵ��-----------------\n");
	printf("-------------5.��ʾ��ϵ��         6.�����ϵ��-----------------\n");
	printf("-------------7.������ϵ��         0.�˳�Contact----------------\n");
}
int main()
{
	int input = 0;
	date people;
	initdate(&people);
	do
	{
		menu();
		printf("����������Ҫִ�еĲ�����\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Add(&people);
			break;
		case 2:
			Del(&people);
			break;
		case 3:
			Find(&people);
			break;
		case 4:
			change(&people);
			break;
		case 5:
			show(&people);
			break;
		case 6:
			initdate(&people);
			break;
		case 7:
			sort(&people);
			break;
		case 0:
			Desdate(&people);
			printf("�ɹ��˳���ллʹ�á�\n");
			break;
			return 0;
		default:
			printf("����Ƿ�ָ�\n");
			break;
		}
	} while (input);
	system("pause");
	return 0;
}