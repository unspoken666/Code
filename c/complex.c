#include <stdio.h>  

//设计一个复数类型，输入实部和虚部生成一个复数，可进行两个复数求和、两个
//复数求差、两个复数求积运算。

typedef struct complex
{
	int re;
	int im;
}complex;
void add(complex a, complex  b, complex *c)
{
	c->re = a.re + b.re;
	c->im = a.im + b.im;
}
void minus(complex a, complex  b, complex *c)
{
	c->re = a.re - b.re;
	c->im = a.im - b.im;
}
void multiply(complex a, complex b, complex *c)
{
	c->re = a.re * b.re - a.im * b.im;
	c->im = a.re * b.im + a.im * b.re;
}
int main()
{
	complex x, y, s, p,m;
	scanf_s("%d%d", &x.re, &x.im);
	scanf_s("%d%d", &y.re, &y.im);
	add(x, y, &s);
	printf("sum = %3d + %3di\n", s.re, s.im);
	minus(x, y, &p);
	printf("product = %3d + %3di\n", p.re, p.im);
	multiply(x, y, &m);
	printf("multiply = %3d + %3di\n", m.re, m.im);

	getchar();
	getchar();

	return 0;
}
