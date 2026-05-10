#include <stdio.h> 
#include <stdlib.h>

/*
void sushu1(void);
void sushu2(void);
int main()
{
	sushu1();
	sushu2();
	system("pause");
	return 0;
}

void sushu1(void)
{
	int i, j;
	int t = 0;
	int sum = 0;
	for ( i = 100; i <= 999; i++)
	{
		for ( j = 2; j <= 99; j++)
		{
			if (!(i % j))
				break;
			t++;
		}
		if (t >= 98)//2~99的数均不能整除
		{
			printf("%d ", i);
			sum = sum + i;
			t = 0;
		}
		t = 0;
	}
	printf("\nsum:%d\n", sum);
}
int prime(int n)
{
	int j;
	if (0 == n || 1 == n)
		return 0;//不是素数
	if (2 == n)
		return 1; //是素数 返回 n 也行
	for (j = 2; j <= n - 1; j++)
		if (n % j == 0) //非素数
			for (j = 2; j <= n - 1; j++)
				return 0;
	return 1;//经过循环之后，一定是素数
}
void sushu2(void)
{
	int n, j, sum = 0;
	for (n = 100; n <= 999; n++)//素数循环条件判断处：j < n / 2 即可
	{
		if (0 != prime(n)) //是素数
		{
			sum += n; //累加
			printf("%d ", n);
		}
	}
	printf("\n sum = %d\n", sum);
}
//int m = (int)sqrt(n);
//for (j = 2; j <= m; j++) //循环次数更少，效率更好
//数学分析
//比如49 7*7==49 如果还有两个数相乘得49，一定是其中一个比7小，其中一个比7大，所以只需在2 - 7之间找整除的数即可
*/