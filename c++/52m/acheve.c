#define _CRT_SECURE_NO_WARNINGS
#include "TCS.h"
#define TEST
extern acheve ach;
extern int MAX_LL;
struct achname
{
	char name[20];
	int num;
}name[9] = { { "������",10000 }
,{ "�����й�",100000 } ,{"����̫��",1000000 },{"��θ��", 100}
,{ "�ϹŸ�����",10000 },{ "���漶����", 100000},{ "�÷ָ���",10000 }
,{ "�÷ִ�ʦ",100000 },{"�÷���ʦ",1000000 } };
//չʾ�ɾ�
void showach()
{
	int i = 0;
	system("cls");
	print();
	Pos(MAX_LL / 5, i + 3);
	color(15);
	printf("%-20s\t         %-12s\t", "�ɾ�", "״̬");
	for (i = 0; i < 9; i++)
	{
		color(i % 3 + 10);//�ж���ɫ
		Pos(MAX_LL / 5, 2 * (i + 1) + 3);
		printf("%-20s\t", name[i].name);
		switch (i / 3)//�ж�����
		{
		case 0:
			if (ach.step >= name[i].num)
			{
				printf("%10d/%-9d", name[i].num, name[i].num);
			}
			else
				printf("%10d/%-9d", ach.step, name[i].num);
			break;
		case 1:
			if (ach.eat >= name[i].num)
			{
				printf("%10d/%-9d", name[i].num, name[i].num);
			}
			else
				printf("%10d/%-9d", ach.eat, name[i].num);
			break;
		case 2:
			if (ach.score >= name[i].num)
			{
				printf("%10d/%-9d", name[i].num, name[i].num);
			}
			else
				printf("%10d/%-9d", ach.score, name[i].num);
			break;
		}
	}
	Pos(MAX_LL / 5, 2 * (i + 1) + 5);
	printf("�߹����ܲ���:%d��\t�Թ���ʳ������:%d��\t�õ����ܷ���:%d��", ach.step, ach.eat, ach.score);
	Pos(MAX_LL / 5, 2 * (i + 1) + 7);
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
//����
void loadach()
{
	FILE* c = fopen("ach.52m", "a+");//���û�о��½�
	FILE* load = fopen("ach.52m", "rb");
	fclose(c);
	c = NULL;
	if (load == NULL)
	{
		perror("load ach");
		exit(1);
	}
	ach.eat = 0;
	ach.score = 0;
	ach.step = 0;
	fread(&ach, sizeof(acheve), 1, load);
	fclose(load);
	load = NULL;
}
//����
void saveach()
{
	FILE* save = fopen("ach.52m", "wb");
	if (save == NULL)
	{
		perror("save ach");
		exit(1);
	}
	fwrite(&ach, sizeof(acheve), 1, save);
	fclose(save);
	save = NULL;
}