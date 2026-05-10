#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

/*
void wanquanshu1(void);
void wanquanshu2(void);
int main()
{
	wanquanshu1();
	wanquanshu2();


	system("pause");
	return 0;
}

void wanquanshu1(void)
{
	int i, j;
	int m = 0;
	int t = 0;
	for ( i = 2; i <= 1000; i++)//循环 2~ 100 的数
	{
		t = 0;
		for (j = 1; j <= i - 1; j++)//因子的范围
		{
			if (i % j == 0)//判断是否是因子
			{
				t = t + j;
			}
		}
		if (t == i)//判断所有因子的和是否等于该数
		{
			printf("%d ", i);
			t = 0;
		}
	}
}
void wanquanshu2(void)
{
	int n = 2;
	//循环2~1000
	while (n <= 1000)
	{
		//累加真因子
		int sum = 0, j = 1;
		int nn = sqrt(n);
		for (j = 2; j <= nn; j++)
			if (n % j == 0)
			{
				sum += j;
				if (j != n / j)//当两个因数一样时，不再加，如 16 = 4 * 4
					sum += n / j;
			}
		sum += 1;//不包含 1，需加上
		if (sum == n)//判断完数
			printf("%d 是完数\n", n);
		n++;
	}
}
*/