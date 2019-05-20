#include <stdio.h>
#include <stdlib.h>

void sort(char *a, int len)
{
	int i;
	int j;

	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - i - 1; j++)
		{
			if (a[j] > a[j + 1])
			{
				char temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main()
{
	FILE *fp1, *fp2, *fp3;
	char a[1024] = "";
	int i = 0;
	char tmp;
	if ((fp1 = fopen("A.dat", "r")) == NULL || (fp2 = fopen("B.dat", "r")) == NULL)//打开操作不成功
	{
		perror("fopen");
		exit(1);
	}
	while (!feof(fp1))
	{
		fscanf(fp1, "%c", &tmp);
		a[i] = tmp;
		i++;
	}
	while (!feof(fp2))
	{
		fscanf(fp2, "%c", &tmp);
		a[i] = tmp;
		i++;
	}
	sort(&a, i);
	int len = i - 1;

	fp3 = fopen("C.dat", "w+");
	if (fp3 == NULL)
	{
		perror("fopen:");
		exit(1);
	}
	for (i = 0; i < len; i++)
	{
		fprintf(fp3, "%c", a[i]);
	}

	fclose(fp1);
	fclose(fp2);
	fclose(fp3);

	return 0;
}

