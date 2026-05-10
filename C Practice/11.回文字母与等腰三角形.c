#include <stdio.h> 
#include <stdlib.h>

/*
void dengyaoABC1(int m);
void dengyaoABC2(int m);
int main(void)
{
	dengyaoABC1(5);
	dengyaoABC2(5);

	system("pause");
	return 0;
}


void dengyaoABC1(int m)
{
	int n = 1;
	int i = 0, j = 0;
	int t = 0;//同一行字母的位置
	char c = 'A';
	int d = 0;//每一行产生回文的位置
	for (n = 1; n <= m; n++)

	{
		for (j = m - n; j > 0; j--)
		{
			putchar(' ');
		}
		for (i = 0; i < 2 * n - 1; i++)
		{
			putchar(c);
			if (t < d)
			{
				c++;
				t++;
			}
			else
			{
				c--;
				t++;
			}
		}
		putchar('\n');
		c = 'A';
		t = 0;
		d++;
	}
}

void dengyaoABC2(int m)
{
	int n = 1, i, j;
	for (n = 1; n <= m; n++) //行遍历
	{
		for (i = 1; i <= m - n; i++)//输出空格
			putchar(' ');
		//输出字符
		char c = 64 + n;
		for (j = 1 - n; j < n; j++)
		{
			if (j < 0) putchar(c + j);
			else putchar(c - j);
		}
		putchar('\n'); //输出换行
	}
}
*/