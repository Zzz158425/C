#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

/*
void shuzuhuiwen1(void);
void shuzuhuiwen2(void);
int main()
{
	
	//shuzuhuiwen1();错误
	shuzuhuiwen2();

	system("pause");
	return 0;
}

void shuzuhuiwen1(void)
{
	int a = 134431;
	int arr[20] = { 0 };
	int arr1[20] = { 0 };
	int i = 0;
	int j = 0;
	int t = 0;
	while (a != 0)//将 a 填充进 arr 里面
	{
		arr[i] = a % ((int)pow(10, 1));
		a = a / 10;
		i++;
		t = i - 1;
	}
	for (j = 0; j < i; j++)
	{
		arr1[j] = arr[t];
		t--;
	}
	if (arr1 == arr)//在C语言中，arr1 == arr 比较的是两个数组的地址，而不是数组的内容。
	{
		printf("是回文");
	}
	else
	{
		printf("不是回文");
	}
	printf("%d", arr1 == arr);
}

void shuzuhuiwen2(void)
{
	int a = 123321, aa = a; //aa 记录原值
	int arr[10] = { 0 }, in = 0;//in 是数组下标，arr10 元素就可以
	while (a)
	{
		arr[in] = a % 10; //取低位
		in++; //下标++
		a /= 10; //自除 10
	}
	//循环结束 in 指向最后一个元素的下一个位置
	in -= 1; //指向最后一个元素
	int i = 0; //首元素下标
	while (i < in)
	{
		if (arr[i] != arr[in]) //找到不相等
			break;
		i++; //一个从前往后走
		in--; //一个从后往前走
	}
	if (i >= in)
	{
		printf("%d 回文\n", aa);
	}
	else
	{
		printf("%d 不回文\n", aa);
	}
}
*/