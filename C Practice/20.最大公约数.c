#include <stdio.h> 
#include <stdlib.h>

/*
void gongyueshu1(void);
void gongyueshu2(void);
void gongyueshu3(void);
int main()
{
	gongyueshu1();
	gongyueshu2();
	gongyueshu3();

	system("pause");
	return 0;
}

void gongyueshu1(void)
{
	int a = 135;
	int b = 180;
	int i, j;
	int m = 0;
	for (i = 1; i <= a; i++)//从小到大，找出 a 的因子，然后与 b 的所有因子逐一进行比较
	{
		if (0 == a % i)
		{
			for (j = 1; j <= b; j++)
			{
				if (0 == b % j)
				{
					if (i == j)
					{
						m = i;
						printf("%d ", m);
					}
				}
			}
		}
	}
	printf("\n最大公约数：%d \n", m);
}


void gongyueshu2(void)
{
	int n1 = 12, n2 = 20;
	int n = n1 > n2 ? n2 : n1; //公因数范围是1~小的那一个数，n1 > n2 为真，即 n = n2，反之
	int j, maxg = 0;
	for (j = 1; j <= n; j++)//<= 两个数中小的那个
	{
		if (0 == n1 % j && 0 == n2 % j) //公因子,
		{
			if (j > maxg) //找最大值
				maxg = j;
			//printf("%d ", j);//输出所有公因子
		}
	}
	printf("最大：%d\n", maxg);
}

void gongyueshu3(void)//从最大到小找，不一定最快
{
	int n1 = 12, n2 = 20;
	int n = n1 > n2 ? n2 : n1;
	int j;
	for (j = n; j >= 1; j--)
		if (n1 % j == 0 && n2 % j == 0)
			break;
	printf("最大：%d\n", j);
}
*/