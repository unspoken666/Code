#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j,x=1,n,d,k=0,sum=0,c,z,res=0,flag=0;
	int A[2][2] = { 0 },AN[2][2] = { 0 },m[2][10] = { 0 },ciph[2][10] = { 0 },decode[2][10] = { 0 };
    char p[20]={0};
    printf("请输入密钥矩阵A:\n");//密钥矩阵A
    for (i = 0; i < 2; i++)
	{
	    for (j = 0; j < 2; j++)
		{
		      scanf("%d", &A[i][j]);
		}
	}
    x=(A[0][0]*A[1][1]-A[0][1]*A[1][0]+26*10)%26; //求矩阵A的逆AN
//  printf("行列式的值x:%d\n",x);        //行列式的值
	for(n=1;n<500;n++)
	{
		d=x*n;
		if(d%26==1)
		{
//		    printf("行列式的值的逆n:%d\n",n); //行列式的值的逆
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("矩阵不可逆\n");
		return 0;
	}
	AN[0][0]=A[1][1]*n%26;
	AN[0][1]=(-A[0][1]*n+26*1000)%26;
    AN[1][0]=(-A[1][0]*n+26*1000)%26;
	AN[1][1]=A[0][0]*n%26;
	printf("密钥矩阵A的逆:\n");
	for (i = 0; i < 2; i++)
	{
	    for (j = 0; j < 2; j++)
		{
		      printf("%d  ", AN[i][j]);
		}
	}

   printf("\n请输入明文：\n");
   scanf("%s",p);
   for (j = 0; j < 10; j++)
   {
	    for (i = 0; i < 2; i++)
		{
		    if (p[k]!='\0')
			{
			      m[i][j] = p[k]-'a';
				  k++;
			}
		    else
			     break;
		}
   }  
    printf("密文：\n");//加密
	for (z= 0; z < 10; z++) 
	{
		for (c = 0; c < 2; c++)
		{
			for (k = 0; k < 2; k++)
			{
				sum = sum + A[c][k] * m[k][z];
			}
			ciph[c][z] = sum % 26;
			sum = 0;
			printf("%c",ciph[c][z]+'a');
		}
	}
	printf("\n");
	printf("明文：\n"); //解密
	for (z = 0; z < 10; z++) 
	{
		for (c = 0; c < 2; c++) 
		{
			for (k = 0; k < 2; k++) 
			{
				res = res + AN[c][k] * (ciph[k][z]);
			}
			decode[c][z] = res % 26;
			res = 0;
			printf("%c",decode[c][z]+'a');
		}
	} 
	printf("\n");



/*
  由于由明文和密文求解加密矩阵只对部分明文有效，所以这部分注释掉了
    y=(m[0][0]*m[1][1]-m[0][1]*m[1][0]+26*10)%26;  //行列式
	for(s=1;s<500;s++)
	{
		d=y*s;
		if(d%26==1)
		{
//		    printf("行列式的值的逆s:%d\n",s); //行列式的值的逆
			flagg=1;
			break;
		}
	}
    if(flagg==0)
	{
		printf("矩阵不可逆\n");
		return 0;
	}
	mn[0][0]=m[1][1]*s%26;
	mn[0][1]=(-m[0][1]*s+26*1000)%26;
    mn[1][0]=(-m[1][0]*s+26*1000)%26;
	mn[1][1]=m[0][0]*s%26;
	printf("明文矩阵m的逆:\n");
	for (i = 0; i < 2; i++)
	{
	    for (j = 0; j < 2; j++)
		{
		      printf("%d  ", mn[i][j]);
		}
	}
    B[0][0]=(ciph[0][0]*mn[0][0]+ciph[0][1]*mn[1][0])%26;
	B[0][1]=(ciph[0][0]*mn[0][1]+ciph[0][1]*mn[1][1])%26;
	B[1][0]=(ciph[1][0]*mn[0][0]+ciph[1][1]*mn[1][0])%26;
	B[1][1]=(ciph[1][0]*mn[0][1]+ciph[1][1]*mn[1][1])%26;
	printf("\n加密矩阵:\n");
	for (i = 0; i < 2; i++)
	{
	    for (j = 0; j < 2; j++)
		{
		      printf("%d  ", B[i][j]);
		}
	}                                                    */
    return 0;
}

