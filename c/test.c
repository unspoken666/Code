#include <stdio.h>
#include<stdlib.h>

int main()
{
	char ch;
	printf("������һ���ַ���(��!��β): ");
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