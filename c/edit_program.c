#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *fp;
	char s[100][1024];
	int i = 0,j,k;
	if ((fp = fopen("hello.c", "r+")) == NULL)//�򿪲������ɹ�
	{
		perror("fopen");
		exit(1);
	}
	while (!feof(fp))
	{
		fgets(s[i], 1024, fp);

		i++;//��ȡ������
	}
	for (k = i - 1; k >= 0; k--)//����ע��
	{
		for (j = 0; j < 1024; j++)
		{
			if (s[k][j] == '/' && s[k][j - 1] != '*' && (s[k][j + 1] == '/' || s[k][j + 1] == '*')) //ע����// ��/* �����
			{
				if (k != 0 && j != 0)
				{
					s[k][j] = '\n'; // ��ֹ��һ����ע�ͣ�������󣬵�һ�б��
				}
				else
				{
					s[k][j] = '\0';
				}	
				s[k][j + 1] = '\0';
			}
			else if (s[k][j] == '/' && s[k][j - 1] == '*')  // ����ע��Ϊ */ �����
			{
				s[k][0] = '\0';
			}
		}
	}
	fclose(fp);
	if ((fp = fopen("hello.c", "wb+")) == NULL)//�򿪲������ɹ�
	{
		perror("fopen");
		exit(1);
	}
	j = 0, k = 1;
	for (j = 0, k = 1; j < i - 1; j++, k++)//����Ǽ��кŵ�   ��i-1����Ϊǰ���и�i++�������һ��1�� 
	{
		if (strlen(s[j]) == 0)
		{
			k--;    //�����һ��Ϊ�գ���������Σ����Ҳ���ʹ��һ���кű��2������Ҫ��ȥ1 
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