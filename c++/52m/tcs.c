#define _CRT_SECURE_NO_WARNINGS
#define TEST
#include "TCS.h"
//ȫ�ֱ���//
int maxlevel = MAXLEVEL;             //���ؿ���
int level = 0;                       //�ؿ�����0��ʾ�޾�ģʽ
int score = 0, add = 10;             //�ܵ÷���ÿ�γ�ʳ��÷�
int status, sleeptime = 200;         //ÿ�����е�ʱ����
snake *head, *food;	                 //��ͷָ�룬ʳ��ָ��
snake *q;                            //�����ߵ�ʱ���õ���ָ��
int endgamestatus = 0;               //��Ϸ�����������1��ײ��ǽ��2��ҧ���Լ���3�������˳���Ϸ��
int run = 0;                         //�ж���Ϸ�Ƿ�������
player top[61];                      //���а�
int MAX_LL = 130;                    //��Ϸ���ڳ���
int MAX_CC = 36;                     //��Ϸ���ڸ߶�
int MAX_L = 92;                      //��Ϸ���򳤶�
int MAX_C = 35;                      //��Ϸ����߶�
int steps = 0;                       //��������
int lenth = 4;                       //��������
acheve ach;                          //�ɾ�����
int mode = 0;                        //��Ϸģʽ  0  ����    1  ���
int istest = 0;                       //�Ƿ�Ϊ����ģʽ
lel map[MAXLEVEL + 1];
int weisuoyuwei = 0;                 //Ϊ����Ϊģʽ
int Color = 0;
List mainmenu = { { "��ʼ��Ϸ","��Ϸ˵��","�����ܰ�","�ɾ�ϵͳ","�˳���Ϸ" },5 };
List Modemenu = { { "��������ģʽ", "�ϰ�����ģʽ", "���ɴ���ģʽ", "�ϰ�����ģʽ" }, 4 };
List Mapmenu = { { "С�͵�ͼ", "�кŵ�ͼ", "���͵�ͼ" }, 3 };
List Maptopmenu = { { "С�͵�ͼ����", "�кŵ�ͼ����", "���͵�ͼ����" }, 3 };
void printmenu(List menu, int t)
{
	int i;
	for (i = 0; i <= menu.sz; i++)
	{
		Pos(MAX_LL / 2 - 6, MAX_CC / 2 - 7 + i * 2);
		if (i == t)
		{
			color(15 * 16);
		}
		else
		{
			color(0);
		}
		if (i <= menu.sz - 1)
			printf("  %s  \n\n", menu.name[i]);
	}
}
int Select(List menu)
{
	int t = 0;
	int recordt = 1;
	system("cls");
	print();
	Pos((MAX_LL - 78) / 2 - 1, MAX_CC / 5);
	printf(" ����������������                      ��                      ����������������");
	while (1)
	{
		if (recordt != t)
		{
			printmenu(menu, t);
		}
		Pos(158, 43);
		recordt = t;
		if (GetAsyncKeyState(VK_DOWN) && t < menu.sz - 1)
		{
			t++;
			Sleep(200);
		}
		if (GetAsyncKeyState(VK_UP) && t > 0)
		{
			t--;
			Sleep(200);
		}
		if (GetAsyncKeyState(VK_RETURN))
		{
			Sleep(200);
			return t;
		}
	}

}
//���ùؿ�
void push(int l, int x, int y)
{
	if (map[l].sz == map[l].capacity)
	{
		ppos tmp = realloc(map[l].pos, (map[l].capacity + 10) * sizeof(pos));
		if (tmp == NULL)
		{
			perror("realloc");
			exit(1);
		}
		map[l].pos = tmp;
		map[l].capacity += 10;
	}
	map[l].pos[map[l].sz].x = x;
	map[l].pos[map[l].sz].y = y;
	map[l].sz++;
}
//��ʼ���ؿ�
void initlevel()
{
	//MAX_LL = 160;
	//MAX_CC = 45;
	//MAX_L = 120;
	//MAX_C = 44;
	int i = 0;
	for (i = 0; i < 6; i++)
	{
		map[i].pos = (ppos)malloc(3 * sizeof(pos));
		map[i].capacity = 3;
		map[i].sz = 0;
	}
	for (i = 20; i <= 100; i += 4)
	{
		push(1, i, 22);
		push(2, i, 22);
		push(5, i, 22);
	}
	for (i = 8; i < 38; i += 2)
	{
		push(2, 60, i);
		push(3, 60, i);
		push(5, 60, i);
	}
	for (i = 28; i <= 92; i += 4)
	{
		push(3, i, 14);
		push(3, i, 28);
	}
	for (i = 20; i <= 100; i += 2)
	{
		if (i == 50)i = 72;
		push(4, i, 8);
		push(4, i, 36);
		push(5, i, 8);
		push(5, i, 36);
	}
	for (i = 9; i <= 36; i++)
	{
		if (i == 18)i = 28;
		push(4, 20, i);
		push(4, 100, i);
		push(5, 20, i);
		push(5, 100, i);
	}
	for (i = 4; i <= 116; i += 4)
	{
		push(6, i, 22);
		push(7, i, 22);
	}
	for (i = 2; i <= 42; i += 2)
	{
		push(7, 60, i);
	}
	for (i = 2; i < MAX_L - 2; i += 2)
	{
		if (abs(i - 60) <= 2)continue;
		push(8, i, 22);
		push(9, i, 22);
		if (abs(i - 60) > 6)
		{
			push(10, i, 1);
			push(10, i, 43);
		}
	}
	for (i = 1; i < MAX_C; i++)
	{
		if (abs(i - 22) <= 1)continue;
		push(9, 60, i);
		if (abs(i - 22) > 3)
		{
			push(10, 2, i);
			push(10, 118, i);
		}
	}
	for (i = 2; i < MAX_L - 2; i += 2)
	{
		push(10, i, 22);
	}
	for (i = 1; i < MAX_C; i++)
	{
		push(10, 60, i);
	}
}
//��ӡ�ؿ��ϰ�
void printlevel()
{
	int i = 0;
	for (i = 0; i < map[level].sz; i++)
	{
		Pos(map[level].pos[i].x, map[level].pos[i].y);
		printf("��");
	}
}
//��Ϸ�������ݻ���
void tfree(snake *p)
{
	if (p->next)
		tfree(p->next);
	free(p);
}
//����������ɫ
void color(int x)
{
	static int tmp = 0;
	if (x < 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), tmp);
		return;
	}
	if (!x)
	{
		do
		{
			x = rand() % 6 + 9;
		} while (tmp == x);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);  //ֻ��һ���������ı�������ɫ
		Color = tmp;
		tmp = x;
	}
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
//���ù��λ��
void Pos(int x, int y)
{
	COORD pos;
	HANDLE hOutput;
	pos.X = x;
	pos.Y = y;
	hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOutput, pos);
}
//������ͼ
void creatMap(int x)
{
	int i;
	char p[4] = { 0 };
	if (x)strcpy(p, "��");
	else strcpy(p, "��");
	PlaySound(NULL, NULL, NULL);
	for (i = 0; i < MAX_L; i += 2)//��ӡ���±߿�
	{
		Pos(i, 0);
		color(0);
		printf(p);
		Pos(i, MAX_C);
		color(0);
		printf(p);
		//if (!x)
		//Sleep(10);
	}
	for (i = 1; i < MAX_C; i++)//��ӡ���ұ߿� 
	{
		Pos(0, i);
		color(0);
		printf(p);
		Pos(MAX_L - 2, i);
		color(0);
		printf(p);
		//if (!x)
		//Sleep(10);
	}
}
//��ʼ������
void initsnake()
{
	snake *tail;
	int i;
	tail = (snake*)malloc(sizeof(snake));//����β��ʼ��ͷ�巨����x,y�趨��ʼ��λ��// 
	tail->x = 4;
	tail->y = 3;
	tail->next = NULL;
	for (i = 1; i <= 4; i++)
	{
		head = (snake*)malloc(sizeof(snake));
		head->next = tail;
		head->x = 4 + 2 * i;
		head->y = 3;
		tail = head;
	}
	Pos(tail->x, tail->y);
	printf("��");
	tail = tail->next;
	while (tail != NULL)//��ͷ��β���������
	{
		Pos(tail->x, tail->y);
		printf("��");
		tail = tail->next;
	}
}
//�ж��Ƿ�ҧ�����Լ�
int biteself()
{
	snake *self;
	self = head->next;
	while (self != NULL)
	{
		if (self->x == head->x && self->y == head->y)
		{
			return 1;
		}
		self = self->next;
	}
	return 0;
}
//�������ʳ��/�ϰ�
void createfood(int x)
{
	snake *food_1;
res:
	food_1 = (snake*)malloc(sizeof(snake));
	food_1->x = (rand() % (MAX_L - 4) + 2) / 2 * 2;//��֤��Ϊż����ʹ��ʳ��������ͷ����
	food_1->y = rand() % (MAX_C - 1) + 1;
	q = head;
	while (q != NULL)
	{
		if (q->x == food_1->x && q->y == food_1->y) //�ж������Ƿ���ʳ���غ�
		{
			free(food_1);
			goto res;
		}
		q = q->next;
	}
	if (level)
	{
		int i = 0;
		for (i = 0; i < map[level].sz; i++)
		{
			if (food_1->x == map[level].pos[i].x && food_1->y == map[level].pos[i].y)
			{
				free(food_1);
				goto res;
			}
		}
	}
	if (mode)
	{
		int i = 0;
		for (i = 0; i < map[0].sz; i++)
		{
			if (food_1->x == map[0].pos[i].x && food_1->y == map[0].pos[i].y)
			{
				free(food_1);
				goto res;
			}
		}
	}
	Pos(food_1->x, food_1->y);
	food = food_1;
	color(0);
	printf("��");
	if (mode&&x)
	{
		snake *food_1;
	res2:
		food_1 = (snake*)malloc(sizeof(snake));
		food_1->x = (rand() % (MAX_L - 4) + 2) / 2 * 2;//��֤��Ϊż����ʹ��ʳ��������ͷ����
		food_1->y = rand() % (MAX_C - 1) + 1;
		q = head;
		while (q != NULL)
		{
			if (q->x == food_1->x && q->y == food_1->y) //�ж������Ƿ���ʳ���غ�
			{
				free(food_1);
				goto res2;
			}
			q = q->next;
		}
		if (level)
		{
			int i = 0;
			for (i = 0; i < map[level].sz; i++)
			{
				if (food_1->x == map[level].pos[i].x && food_1->y == map[level].pos[i].y)
				{
					free(food_1);
					goto res;
				}
			}
		}
		if (mode)
		{
			int i = 0;
			for (i = 0; i < map[0].sz; i++)
			{
				if (food_1->x == map[0].pos[i].x && food_1->y == map[0].pos[i].y)
				{
					free(food_1);
					goto res;
				}
			}
		}
		Pos(food_1->x, food_1->y);
		push(0, food_1->x, food_1->y);
		//color(0);
		printf("��");
	}
}
//���ܴ�ǽ
void cantcrosswall()
{
	if (head->x == 0 || head->x == MAX_L - 2 || head->y == 0 || head->y == MAX_C)
	{
		system("color cf");
		Sleep(200);
		system("color 0f");
		Sleep(200);
		system("color cf");
		Sleep(200);
		system("color 0f");
		endgamestatus = 1;
		endgame();
	}
}
//����
void uplevel()
{
	system("cls");
	print();
	Pos(60, 22);
	printf("��ϲ���أ�������л��ؿ�");
	Sleep(3000);
	system("cls");
	endgame();
	lenth = 4;
	creatMap(weisuoyuwei);
	initsnake();
	createfood(mode);
	printlevel();
	status = R;
	PlaySound("running.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
}
//���ƶ�
void snakemove()
{
	int t = 0;
	snake * nexthead;
	if (!weisuoyuwei)
	{
		cantcrosswall();
	}
	if (run)return;
	nexthead = (snake*)malloc(sizeof(snake));
	if (status == U)
	{
		nexthead->x = head->x;
		nexthead->y = head->y - 1;
	}
	else if (status == D)
	{
		nexthead->x = head->x;
		nexthead->y = head->y + 1;
	}
	else if (status == L)
	{
		nexthead->x = head->x - 2;
		nexthead->y = head->y;
	}
	else if (status == R)
	{
		nexthead->x = head->x + 2;
		nexthead->y = head->y;
	}
	if (weisuoyuwei)
	{
		if (nexthead->x == 0)nexthead->x = MAX_L - 4;
		if (nexthead->x == MAX_L - 2)nexthead->x = 2;
		if (nexthead->y == 0)nexthead->y = MAX_C - 1;
		if (nexthead->y == MAX_C)nexthead->y = 1;
	}
	if (level)
	{
		int i = 0;
		for (i = 0; i < map[level].sz; i++)
		{
			if (nexthead->x == map[level].pos[i].x && nexthead->y == map[level].pos[i].y)
			{
				system("color cf");
				Sleep(200);
				system("color 0f");
				Sleep(200);
				system("color cf");
				Sleep(200);
				system("color 0f");
				endgamestatus = 4;
				endgame();
			}
			if (run)return;
		}
	}
	if (mode)
	{
		int i = 0;
		for (i = 0; i < map[0].sz; i++)
		{
			if (nexthead->x == map[0].pos[i].x && nexthead->y == map[0].pos[i].y)
			{
				system("color cf");
				Sleep(200);
				system("color 0f");
				Sleep(200);
				system("color cf");
				Sleep(200);
				system("color 0f");
				endgamestatus = 4;
				endgame();
			}
			if (run)return;
		}
	}
	else;
	if ((nexthead->x == food->x) && (nexthead->y == food->y))//�����һ����ʳ��//
	{
		nexthead->next = head;
		head = nexthead;
		createfood(1);
		q = head;
		Pos(q->x, q->y);
		color(Color);
		printf("��");
		Pos(q->next->x, q->next->y);
		printf("��");
		while (q->next != NULL)
		{
			q = q->next;
		}
		Pos(q->x, q->y);
		printf("��");
		Pos(MAX_LL - 4, MAX_CC - 2);
		printf("  ");
		PlaySound("error.wav", NULL, SND_FILENAME | SND_ASYNC | SND_NOSTOP);
		score = score + add * (mode + 1);
		lenth++;
		t = 0;
	}
	else                                               //���û��ʳ��//
	{
		nexthead->next = head;
		head = nexthead;
		q = head;
		Pos(q->x, q->y);
		//color(Color);
		printf("��");
		Pos(q->next->x, q->next->y);
		//color(0);
		printf("��");
		while (q->next->next != NULL)
		{
			q = q->next;
		}
		Pos(q->next->x, q->next->y);
		printf("  ");
		Pos(MAX_LL - 4, MAX_CC - 2);
		printf("  ");
		free(q->next);
		q->next = NULL;
	}
	steps++;
	t++;
	if (biteself() == 1)       //�ж��Ƿ��ҧ���Լ�
	{
		endgamestatus = 2;
		system("color cf");
		Sleep(200);
		system("color 0f");
		Sleep(200);
		system("color cf");
		Sleep(200);
		system("color 0f");
		endgame();
	}
	if (run)return;
	if (t % 300 == 0)
	{
		Pos(food->x, food->y);
		printf("  ");
		createfood(mode);
	}
	Pos(MAX_LL, MAX_CC);
}
//��ͣ
void pause()
{
	while (1)
	{
		Sleep(300);
		if (GetAsyncKeyState(VK_SPACE))
		{
			break;
		}
	}
}
//������Ϸ
void gamecircle()
{
	static int tscore = -1;
	static int tlenth = -1;
	static int tadd = -1;
	static int isweisuoyuwei = 0;
	static int tlel = 0;
	{
		PlaySound("running.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
		Pos(MAX_L + 4, 15);
		color(0);
		printf("���ܴ�ǽ������ҧ���Լ�\n");
		Pos(MAX_L + 4, 16);
		color(0);
		printf("�á�.��.��.���ֱ�����ߵ��ƶ�.");
		Pos(MAX_L + 4, 17);
		color(0);
		printf("F1 Ϊ���٣�F2 Ϊ����\n");
		Pos(MAX_L + 4, 18);
		color(0);
		printf("ESC ���˳���Ϸ.Space����ͣ��Ϸ.");
		Pos(MAX_L + 4, 20);
		color(0);
	}
	if (mode)
	{
		Pos(MAX_L + 4, 22);
		printf("���ģʽ��Ҳ���������ϰ�����");
	}
	printf("\n");
	status = R;
	while (1)
	{
		if (tlel != level)
		{
			Pos(MAX_L + 8, 8);
			printf("�ؿ�%d", level);
		}
		if (tscore != score || tadd != add)
		{
			Pos(MAX_L + 6, 10);
			printf("�÷֣�%d  ", score);
			Pos(MAX_L + 6, 11);
			printf("ÿ��ʳ��÷֣�%d��", add*(mode + 1));
		}
		if (weisuoyuwei != isweisuoyuwei)
		{
			creatMap(weisuoyuwei);
		}
		if (GetAsyncKeyState(VK_UP) && status != D)
		{
			status = U;
		}
		else if (GetAsyncKeyState(VK_DOWN) && status != U)
		{
			status = D;
		}
		else if (GetAsyncKeyState(VK_LEFT) && status != R)
		{
			status = L;
		}
		else if (GetAsyncKeyState(VK_RIGHT) && status != L)
		{
			status = R;
		}
		else if (GetAsyncKeyState(VK_SPACE))
		{
			pause();
		}
		else if (GetAsyncKeyState(VK_ESCAPE))
		{
			endgamestatus = 3;
			PlaySound(NULL, NULL, NULL);
			break;
		}
		tadd = add;
		if (GetAsyncKeyState(VK_F1))
		{
			if (sleeptime >= 50)
			{
				sleeptime = sleeptime - 30;
				add = add + 2;
				if (sleeptime == 320)
				{
					add = 2;//��ֹ����1֮���ټӻ����д�
				}
			}
		}
		else if (GetAsyncKeyState(VK_F2))
		{
			if (sleeptime < 350)
			{
				sleeptime = sleeptime + 30;
				add = add - 2;
				if (sleeptime == 350)
				{
					add = 1;  //��֤��ͷ�Ϊ1
				}
			}
		}
		isweisuoyuwei = weisuoyuwei;
		if (GetAsyncKeyState(VK_F5))
		{
			weisuoyuwei = 1;
		}
		if (GetAsyncKeyState(VK_F6))
		{
			weisuoyuwei = 0;
		}
		tlel = level;
		if (level&&tlenth != lenth && level != maxlevel)
		{
			Pos(MAX_L + 6, 12);
			printf("�ؿ����ȣ�%d/25", (lenth - 4) % 25);
			if (lenth - 4 == 25)
			{
				level++;
				endgamestatus = 0;
				uplevel();
			}
			if (level > 5)
				weisuoyuwei = 1;
		}
		Sleep(sleeptime);
		tscore = score;
		tlenth = lenth;
		snakemove();
		if (run)return;
	}
}
//������
void welcometogame()
{
	system("cls");
	//int i = 7;
	//color(13);
	//Pos(6, 7);
	//printf("��������        ��");
	//for (i = 8; i < 20; i++)
	//{
	//	Pos(6, i);
	//	printf("��");
	//	Pos(MAX_L + 6, i);
	//	printf("��");
	//}
	//Pos(6, i);
	//for (i = 6; i <= MAX_L + 6; i+=2)
	//	printf("��");
	print();
	Pos(MAX_L / 2 - 12, 7);
	color(15);
	printf("��");
	color(10);
	printf("��  ��  ��  ��");
	color(15);
	printf("�ֱ�����ߵ��ƶ�");
	Pos(MAX_L / 2 - 12, 9);
	color(12);
	printf("F1 ");
	color(15);
	printf("Ϊ����");
	color(12);
	printf(" F2 ");
	color(15);
	printf("Ϊ����\n");
	Pos(MAX_L / 2 - 12, 11);
	color(15);
	printf("���Զ�㼸��");
	color(11);
	printf(" F1 ");
	color(15);
	printf("����");
	color(11);
	printf(" F2 ");
	color(15);
	printf("�л�������Ϊ���ʺ�����Ѷ�\n");
	Pos(MAX_L / 2 - 12, 13);
	printf("���ٽ��ܵõ�");
	color(13);
	printf("���ߵķ�����");
	Pos(MAX_L / 2 - 12, 15);
	color(14);
	printf("��ʼ��������̰������Ϸ��  ^_^\n");
	Pos(MAX_L / 2 - 12, 25);
	color(15);
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
//������Ϸ
void endgame()
{
	char c;
	system("cls");
	Pos(MAX_L / 2, 12);
	if (endgamestatus == 1)
	{
		color(12);
		printf("���ź�����ײ����ǽ����Ϸ����.");
	}
	else if (endgamestatus == 2)
	{
		color(12);
		printf("���ź�����ҧ�����Լ�����Ϸ����.");
	}
	else if (endgamestatus == 3)
	{
		color(12);
		printf("���Ѿ���������Ϸ��");
	}
	else if (endgamestatus == 4)
	{
		color(12);
		printf("��ײ�����ϰ������ˣ�����");
	}
	else
	{
		ach.step += steps;
		ach.score += score;
		ach.eat += (lenth - 4);
		saveach();
		tfree(head);
		map[0].sz = 0;
		return;
	}
	print();
	PlaySound("death.wav", NULL, SND_FILENAME | SND_ASYNC);
	Pos(MAX_L / 2, 13);
	printf("��ĵ÷���:%d,�ڱ�����Ϸ����һ������:%d��", score, steps);
	if (score >= top[(MAX_LL - 70) / 30 * 20 - 1].scores&&endgamestatus)
	{
		Pos(MAX_L / 2, 14);
		system("pause");
		top[60].scores = score;
		sprintf(top[60].len, "%d", lenth);
		top[60].steps = steps;
		Pos(MAX_L / 2, 14);
		printf("��ϲ��������а񣡣�����");
		fflush(stdin);
		Pos(MAX_L / 2, 15);
		printf("�Ƿ�����������֣�(y/n)");
		scanf("%c", &c);
		if ('y' == c || 'Y' == c)
		{
			Pos(MAX_L / 2, 16);
			printf("����������ǳ�:>");
			scanf("%s", top[60].name);
			sorttop();
			Pos(MAX_L / 2, 17);
			printf("���а��Ѹ���...");
		}
		else
		{
			strcpy(top[60].name, "noname");
			sorttop();
			Pos(MAX_L / 2, 17);
			printf("���а��Ѹ���...");
		}
	}
	ach.step += steps;
	ach.score += score;
	ach.eat += (lenth - 4);
	saveach();
	tfree(head);
	run = 1;
	Pos(MAX_L / 2, 18);
	map[0].sz = 0;
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
//��Ϸ��ʼ��
void gamestart()
{
	char p[50];
	sleeptime = 200;
	score = 0;
	add = 10;
	steps = 0;
	lenth = 4;
	system("cls");
	run = 0;
	sprintf((char *)p, "mode con cols=%d lines=%d", MAX_LL, MAX_CC);
	system((const char*)p);
	creatMap(weisuoyuwei);
	initsnake();
	createfood(mode);
	//level = 5;
	printlevel();
}
//ѡ���ͼ����
void mapmenu()
{
	print();
	Pos((MAX_LL - 78) / 2 - 1, MAX_CC / 5);
	printf("����������������                      ��                      ����������������");
	Pos(MAX_LL / 2 - 6, MAX_CC / 2 - 5);
	printf("1.��ͼ��С");
	Pos(MAX_LL / 2 - 6, MAX_CC / 2 - 3);
	printf("2.��ͼ����");
	Pos(MAX_LL / 2 - 6, MAX_CC / 2 - 1);
	printf("3.��ͼ����");
	Pos((MAX_LL - 78) / 2 - 1, MAX_CC / 2 + 1);
	printf("ѡ����ĵ�ͼ��С:>");
}
//ѡ���ͼ
void selectmap()
{
	int input;
	do
	{
		if (istest)
			input = Select(Mapmenu) + istest;
#ifndef TEST
		system("cls");
		mapmenu();
		fflush(stdin);
		scanf("%d", &input);
#endif
		switch (input)
		{
		case 1:
			MAX_LL = 100;
			MAX_CC = 30;
			MAX_L = 64;
			MAX_C = 29;
			return;
			break;
		case 2:
			MAX_LL = 130;
			MAX_CC = 36;
			MAX_L = 92;
			MAX_C = 35;
			return;
			break;
		case 3:
			MAX_LL = 160;
			MAX_CC = 45;
			MAX_L = 122;
			MAX_C = 44;
			return;
			break;
		default:
			Pos((MAX_LL - 78) / 2 - 1, MAX_CC / 2 + 2);
			printf("��������");
			Sleep(500);
			break;
		}
	} while (1);
}
//��ӡ�߿�
void print()
{
	int i;
	for (i = 0; i < MAX_LL; i += 2)//��ӡ���±߿�
	{
		Pos(i, 0);
		color(0);
		printf("��");
		Pos(i, MAX_CC - 1);
		color(0);
		printf("��");
	}
	for (i = 1; i < MAX_CC; i++)//��ӡ���ұ߿� 
	{
		Pos(0, i);
		color(0);
		printf("��");
		Pos(MAX_LL - 2, i);
		color(0);
		printf("��");
	}
}
//���˵�
void menu()
{
	print();
	Pos((MAX_LL - 78) / 2 - 1, MAX_CC / 5);
	printf("����������������                      ��                      ����������������");
	Pos(MAX_LL / 2 - 6, MAX_CC / 2 - 7);
	printf("1.��ʼ��Ϸ");
	Pos(MAX_LL / 2 - 6, MAX_CC / 2 - 5);
	printf("2.��Ϸ���");
	Pos(MAX_LL / 2 - 6, MAX_CC / 2 - 3);
	printf("3.���а�");
	Pos(MAX_LL / 2 - 6, MAX_CC / 2 - 1);
	printf("4.�ɾ�");
	Pos(MAX_LL / 2 - 6, MAX_CC / 2 + 1);
	printf("0.�˳���Ϸ");
}
//ѡ��ģʽ����
void modemenu()
{
	print();
	Pos((MAX_LL - 78) / 2 - 1, MAX_CC / 5);
	printf("����������������                      ��                      ����������������");
	Pos(MAX_LL / 2 - 6, MAX_CC / 2 - 5);
	printf("1.����ģʽ");
	Pos(MAX_LL / 2 - 6, MAX_CC / 2 - 3);
	printf("2.�ϰ�����ģʽ");
	Pos(MAX_LL / 2 - 6, MAX_CC / 2 - 1);
	printf("3.����ģʽ");
	Pos(MAX_LL / 2 - 6, MAX_CC / 2 + 1);
	printf("4.�ϰ�����ģʽ");
	Pos((MAX_LL - 78) / 2 - 1, MAX_CC / 2 + 5);
	printf("ѡ�����ģʽ:>");
}
//ѡ��ģʽ
void selectmode()
{
	int input;
	do
	{
		if (istest)
			input = Select(Modemenu) + istest;
#ifndef TEST
		system("cls");
		modemenu();
		fflush(stdin);
		scanf("%d", &input);
#endif
		switch (input)
		{
		case 2:
			level = 0;
			mode = 1;
			selectmap();
			return;
		case 1:
			level = 0;
			mode = 0;
			selectmap();
			return;
			break;
		case 4:
			mode = 1;
			MAX_LL = 160;
			MAX_CC = 45;
			MAX_L = 120;
			MAX_C = 44;
			level = 1;
			return;
		case 3:
			mode = 0;
			MAX_LL = 160;
			MAX_CC = 45;
			MAX_L = 120;
			MAX_C = 44;
			level = 1;
			return;
		default:
			Pos((MAX_LL - 78) / 2 - 1, MAX_CC / 2 + 6);
			printf("��������");
			Sleep(500);
			break;
		}
	} while (1);
}
//��Ϸ���̿���
void game()
{
	//system("color 3f");
	selectmode();
	gamestart();
	gamecircle();
	system("cls");
}
//��ʼ����
void startshow()
{
	int i = 0;
	int t;
	PlaySound("show.wav", NULL, SND_ASYNC | SND_FILENAME);
	Pos((MAX_LL - 56) / 2 - 6, (MAX_CC - 10) / 2 + i++);
	Sleep(5);
	color(0);
	printf("����                ��������������������    ����������������");
	Pos((MAX_LL - 56) / 2 - 6, (MAX_CC - 10) / 2 + i++);
	//color(0);
	Sleep(45);
	printf("����                ��������������������    ����������������");
	Pos((MAX_LL - 56) / 2 - 6, (MAX_CC - 10) / 2 + i++);
	//color(0);
	Sleep(55);
	printf("����                ��                ��    ����");
	Pos((MAX_LL - 56) / 2 - 6, (MAX_CC - 10) / 2 + i++);
	//color(0);
	Sleep(45);
	printf("����                ��                ��    ����");
	Pos((MAX_LL - 56) / 2 - 6, (MAX_CC - 10) / 2 + i++);
	//color(0);
	Sleep(35);
	printf("����                ��������������������    ����");
	Pos((MAX_LL - 56) / 2 - 6, (MAX_CC - 10) / 2 + i++);
	//color(0);
	Sleep(25);
	printf("����                ��������������������    ����������������");
	Pos((MAX_LL - 56) / 2 - 6, (MAX_CC - 10) / 2 + i++);
	//color(0);
	Sleep(15);
	printf("����                ��������                ����������������");
	Pos((MAX_LL - 56) / 2 - 6, (MAX_CC - 10) / 2 + i++);
	//color(0);
	Sleep(15);
	printf("����                ����������                          ����");
	Pos((MAX_LL - 56) / 2 - 6, (MAX_CC - 10) / 2 + i++);
	//color(0);
	Sleep(25);
	printf("����                ����  ������                        ����");
	Pos((MAX_LL - 56) / 2 - 6, (MAX_CC - 10) / 2 + i++);
	//color(0);
	Sleep(35);
	printf("����                ����    ������                      ����");
	Pos((MAX_LL - 56) / 2 - 6, (MAX_CC - 10) / 2 + i++);
	//color(0);
	Sleep(45);
	printf("������������������  ����      ������        ����������������");
	Pos((MAX_LL - 56) / 2 - 6, (MAX_CC - 10) / 2 + i++);
	//color(0);
	Sleep(55);
	printf("������������������  ����        ������      ����������������");
	Sleep(500);
	Pos(MAX_LL / 2 + 10, (MAX_CC - 10) / 2 + i + 3);
	color(13);
	printf("��");
	Pos(0, (MAX_CC - 10) / 2 + i + 3);
	t = (MAX_CC - 10) / 2 + i + 3;
	color(14);
	for (i = 0; i < MAX_LL; i += 2)
	{
		Pos(i, t);
		printf("��");
		if (i >= 16)
		{
			Pos(i - 16, t);
			printf("  ");
		}
		if (i >= (MAX_LL / 2 + 8) && i <= (MAX_LL / 2 + 10))
		{
			color(13);
		}
		Sleep(15);
	}
	//system("pause");
}
//����ʳ���Ƿ�������ڵ�ͼ��
void test()
{
	int x = 0;
	int y = 0;
	system("cls");
	creatMap(weisuoyuwei);
	color(15);
	Pos(MAX_L + 4, 15);
	printf("����Esc��������״̬");
	while (1)    //��֤��Ϊż����ʹ��ʳ��������ͷ����
	{
		x = (rand() % (MAX_L - 4) + 2) / 2 * 2;
		y = rand() % (MAX_C - 1) + 1;
		Pos(x, y);
		color(0);
		printf("��");
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			break;
		}
	}
}
void testlevel(int x)
{
	system("mode con cols=160 lines=45");
	level = x;
	MAX_LL = 160;
	MAX_CC = 45;
	MAX_L = 122;
	MAX_C = 44;
	creatMap(weisuoyuwei);
	initlevel();
	printlevel();
	system("pause");
}
void testcolor()
{
	int i = 0;
	for (i = 0; i < 256; i++)
	{
		color(i);
		printf("%4d ", i);
		if (i % 16 == 0)printf("\n");
	}
	system("pause");
}
void testPos()
{
	int i = 0;
	for (i = 0; i < 15; i++)
	{
		Pos(i * 2, i);
		color(i);
		printf("��");
	}
	system("pause");
}
//������
int main()
{
	int t = 0;
	int input;
	char p[50];
	//testPos();
	//testcolor();
	//testlevel(10);
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &(CONSOLE_CURSOR_INFO) { 30, 0 });//�޸�λ�ñ�ʶ��Ϊ͸��
	istest = 1;
	system("title LRS-̰����");
	initlevel();
	color(0);
	srand((unsigned)time(NULL));
	inittop();
	loadach();
	sprintf((char *)p, "mode con cols=%d lines=%d", MAX_LL, MAX_CC);
	system((const char*)p);
	startshow();
	do {
		PlaySound("begin.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP | SND_NOSTOP);
		weisuoyuwei = 0;
		fflush(stdin);
		Sleep(300);
		//keybd_event(VK_ESCAPE, (BYTE)0, 0, 0);
		//keybd_event(VK_ESCAPE, (BYTE)0, KEYEVENTF_KEYUP, 0);
		if (GetAsyncKeyState(VK_RETURN) | GetAsyncKeyState(VK_UP) | GetAsyncKeyState(VK_DOWN));
		input = (Select(mainmenu) + 1) % 5;
#ifndef TEST
		system("cls");
		menu();
		Pos(MAX_LL / 2 - 14, MAX_CC / 2 + 3);
		printf("��ѡ��:>");
		scanf("%d", &input);
#endif
		switch (input)
		{
		case 5:
			test();
			break;
		case 4:
			showach();
			break;
		case 3:
			showtop();
			break;
		case 2:
			welcometogame();
			break;
		case 1:
			game();
			break;
		case 0:
			Sleep(100);
			break;
		default:
			Pos(MAX_LL / 2 - 14, MAX_CC / 2 + 4);
			printf("�����������������룡\n");
			Sleep(500);
			break;
		}
	} while (input);
	Pos(MAX_LL / 2 - 14, MAX_CC / 2 + 4);
	printf("��л������棬�ټ���");
	Sleep(800);
	return 0;
}
//int main()
//{
//	
//	int t = 0;
//	int input;
//	char p[50];
//	istest = 1;
//	main1();
//	istest = 1;
//	system("title LRS-̰����");
//	initlevel();
//	color(0);
//	srand((unsigned)time(NULL));
//	inittop();
//	loadach();
//	sprintf((char *)p, "mode con cols=%d lines=%d", MAX_LL, MAX_CC);
//	system((const char*)p);
//	startshow();
//	do{
//		PlaySound("begin.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP | SND_NOSTOP);
//		weisuoyuwei = 0;
//		system("cls");
//		menu();
//		Pos(MAX_LL / 2 - 14, MAX_CC / 2 + 3);
//		printf("��ѡ��:>");
//		//printf("%d", sizeof(player));
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 5:
//			test();
//			break;
//		case 4:
//			showach();
//			break;
//		case 3:
//			showtop();
//			break;
//		case 2:
//			welcometogame();
//			break;
//		case 1:
//			game();
//			break;
//		case 0:
//			Sleep(100);
//			break;
//		default:
//			Pos(MAX_LL / 2 - 14, MAX_CC / 2 + 4);
//			printf("�����������������룡\n");
//			Sleep(500);
//			break;
//		}
//	} while (input);
//	Pos(MAX_LL / 2 - 14, MAX_CC / 2 + 4);
//	printf("��л������棬�ټ���");
//	Sleep(800);
//	return 0;
//}