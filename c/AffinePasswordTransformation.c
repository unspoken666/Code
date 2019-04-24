#include"stdio.h"
#include"stdlib.h"
#include"math.h"

int Judge(int a)                   //判断a是否与26互素，互素返回0
{
	int c,k=26;
	while(a!=0)
		{
			c=a;
			a=k%a;
			k=c;
		}
	if(k==1)  return 0;
	else return 1;
}

int Decode(char toDecode, int a, int b)       //解密
{
    int n;
    for (n=0;n<=5000;n++)
    {
        if ((toDecode-b+26*n)%a==0)
        {
            return (toDecode-b+26*n)/a;
        }
    }
}


main()
{
	int a,b,i;
	char message[50];               //明文
    char copy[50];                  //密文
    char demessage[50];             //解密后的明文
	puts("输入明文：");
    gets(message,50);
	puts("输入密钥a b：");
	scanf("%d %d",&a,&b);
	while (Judge(a)==1)
		{
            printf("a要与26互素！请重新输入密钥:\n");
            scanf("%d\n", &a);
		}
	printf("a=%d  b=%d\n",a,b);               //密钥
	for (i=0;message[i]!='\0';i++)            //加密
    {
        if(message[i]>='a'&&message[i]<='z') 
        {
            copy[i]=((message[i]-'a')*a+b)%26+'a';
        }
        else if (message[i]>='A'&&message[i]<='Z')
        {
            copy[i]=((message[i]-'A')*a+b)%26+'A';
        }
        else
        {
            copy[i]=message[i];
        }
    }
    copy[i]='\0';
    puts("密文：");
    puts(copy);

	for (i=0;copy[i]!='\0';++i)    //解密
    {
        if (copy[i]>='a'&&copy[i]<='z')
        {
            demessage[i]='a'+Decode(copy[i]-'a',a,b);
        }
        else if (copy[i]>='A'&&copy[i]<='Z')
        {
            demessage[i] ='A'+Decode(copy[i]-'A',a,b);
        }
        else
        {
            demessage[i] = copy[i];
        }
    }
    demessage[i] = '\0';
    puts("解密密文：");
    puts(demessage);
}

