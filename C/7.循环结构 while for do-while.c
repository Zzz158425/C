#include <stdio.h> 
#include <stdlib.h>

/*
int main(void)
{
//while 循环 2025.8.31
	//
	int i = 1;
	while (i <= 5)
	{
		printf("%d ", i);//也可以printf("%d ", i++);
		i++;
	}

//循环三要素
	//循环控制变量有初始值，即 i = 1，初始值不一定是 1，根据需要来
	//循环控制变量参与条件，即 i<=5
	//循环控制变量规律变化，比如 i++,i+=3,i--等等，按照规律变化，乱变不行

//for 循环
	//for(1;2;3) for(初始值;循环条件;变化) 
	for (i = 1; i <= 5; i++)
	{
		printf("%d ", i);
	}

//for循环的灵活性
	//部分1：可以多个变量，可以什么都不写，可以定义变量
	//部分2：可以不写，为恒为真。最好只写条件
	//部分3：可以不写，把条件变化写在 for 循环内部，也可写多个，用逗号隔开
	for (i = 1, printf("hello");i <= 5; i++) //用逗号分开
	{
		printf("%d ", i);
	}

//do while 循环
	//while for为入口条件循环
	//do while为出口条件循环，该循环最少执行一次
	i = 1;
	do
	{
		printf("%d ", i);
		i++;
	} while (i <= 5);

//break
	//在谁的结构中就跳出谁
	i = 1;
	while (i <= 5)
	{
		if (3 == i) //i==3 时中断跳出循环
			break;
		printf("%d ", i);
		i++;
	}

//continue
	//结束本次循环，跳到循环头，进行下一轮循环
	i = 1;
	for (i = 1; i <= 5; i++)
	{
		if (i == 2 || i == 5)// 当 i = 2 or 5 时 if为真，跳到循环头
			continue;
		printf("%d ", i);
	}

//循环嵌套
	int j;
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 2; j++) //j = 1 的作用
		{
			printf("i=%d,j=%d\n", i, j);
		}
	}
	j = 1;//与上述区别，逐行分析
	for (i = 1; i <= 3; i++)
	{
		for (; j <= 2; j++) //当j第一次为3跳出后 在进入嵌套for时，没有对j进行初始化，使其直接跳出嵌套for
		{
			printf("i=%d,j=%d\n", i, j);
		}
	}

//跳出多层循环
	int flag = 0;
	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= 5; j++)
		{
			if (i + j == 5)
			{
				flag = 1;
				break;//跳出嵌套for循环
			}
			printf("i=%d,j=%d\n", i, j);
		}
		if (1 == flag)
			break;//接力跳 跳出外层for循环
	}
	flag = 0;//goto 一次跳出多层循环
	for (i = 1; i <= 3; i++)
	{
		for (j = 1; j <= 2; j++)
		{
			printf("i=%d,j=%d\n", i, j);
			if (j == 2)
			{
				goto loop;  //直接跳loop
			}
		}
	}
loop:

	system("pause");
	return 0;
}
*/