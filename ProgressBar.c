#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include<time.h>
#define max1 100  //�������������Ϊ200000
#define min1 0  //���������С����Ϊ30000
int main()
{
	char bar[102] = "\0";

	int i = 0;
	int n = 0;
	const char* lable = "|/-\\-";
	for (i = 0; i <= 100; i += 2)
	{
		srand(time(0));//������������
		system("color 1");
		printf("%-100s%d%%[%c]\r", bar, i, lable[i % 5]);
		fflush(stdout);//ˢ�������
		bar[i] = 0xa8;//����������
		bar[i + 1] = 0x80;
		n = rand() % (max1 - min1) + min1;
		Sleep(n);//���ߺ���Ƕ����������ɺ���
	}
	printf("\n");
	system("pause");
	return 0;
}