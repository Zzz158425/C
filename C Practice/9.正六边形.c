#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

/*
void liubianxing(int m);
void zhengliubianxing(int m);
int main(void)
{
	liubianxing(7);
	zhengliubianxing(7);

}

void liubianxing(int m)
{
	int n = 1, i = 0, j = 0;
	for (n = 1; n <= m; n++)
	{
		for (j = m - n; j > 0; j--)
			putchar(' ');
		for (i = 0; i < 2 * n + 1; i++)
			putchar('*');
		putchar('\n');
	}
	for (n = 1; n < m; n++)
	{
		for (j = 0; j < n; j++)
			putchar(' ');
		for (i = 0; i < 2 * (m - n) + 1; i++)
			putchar('*');
		putchar('\n');
	}
}
void zhengliubianxing(int m)
{
	int n, i, j; //n 行号, m 边长，2*m-1 是总行数，行数标号为：-2 -1 0 1 2
	int t = m; //定义中间变量使用 m，t 用来控制星号数量
	for (n = 1 - m; n < m; n++)
	{
		//输出空格
		for (i = 0; i < abs(n); i++)
			putchar(' ');
		//输出星号
		for (j = 0; j < t; j++)
			putchar('*');
		if (n < 0)
			t += 2;
		else
			t -= 2;
		putchar('\n');
	}
}
*/