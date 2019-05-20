#include <stdio.h>
#include<stdlib.h>

int main()
{
	char ch;
	printf("请输入一个字符串(以!结尾): ");
	ch = getchar();
	FILE *fp = fopen("test.dat", "w+");
	if (fp == NULL)
	{
		perror("fopen2:");
		exit(1);
	}
	while (ch != '!')
	{
		if (ch >= 'a'&&ch <= 'z')
			ch -= 32;
		fputc(ch, fp);
		ch = getchar();
	}
	return 0;
}