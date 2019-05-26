#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_replace(char* a, int n, char* str)
{
	int len = strlen(str);
	char *tmp = a + n;
	if (n > len) //ԭ�ַ��� str1 ��Ҫ�滻���ַ��� str2 Ҫ�����ַ��������Ԫ��Ҫ��ǰ�ƶ�
	{
		while (*tmp)
		{
			*(tmp - (n - len)) = *tmp;
			tmp++;
		}
		*(tmp - (n - len)) = *tmp;  // '/0'ҲҪ����

	}
	else if(n < len)     //ԭ�ַ��� str1 ��Ҫ�滻���ַ��� str2 Ҫ�̣��ַ��������Ԫ��Ҫ����ƶ�
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
	if ((fp = fopen("English.txt", "r+")) == NULL)//�򿪲������ɹ�
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

	printf("\n��������Ҫ���ҵ��ַ����������滻���ַ������м��ÿո�ָ�����");
	scanf("%s", str2);
	scanf("%s", str3);
	//�� English.txt �ж�ȡ�ַ���
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
	p = strstr(str1, str2); //��ʼ���� str2
	while (p)
	{
		count++;
		//ÿ�ҵ�һ�� str2 ���� str3 �滻
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

