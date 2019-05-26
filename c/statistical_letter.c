#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_replace(char* a, int n, char* str)
{
	int len = strlen(str);
	char *tmp = a + n;
	if (n > len) //原字符串 str1 比要替换的字符串 str2 要长，字符串后面的元素要向前移动
	{
		while (*tmp)
		{
			*(tmp - (n - len)) = *tmp;
			tmp++;
		}
		*(tmp - (n - len)) = *tmp;  // '/0'也要拷贝

	}
	else if(n < len)     //原字符串 str1 比要替换的字符串 str2 要短，字符串后面的元素要向后移动
	{
		while (*tmp)tmp++;
		while (tmp >= a+n)
		{
			*(tmp + (len - n)) = *tmp;
			tmp--;
		}
	}
	strncpy(a, str, len);
}
int main()
{
	FILE *fp;
	char ch;
	int i = 0,count = 0;
	int a[26] = { 0 };
	char str1[1024];
	char str2[100],str3[100];
	char *p;
	if ((fp = fopen("English.txt", "r+")) == NULL)//打开操作不成功
	{
		perror("fopen");
		exit(1);
	}

	ch = fgetc(fp);
	while (ch != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
		{
			ch -= 32;
		}
		if (ch >= 'A' && ch <= 'Z')
		{
			a[ch - 'A']++;
		}
		ch = fgetc(fp);
	}
	for (i = 0; i < 26; i++)
	{
		printf("%c : %d\n", i+'a',a[i]);
	}

	printf("\n请输入你要查找的字符串和用于替换的字符串（中间用空格分隔）：");
	scanf("%s", str2);
	scanf("%s", str3);
	//从 English.txt 中读取字符串
	freopen("English.txt", "r+", stdin);
	i = 0;
	ch = getchar();
	while (ch != EOF)
	{
		str1[i] = ch;
		i++;
		ch = getchar();
	}
	str1[i] = '\0';
	p = strstr(str1, str2); //开始查找 str2
	while (p)
	{
		count++;
		//每找到一个 str2 就用 str3 替换
		str_replace(p, strlen(str2), str3);
		p = p + strlen(str3);
		p = strstr(p, str2);
	}
	printf("\ncount = %d\n", count);
	printf("Result = %s\n", str1);

	getchar();
	getchar();

	return 0;
}

