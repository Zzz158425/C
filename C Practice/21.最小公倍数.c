#include <stdio.h> 
#include <stdlib.h>

/*
void gongbeishu1(void);
void gongbeishu2(void);
int main()
{
	gongbeishu1();
	gongbeishu2();


	system("pause");
	return 0;
}

void gongbeishu1(void)
{
	int a = 12;
	int b = 20;
	int i, j;
	int m = a > b ? a : b;//取大的那个数
	int n = a < b ? a : b;//取小的那个数
	int flag = 0;
	for (i = 1; i <= n; i++)//逐次比较，直到出现 m * i = n * j 的时候出现，即为其最小公倍数
	{
			for (j = 1; j <= m; j++)
			{
				if (m * i == n * j)
				{
					flag = 1;
					break;
				}
			}
			if (1 == flag)
				break;
	}
	printf("最大公倍数：%d \n", m * i);
}
void gongbeishu2(void)
{
	int n1 = 12, n2 = 20;
	int maxn = n1 > n2 ? n1 : n2; //公倍数从大的那个数开始找，如：20 40 60 80
	int n = maxn;
	while (1) //不知道找多少次，所以死循环
	{
		if (n % n1 == 0 && n % n2 == 0) //用大的，先是大的倍数
			break;
		n += maxn;//n = n + maxn
	}
	printf("最大：%d", n);
}
*/