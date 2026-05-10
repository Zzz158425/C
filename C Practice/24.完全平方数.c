#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

/*
void wanquanpingfang1();
void wanquanpingfang2();
int main()
{
	wanquanpingfang1();
	wanquanpingfang2();
	system("pause");
	return 0;
}

void wanquanpingfang1()
{
	int s;
	int t100 = 0;
	int t268 = 0;
	for ( s = 0; s <= 10000; s++)//0 ~ 1000 以内的完全平方数
	{
		t100 = (int)sqrt(s + 100);
		t268 = (int)sqrt(s + 268);
		if ((t100 * t100 == s + 100) && (t268 * t268 == s + 268))
		{
			printf("%d 是完全平方数\n", s);
			t100 = 0;
			t268 = 0;
		}
	}
}
int IsSqrt(int n)
{
	int x = (int)sqrt(n);
	if (x * x == n)
		return 1; //是完全平方数
	return 0; //非完全平方数
}
void wanquanpingfang2()
{
	int n = 0;
	for (n = 0; n < 10000; n++)
	{
		if (1 == IsSqrt(n + 100) && 1 == IsSqrt(n + 268))
		{
			printf("%d 是完全平方数\n", n);
		}
	}
}
//优化遍历范围
	//边界推断：
	//x* x == n + 100，y * y == n + 268
	//由于 n + 100 与 n + 268 差值是 168，所以 y * y - x * x == 168 差值最大 168
	//假设 y = 168 x = 167 两个相邻的差值最小，最小的要小于等于 168，就是我们遍历的边界点，y x 中间隔得越多，差值越大
	//28224 - 27889 == 335 > 168 所以边界 28224 不行 168 * 168 太大了，100 * 100 - 99 * 99 == 199 > 168
	//85 * 85 - 84 * 84 == 169 所以 85 * 85 可以作为边界 7225 所以 n < 7225
*/