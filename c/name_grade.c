#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 80


struct student /*包含学生姓名和成绩*/
{
	char name[32];
	int English;
	int math;
};

int main()
{
	//定义一个名叫fp文件指针
	FILE *fp1, *fp2, *fp3;
	struct student info[MAXSIZE] = { 0 };
	char name[32] = "";
	int score = 0,i = 0, ret = 0, num = 0;

	//判断按读方式打开一个名叫db1,db2的文件是否失败
	if ((fp1 = fopen("db1.txt", "r")) == NULL || (fp2 = fopen("db2.txt", "r")) == NULL)//打开操作不成功
	{
		perror("fopen");
		exit(1);
	}

	fp3 = fopen("db3.txt", "w+");
	if (fp3 == NULL)
	{
		perror("fopen:");
		exit(1);
	}

	while (!feof(fp1))
	{
		ret = fscanf(fp1, "%s %d\n", name, &score);
		if (ret < 2)
			break;
		strcpy(info[i].name, name);
		info[i].English = score;
		i++;
		if (i >= MAXSIZE)
			break;
	}

	num = i;
	i = 0;
	while (!feof(fp2))
	{
		ret = fscanf(fp2, "%s %d\n", name, &score);
		if (ret < 2)
			break;
		while (i < num)
		{
			if (strcmp(name, info[i].name) == 0)
			{
				info[i].math = score;
				break;
			}
			i++;
		}
		//if (i >= num && i < MAXSIZE)
		//{
		//	strcpy(info[i].name, name);
		//	info[i].math = score;
		//	num++;
		//}
		if (i >= MAXSIZE)
			break;
		i = 0;
	}
	i = 0;
	while (i < num)
	{
		fprintf(fp3, "%s %d %d %.1lf\n", info[i].name, info[i].English, info[i].math, (info[i].English + info[i].math) * 1.0 / 2);
		i++;
	}

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	return 0;
}