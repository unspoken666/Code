#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 1024
#define MAXSIZE 80

//真真真真真真真真真真真真真真真真� 80�

int main()
{

	//協吶匯倖兆出fp猟周峺寞
	FILE *fp1,*fp2;
	char buffer1[SIZE] = "";
	char buffer2[SIZE] = "";
	int i = 0;

	//登僅梓響圭塀嬉蝕匯倖兆出test議猟周頁倦払移
	if ((fp1 = fopen("test1.txt","r")) == NULL || (fp2 = fopen("test2.txt", "r")) == NULL)//嬉蝕荷恬音撹孔
	{
		printf("The file can not be opened.\n");
		exit(1);//潤崩殻會議峇佩
	}
	while (fgets(buffer1, MAXSIZE, fp1) && fgets(buffer2, MAXSIZE, fp2))
	{
		if (strcmp(buffer1, buffer2) == 0)
		{
			i++;
			continue;
		}
		else
		{
			fputs(buffer1, stdout);
			fputs(buffer2, stdout);
			break;
		}
	}
	printf("\nline: %d\n", i);

	if (ferror(fp1) || ferror(fp2)) 
	{
		fprintf(stderr, "error writing stdout\n");
		exit(2);
	}

	fclose(fp1);
	fclose(fp2);
	return 0;

}
