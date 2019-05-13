#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void sort(int *a, int len)
{
	int i;
	int j;

	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main()
{
	//定义一个名叫fp文件指针
	FILE *fp1, *fp2, *fp3;
	int a[1024] = { 0 };
	int i = 0,tmp = 0,len = 0;

	//判断按读方式打开一个名叫test的文件是否失败
	if ((fp1 = fopen("num1.txt", "r")) == NULL || (fp2 = fopen("num2.txt", "r")) == NULL)//打开操作不成功
	{
		perror("fopen");
		exit(1);
	}
	while (!feof(fp1))
	{
		fscanf(fp1, "%d", &tmp);
		a[i] = tmp;
		i++;
	}
	while (!feof(fp2))
	{
		fscanf(fp2, "%d", &tmp);
		a[i] = tmp;
		i++;
	}
	

	sort(&a,i);
	len = i - 1;
	

	fp3 = fopen("num3.txt", "w+");
	if (fp3 == NULL)
	{
		perror("fopen2:");
		exit(1);
	}

	for (i = 0; i < len; i++)
	{
		fprintf(fp3, "%d ", a[i]);
	}
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	return 0;
}