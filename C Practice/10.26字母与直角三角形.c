#include <stdio.h> 
#include <stdlib.h>
//OK

/*
void zhijiao26ABC1(int m);
void zhijiao26ABC2(void);
int main(void)
{
	zhijiao26ABC1(6);
	zhijiao26ABC2();

	system("pause");
	return 0;
}

void zhijiao26ABC1(int m)
{
	int i, j;
	char k = 65;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j <= i; j++)
		{
			if (k < 91)
			{
				printf("%c", k);
				k++;
			}
			else
			{
				break;
			}
		}
		printf("\n");
	};
}

void zhijiao26ABC2(void)
{
	int n = 1; //行号
	int i = 0; //循环控制变量
	char c = 'A';
	while (c <= 'Z') //当 c>z 是结束
	{
		for (i = 0; i < n && c <= 'Z'; i++)//当 c>z 是结束，因为最后一次不一定满行
		{
			putchar(c); //输出字符
			c++; //输出完自加 1,输出一个自加 1
		}
		n++; //一次循环输出一行
		putchar('\n'); //输出换行
	}
}
*/