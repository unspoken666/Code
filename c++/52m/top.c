#define _CRT_SECURE_NO_WARNINGS
#define TEST
#include "TCS.h"
//ȫ�ֱ���//
extern int level;                          //�ؿ�����0��ʾ�޾�ģʽ
extern int score, add;                    //�ܵ÷���ÿ�γ�ʳ��÷�
extern int status, sleeptime;              //ÿ�����е�ʱ����
extern snake *head, *food;                  //��ͷָ�룬ʳ��ָ��
extern snake *q;                            //�����ߵ�ʱ���õ���ָ��
extern int endgamestatus;                  //��Ϸ�����������1��ײ��ǽ��2��ҧ���Լ���3�������˳���Ϸ��
extern int run;                            //�ж���Ϸ�Ƿ�������
extern player top[61];                      //���а�
extern int MAX_LL;
extern int MAX_CC;
extern int MAX_L;
extern int MAX_C;
extern int istest;
extern List Maptopmenu;
//��ʼ������
void inittop()
{
	int j = 0;
	for (j = 0; j < 3; j++)
	{
		int i = 0;
		top[20 * j + i].scores = 999;
		sprintf(top[20 * j + i].len, "%d", 56);
		top[20 * j + i].steps = 1658;
		for (i = 1; i < 20; i++)
		{
			top[20 * j + i].scores = 480 - 20 * i;
			sprintf(top[20 * j + i].len, "%d", 48 - 2 * i);
			top[20 * j + i].steps = 999 - 20 * i;
		}
		for (i = 0; i < 21; i++)
		{
			strcpy(top[20 * j + i].name, "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0");
			strcpy(top[20 * j + i].name, "LRS");
		}
	}
	top[60].scores = 0;
	loadtop();
}
//���в˵�
int topmenu()
{
	int input;
	do
	{
		if (istest)
			input = Select(Maptopmenu) + istest;
#ifndef TEST
		system("cls");
		mapmenu();
		fflush(stdin);
		scanf("%d", &input);
#endif
		switch (input)
		{
		case 1:
			return 0;
			break;
		case 2:
			return 1;
			break;
		case 3:
			return 2;
			break;
		default:
			Pos((MAX_LL - 78) / 2 - 1, MAX_CC / 2 + 2);
			printf("��������");
			Sleep(500);
			break;
		}
	} while (1);
}
//��ʾ����
void showtop()
{
	int i = 0;
	int j = topmenu();
	system("cls");
	print();
	Pos(MAX_LL / 5, i + 3);
	color(15);
	printf("%-5s\t%-20s%-6s\t%-3s\t%-8s", "����", "�ǳ�", "����", "�峤", "·��");
	for (i = 0; i < 20; i++)
	{
		Pos(MAX_LL / 5, i + 4);
		if (i < 20)color(15);
		if (i < 10)color(10);
		if (i < 5)color(9);
		if (i < 3)color(13);
		if (i < 2)color(14);
		if (i < 1)color(12);
		printf("%-5d\t%-20s%-6d\t%-3s\t%-8d", i + 1, top[j * 20 + i].name, top[j * 20 + i].scores, top[j * 20 + i].len, top[j * 20 + i].steps);
	}
	Pos(MAX_LL / 5, i + 6);
#ifndef TEST
	system("pause");
#endif
#ifdef TEST
	printf("���¿ո������...");
	while (1)
	{
		if (GetAsyncKeyState(VK_SPACE))
			return;
	}
#endif
}
//��������
void sorttop()
{
	int i = 0;
	int j = 0;
	int m = (MAX_LL - 100) / 30 * 20;
	for (i = 0; i < 20; i++)
	{
		if (top[60].scores >= top[m + i].scores)
		{
			for (j = 19 + m; j > (i + m); j--)
			{
				top[j] = top[j - 1];
			}
			top[i + m] = top[60];
			break;
		}
	}
	savetop();
}
//����
void loadtop()
{
	int ret = 0;
	FILE* c = fopen(Filename, "a+");
	FILE* load = fopen(Filename, "rb");
	fclose(c);
	c = NULL;
	if (load == NULL)
	{
		perror("load top");
		exit(1);
	}
	while (fread(&top[ret++], sizeof(player), 1, load));
	//printf("%d", ret);
	//system("pause");
	fclose(load);
	load = NULL;
}
//����
void savetop()
{
	int i = 0;
	FILE* save = fopen(Filename, "w");
	if (save == NULL)
	{
		perror("save top");
		exit(1);
	}
	fwrite(&top[0], sizeof(player), 60, save);
	fclose(save);
	save = NULL;
}