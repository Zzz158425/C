#include <stdio.h> 
#include <stdlib.h>
//2025.9.26

/*
void lingxing(int m);
int main(void)
{
	lingxing(7);
}

void lingxing(int m)
{
	int n = 1, i = 0, j = 0;
	for (n = 1; n <= m; n++)//输出 5 行星号,5 可变
	{
		for (j = m - n; j > 0; j--)//输出每行前的空格
			putchar(' ');
		for (i = 0; i < 2 * n - 1; i++)//输出每行的*
			putchar('*');
		putchar('\n');//输出完一行输出换行
	}
	for (n = 1; n < m; n++)//行数，<m 上半边输出 5 行，下边输出 4 行
	{
		for (j = 0; j < n; j++)//输出每行前的空格 1,2,3...
			putchar(' ');
		for (i = 0; i < 2 * (m - n) - 1; i++)//输出每行的*
			putchar('*');
		putchar('\n');//输出完一行输出换行
	}
}
*/