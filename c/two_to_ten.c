#include<stdio.h>
#include<string.h>
#include<math.h>

//将输入的 2 进制字符串转换为 10 进制数输出

int TwoToTen(char * str2)
{
	int len = strlen(str2);
	int i = 0;
	int dec = 0;
	for (i = 0; i < len; i++)
	{
		if (str2[i] == '1')
		{
			dec += pow(2, len-i-1);
		}
	}
	return dec;
}
int main()
{
	char str2[101] = "";
	gets_s(str2,100);
	int ret = TwoToTen(str2);
	printf("%d\n", ret);
	getchar();
	return 0;
}
