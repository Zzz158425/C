#include <stdio.h> 
#include <stdlib.h>

/*
void chengfabiao(void);
void chengfabiaozuoxia1(void);
void chengfabiaozuoxia2(void);
void chengfabiaoyouxia1(void);
void chengfabiaoyouxia2(void);
void chengfabiaozuoshang1(void);
void chengfabiaozuoshang2(void);
void chengfabiaoyoushang1(void);
void chengfabiaoyoushang2(void);
int main()
{
	chengfabiao();
	chengfabiaozuoxia1();
	chengfabiaozuoxia2();
	chengfabiaoyouxia1();
	chengfabiaoyouxia2();
	chengfabiaozuoshang1();
	chengfabiaozuoshang2();
	chengfabiaoyoushang1();
	chengfabiaoyoushang2();

	system("pause");
	return 0;
}

void chengfabiao(void)
{
	int i, j;
	for ( i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
		{
			printf("%dx%d =%2d ", j, i, i * j);//%2d占两个宽度
		}
		putchar('\n');
	}
}

void chengfabiaozuoxia1(void)
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%dx%d=%2d ", j, i, i * j);
		}
		putchar('\n');
	}
}

void chengfabiaozuoxia2(void)
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= i; j++)
		{
			if(i >= j)
				printf("%dx%d=%2d ", j, i, i * j);
		}
		putchar('\n');
	}
}

void chengfabiaoyouxia1(void)
{
	int i, j, k, l;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9 - i; j++)
		{
			printf("       ");
		}
		for (k = i; k <= i; k++)
		{
			for (l = 1; l <= i; l++)
			{
				printf("%dx%d=%2d ", l, k, k * l);
			}
		}
		putchar('\n');
	}
}

void chengfabiaoyouxia2(void)
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 9; j > i; j--)
			printf("       ");
		for (j = 1; j <= 9; j++)
			if (i >= j)
				printf("%dx%d=%2d ", j, i, i * j);
		putchar('\n');
	}
}
void chengfabiaozuoshang1(void)
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = i; j <= 9; j++)
		{
			printf("%dx%d=%2d ", i, j, i * j);
		}
		putchar('\n');
	}
}

void chengfabiaozuoshang2(void)
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j <= 9; j++)
			if (i <= j)
				printf("%dx%d=%2d ", i, j, i * j);
		putchar('\n');
	}
}
void chengfabiaoyoushang1(void)
{
	int i, j, k, l;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j < i; j++)
		{
			printf("       ");
		}
		for (k = i; k <= i; k++)
		{
			for (l = i; l <= 9; l++)
			{
				printf("%dx%d=%2d ", k, l, k * l);
			}
		}
		putchar('\n');
	}
}

void chengfabiaoyoushang2(void)
{
	int i, j;
	for (i = 1; i <= 9; i++)
	{
		for (j = 1; j < i; j++)
			printf("       ");
		for (j = 1; j <= 9; j++)
			if (i <= j)
				printf("%dx%d=%2d ", i, j, i * j);
		putchar('\n');
	}
}
*/