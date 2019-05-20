#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	char s[100][1024];
	int i = 0,j,k;
	if ((fp = fopen("hello.c", "r+")) == NULL)//打开操作不成功
	{
		perror("fopen");
		exit(1);
	}
	while (!feof(fp))
	{
		fgets(s[i], 1024, fp);

		i++;//读取的行数
	}
	for (k = i - 1; k >= 0; k--)//消除注释
	{
		for (j = 0; j < 1024; j++)
		{
			if (s[k][j] == '/' && s[k][j - 1] != '*' && (s[k][j + 1] == '/' || s[k][j + 1] == '*')) //注释有// 和/* 的情况
			{
				if (k != 0 && j != 0)
				{
					s[k][j] = '\n'; // 防止第一行是注释，消除完后，第一行变空
				}
				else
				{
					s[k][j] = '\0';
				}	
				s[k][j + 1] = '\0';
			}
			else if (s[k][j] == '/' && s[k][j - 1] == '*')  // 这是注释为 */ 的情况
			{
				s[k][0] = '\0';
			}
		}
	}
	fclose(fp);
	if ((fp = fopen("hello.c", "wb+")) == NULL)//打开操作不成功
	{
		perror("fopen");
		exit(1);
	}
	j = 0, k = 1;
	for (j = 0, k = 1; j < i - 1; j++, k++)//这个是加行号的   （i-1是因为前面有个i++，多加了一个1） 
	{
		if (strlen(s[j]) == 0)
		{
			k--;    //如果第一行为空，则跳过这次，并且不能使第一行行号变成2；所以要减去1 
			continue;
		}
		fputs("/*", fp);
		fprintf(fp, "%d", k);
		fputs("*/", fp);
		fputs(s[j], fp);
	}
	fclose(fp);
	return 0;
}