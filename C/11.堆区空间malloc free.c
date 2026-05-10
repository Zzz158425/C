#include <stdio.h>
#include <stdlib.h> 
#include <malloc.h> 

/*
int main(void)
{
//堆	区空间简单介绍 2025.9.6
	//malloc 申请空间 理论上物理内存多大，他就能申请多大，当然并不能，毕竟系统运行其他软件都要使用空间。
	//兄弟函数：calloc realloc 
	//free 释放空间，申请的空间必须我们自己手动释放

//malloc函数的使用
	//头文件：malloc.h 一定要加上，老版本可以不加，新版本更加规范了
	//malloc(sizeof(int) * 10) == int a[10]
	int* p1 =(int*)malloc(sizeof(int) * 10);//返回地址为 void* 类型，需要强制转成 int 类型
	if (NULL == p1)//判断申请空间是否失败，申请失败直接中断
		return 0;
	*p1 = 45;

	//空间使用
	p1[0] = 12;
	p1[1] = 22;
	int(*p2)[10] = (int(*)[10])malloc(sizeof(int) * 10);
	if (NULL == p2)//判断申请空间是否失败，申请失败直接中断
		return 0;
	(*p2)[0] = 11;
	(*p2)[1] = 33;

//free释放空间
	//不能重复释放，不能释放非malloc的空间
	free(p1);//直接放首地址即可
	p1 = NULL;//释放完后清零，规范，若未释放又申请其他空间，会造成原来申请的空间的遗失，造成内存泄漏


//_msize函数
	//得到用malloc申请的空间大小
	size_t t = _msize(p2);//size_t 专属格式说明符%zd %zu，也可用%d %lld
	printf("%zu", t);
	p2 = NULL;
	free(p2);
//realloc与calloc
	//calloc作用跟 malloc 一样，参数拆开了
	int* p3 = (int*)malloc(sizeof(int) * 10);
	int* p4 = (int*)calloc(sizeof(int), 10); //乘积是总字节数 40
	free(p3);
	p3 = NULL;
	free(p4);
	p4 = NULL;
	//realloc重新申请更大/小的空间
	//过程：
	//1、申请更大的 80 字节，将首地址返回，装进 p6
	//2、将原空间的数据，依次复制进新空间
	//3、将原 p5 指向的 40 字节释放, p6装着新空间的
	int* p5 = (int*)malloc(sizeof(int) * 10);
	int* p6 = (int*)realloc(p5, sizeof(int) * 20); //申请更大的 80 字节
	free(p6);

	system("pause");
	return 0;
}
*/