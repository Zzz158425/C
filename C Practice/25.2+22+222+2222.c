#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

/*
void fun1();
void fun2();
int main()
{
	fun1();
	fun2();
	system("pause");
	return 0;
}
void fun1() 
{
	int i;
	int x = 5;//循环次数
	long long a = 0;
	long long sum = 0;
	for ( i = 0; i < x; i++)
	{
		a = a + (2 * (int)pow(10,i));
		sum = sum + a;
		if ((i + 1) != x)
		{
			printf("%lld + ", a);//形成 x - 1 个之前的表达式
		}
		else
		{
			printf("%lld ", a);//形成最后一个式子的表达式
		}
	}
	printf("= %lld \n",sum);
}
void fun2()
{
	//通项公式：n = ( n - 1 ) * 10 + 2
	int n = 0, i = 1, sum = 0;
	for (i = 1; i < 5; i++)
	{
		n = n * 10 + 2; //2 22 222 2222 22222
		sum += n; //累加
		printf("%d + ", n); //输出 2 + 22 + 222 +
	}
	n = n * 10 + 2; //再算一次
	sum = sum + n;
	printf("%d = %d\n", n, sum);//可以盖住一个+
}
*/