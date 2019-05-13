#include<stdio.h>
#include<string.h>

//用一个整型数组表示 10 进制大整数，数组的每个元素存储大整数的一位数字，将
//这个大整数转换为 2 进制数输出

int main()
{
	char m[1001];
	int i, a[1000], n[1000];

	while (gets_s(m,1000))
	{
		int k = strlen(m), j = 0;
		while (1)
		{
			n[j++] = (m[k - 1] - '0') % 2;
			int c = 0;
			for (i = 0; i < k; i++)
			{
				int s = ((m[i] - '0') + 10 * c) / 2;
				c = (m[i] - '0') % 2;
				m[i] = s + '0';
			}
			for (i = 0; i < k; i++)
				if (m[i] != '0') break;
			if (i == k) break;
		}
		for (i = j - 1; i >= 0; i--) printf("%d", n[i]);
		printf("\n");
	}
	return 0;
}

