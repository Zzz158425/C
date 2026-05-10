#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

/*
void yinshu1(void);
void yinshu2(void);
int main()
{
	yinshu1();
	yinshu2();

	system("pause");
	return 0;
}

int prime(int n)
{
	int j, m;
	m = (int)sqrt(n);
	if (0 == n || 1 == n)
		return 0;
	if (2 == n)
		return 1;
	for (j = 2; j <= m; j++)
		if (n % j == 0)
			return 0;
	return 1;
}
void yinshu1(void)//与找素数类似
{
	int n, s;
	scanf_s("%d", &s); 
	for ( n = 2; n <= s; n++)
	{
		if (0 ==s % n)
		{
			if (0 != prime(n))
			{
				printf("%d ", n);
			}
		}
	}

}

void yinshu2(void)
{
	int n = 120, j;
	int m = (int)sqrt(n);
	for (j = 1; j <= m; j++)//用开平方将数分为左右各一组，知道左边小的因子，直接用 n / j 就可以知道所对应的大的因子，无需对所有数进行遍历
	{
		if (n % j == 0)
		{
			if (prime(j))//左组
				printf("%d ", j);
			if (j != n / j && prime(n / j))//右组
				printf("%d ", n / j);
		}
	}
}
*/