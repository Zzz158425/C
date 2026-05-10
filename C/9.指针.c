#include <stdio.h> 
#include <stdlib.h> 

/*
int main(void)
{
//指针的简介 2025.9.2
	//地址类型就叫指针类型，即指针类型定义的变量就是专门装地址的

//指针变量声明
	//short* char*叫指针类型，ps pc 叫指针变量，很多资料简称指针
	//*表示 ps pc 是指针变量，类型 int a[10]的[]，在定义变量时是指示作用
	//空格放在哪儿都行，short *ps， short * ps，short* ps 等等
	short* px;
	char* py;

//指针变量初始化
	//各种类型变量的地址的类型不同，a b 变量的地址类型就是变量对应的类型，所以装地址的指针变量的类型，是相应的类型
	//指针的赋值操作又叫指向，即 pa 指向变量 a 的地址
	//指针也有空间
	int a = 12;
	int* pa = &a;
	float b = 2.3f;
	float* pb = &b;

//NULL简介
	double* po = NULL; //NULL 就是 0，用来初始化指针

//指针的赋值
	//指针变量也是变量，可以装别的地址，但是要是同类型的，重新赋值也叫重新指向
	int c = 12, d = 22;
	int* pc = &c;
	pc = &d;
	pc = NULL;

//地址操作符
    //*+空间的地址 就是 该空间名字/*+变量的地址 就是 该变量本身
	//*&a == a 以 * &a 与 a 的用法完全一模一样
	printf("%d %d\n", *&c, c);
	*&c = 34;
	printf("%d %d\n", *&c, c);
	printf("%p %p\n", &*&c, &c);

//指针操作空间
	int e = 12;
	int* pe = &e; //p == &a，*&a == a 即*p == a
	printf("%d %d\n", *pe, e);
	*pe = 111;
	printf("%d %d\n", *pe, e);
	printf("%p %p\n", &*pe, &e);
//不同类型的指针指向
	//short*指针一次操作 2 字节空间，char*指针一次操作1 字节空间，int*指针一次操作 4 字节空间，float*指针一次操作 4 字节空间，double*指针一次操作 8 字节空间

//二级指针
	//pp 就是二级指针变量，用来装 1 级指针变量的地址。
	//int** 就是二级指针类型，int * 是一级指针类型。
	int f = 12; //a 变量有自己的空间，假设地址是 0x10，里边装 12
	int* pf = &f; //p 变量有自己的空间，假设地址是 0x20，里边装 0x10 pf = &f -> *pf = *&f = f
	int** ppf = &pf; //pp 也有自己的空间，假设地址是 0x30，里边装 0x20 ppf = &pf -> *ppf = *&pf = pf -> *(*ppf) = *(*&pf) = *pf = f
	printf("%d %d\n", **ppf, f);
	**ppf= 123;
	printf("%d %d\n", **ppf, f);
	printf("%p %p\n", &**ppf, &f);

//指针数组 2025.9.3
	int g[10]; //每个元素都是 int 类型数据
	int* pg[10]; //每个元素都是 int*类型的，即地址
	int h = 1, i = 2, j = 3, k = 4;
	int* ph[5] = { &h,&i,&j,&k };//c[1]就是&e *ph[1] == *&h == h
	printf("%d %d %d %d\n", *ph[0], *ph[1], *ph[2], *ph[3]);

//指针的偏移计算
	//指针可以进行加减运算，且只能进行加减法，名字叫指针偏移。
	//int* p1指针*p1 一次操作 4 字节空间，float* p2 指针* p2 一次操作 4 字节空间，double * p3 指针 * p3 一次操作 8 字节空间。
	//p1+1   1为 sizeof(int)        +4
	//p2 - 2 2为 sizeof(float) * 2  -8
	//p3 + 3 3为 sizeof(double) * 3 +24
	printf("%zu %zu\n", pf, pf + 1);

//指针操作一维数组
	//&k[0] + 1 == &k[1]
	//&k[0] + 2 == &k[2]
	//&l[4] - 1 == &k[3]
	//int* pk = &l[0];
	//那么: p + 0 == &a[0] 所以：a[0] == *&a[0] == *(p+0) == *p
	//     p + 1 == &a[1]       a[1] == *&a[1] == *(p + 1)
	//     p + 2 == &a[2]       a[2] == *&a[2] == *(p + 2)
	//     p + 3 == &a[3]       a[3] == *&a[3] == *(p + 3)
	//     p + 4 == &a[4]       a[4] == *&a[4] == *(p + 4)
	int l[5] = { 8,7,8,9,10 };
	int* pk = &l[0];//int* pk = l
	int m;
	for (m = 0; m < 5; m++)
		printf("%d \n", *(pk + m));//*pk++会改变指针的指向
	printf("%d %d\n", *ph[0], *ph[0] + 7);//*ph[0] + 7 先执行*ph[0]，为1，再 + 1 为8
	//注意：*(p+1)一定要加小括号，因为加法的优先级低于*，*(p + 1)先执行 p + 1 为 & a[1]，再取 * ，为 a[1]，为 7
	//     * p + 1 先执行 * p，为 8，再 + 1 为 9

//数组名是首元素的首地址
	//数组名是首元素的首地址：&a[0] == a
	int* pl = l;//int* pl = &l[0] 二者一模一样，平时都是用前者，因为写起来方便

//下标运算
	//*(pl + 4) == pl[4] == 4[pl]
	printf("%d %d %d\n", pl[4], *(pl + 4), 4[pl]);

//一维数组指针 
	int(*pm)[5] = &l;//&l 取l里面所有元素的地址
	printf("%u %u\n", pk, pm );
	printf("%u %u\n", pk + 1, pm + 1);//pk + 1是元素地址 + 1，pm + 1是整个数组地址 + 1

//一维数组指针的操作
	//pm = &l
	//*pm = *&l = l
	for (i = 0; i < 5; i++)
		printf("%d %d\n", l[i], (*pm)[i]);
	(*pm)[1] = 45;
	printf("%d %d\n", l[1], (*pm)[1]);
	printf("%p %p\n", &l[1], &(*pm)[1]);

//二维数组指针
	int n[2][3] = { {3,6,2},{1,9,7} };
	int (*pn)[2][3] = &n; //&n 是整个二维数组的地址
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d %d\n", n[i][j], (*pn)[i][j]);
		}
		putchar('\n');
	}

//一维指针遍历二维数组
	int(*pn1)[3] = &n[0];//也可写作int(*pn1)[3] = n pn1 == &n[0] -> *pn1 = n[0] 
	int(*pn2)[3] = &n[1];//*pn2 = n[1]
	printf("%d %d %d\n", (*pn1)[0], (*pn1)[1], (*pn1)[2]);
	printf("%d %d %d\n", pn1[0][0], pn1[0][1], pn1[0][2]);//下标运算
	printf("%d %d %d\n", (*(pn1 + 1))[0], (*(pn1 + 1))[1], (*(pn1 + 1))[2]);
	printf("%d %d %d\n", pn1[1][0], pn1[1][1], pn1[1][2]);//下标运算
	for (i = 0; i < 2; i++)//一维指针遍历二维
	{
		for (j = 0; j < 3; j++)
		{
			printf("%d %d\n", n[i][j], pn1[i][j]);
		}
		putchar('\n');
	}

//元素类型访问二维数组
	//n[0][0] == *(p + 0) == p[0]
	//n[0][1] == *(p + 1) == p[1]
	//n[0][2] == *(p + 2) == p[2]
	//n[1][0] == *(p + 3) == p[3]
	//n[1][1] == *(p + 4) == p[4]
	//n[1][2] == *(p + 5) == p[5]
	int* pnn = &n[0][0];
	for (i = 0; i < 6; i++)
		printf("%d %d \n", pnn[i], *(pnn + i));

//指针的大小
	//32 位编译环境下是 4 字节
	//64 位编译环境下是 8 字节
	printf("%zd\n", sizeof(int*));
	printf("%zd\n", sizeof(short**));
	printf("%zd\n", sizeof(long****));
	printf("%zd\n", sizeof(int(*)[2]));
	printf("%zd\n", sizeof(double(*)[2][6]));

//通用类型指针
	//通用类型就是指没有具体类型，什么指针都能装
	//可装不可用，只能作为中转站
	void* p = &b;
	p = &a;
	int* pp = p;//中转站
	*pp = 111;
	printf("%d\n", *pp);
	void* ppp = &a;
	*(int*)ppp = 34;//强制类型转换
	pp = ppp;
	printf("%d\n", *pp);

	system("pause");
	return 0;
}
*/