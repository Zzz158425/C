#include <stdio.h> 
#include <stdlib.h> 

/*
//多文件介绍
	void fun16(void);
#include "位运算 多文件 宏 存储类-多文件1.h"

//防止头文件重复包含 2025.9.22
#include "位运算 多文件 宏 存储类-防止头文件重复包含.h"

//宏
#define N 12
#define M printf

//宏不计算
#define L 3 + 2

//参数宏
#define O(x,y)   x+y
#define P(x,y)   (x+y)
#define Q(x,y)   O(x,y)*P(x,y)

//typedef
	//类型重命名，给类型名起个新的名字，增加代码可读性
	typedef int myint; //myint a = 34;
	typedef int yourint;//yourint b = 11;
	typedef int* pint; //pint p = &a;
	typedef int** ppint; //ppint pp = &p;
	typedef int arr[5]; //arr b = {1,2,3,4,5};
	typedef int(*parr)[5]; //parr pa = &a;
	typedef int(*pfun)(int, double); //pfun pf = fun;
	typedef struct Node node; //node a = {"小明", 56.5};
	typedef struct Node1* pnode; //pnode pn = &a;
	typedef struct Node2
	{
		char str[20];
		double b;
	}no; //no a = {"小明", 56.5};
	typedef struct //无名
	{
		char str[20];
		double b;
	}NODE; //NODE b = {"小明", 56.5};

//全局变量extern
	int aa;//全局变量，在整个工程文件有效，生命周期与程序共存亡
	extern int aaaa;//声明定义在其他文件中的全局变量，与函数声明void fun17(void)一样

//static
	//静态全局变量，只在该源文件使用，作用域是所在文件
	static int bb = 56;//只能在“位运算 多文件 宏 存储类.c”中使用，生命周期与程序共存亡，无初始化默认为 0
	//静态局部变量
	void fun26(void);
	static void fun27(void);

int main(void)
{
//进制转换 2025.9.21	
	//程序员计算器
	//10 进制转其他进制，翻转取余法
	//其他进制转 10 进制，基数相加法

//位运算
	//使用其二进制位进行计算 只能用于整型
	//位运算符： 复合赋值运算符： 
	//&         按位与 a &= 2 a = a & 2
	//|         按位或 a |= 2 a = a | 2 ~按位取反
	//^         按位亦或 a ^= 2 a = a ^ 2
	//<<        位左移 a <<= 2 a = a << 2
	//>>        位右移 a >>= 2 a = a >> 2
	unsigned char a = 12, b = 3;
	unsigned char c = a & b;
	unsigned char d = a | b;
	unsigned char e = ~a;
	unsigned char f = ~b;
	unsigned char g = a ^ b;
	printf("%hhd %hhd %hhu %hhu %hhu\n", c, d, e, f, g);

//位左移
	//所有位向左平移，左侧截断，右侧补 0
	unsigned char h = a << 3;//a << n == a * 2^n
	printf("%hhu\n", h);

//位右移
	//所有位向右平移，右侧截断，负数左侧补 1，正数左侧补 0
	unsigned char i = a >> 1;
	printf("%hhu\n", i);

//多文件介绍
	//函数的作用：将一大堆代码按照功能封装成多个函数，方便维护管理
	//文件的作用：将一大堆函数按照功能分别写在多个文件中，方便维护管理多文件的本质跟单文件是一样的，比如想要使用使用一个函数，不管在不在同一个文件中，都需要声明，声明一下就能使用别的文件里内容了。
	//如果要使用的函数比较多，那么每个使用的文件内的最前都要写上相同的声明，写很多次，非常不方便，所以就出来了头文件，头文件内写着所有需要的声明，那个文件需要，就直接包含该头文件即可
	fun16();
	fun17();
	fun18();
	fun19();
	fun20();
	fun21();
	fun22();
	fun23();
	fun24();

//尖括号与双引号的区别
	//标准库头文件使用尖括号，自定义头文件使用双引号
	//查找起始路径不一样：工程所在相对路径：vcxproj，包含默认查找路径：项目属性->vc++目录->包含目录
	//双引号先在工程文件所在路径查找，然后在包含的默认路径依次查找，直到找到它
	//尖括号直接在包含的默认路径(文件属性 -> VC++目录 -> 包含目录)依次查找，直到找到它，
	//直接写头文件的绝对路径是编译效率最高的 #include "多文件2.h" == #include "D:\\Visual Studio2022SharedProject\\C language\\C language\\多文件2.h"

//防止头文件重复包含 2025.9.22
	//包含头文件就是将头文件里面的内容替换到头文件处，若两个头文件都包含同一个结构体，就会出现重定义
	//在每个头文件里面放入 #pragma once 即可解决
	fun25();
	//条件编译
		//#ifndef _AH
		//#define _AH
		//内容：各种声明
		//#endif

//宏
	//#define
	//常量宏：宏是单纯的替换
	printf("%d\n", N * 3);
	M("%d\n", N * 10);

//宏不计算
	printf("%d\n", L * 3);

//参数宏
	printf("%d %d %d\n", O(2, 3) * 3, P(2, 3) * 3, Q(2, 3) * 3);

//typedef
	myint q = 1;
	pint p = &q;
	arr u = { 2,3 };
	parr pp = &u;
	no t = { "小明", 56.5 };

//全局变量extern
	//不能在头文件定义变量
	//全局变量默认为零
	//谨慎在全局变量定义大空间，因为会一直占用次空间
	int aaa = 1;//局部变量，只在main函数里面有效
	printf("%d\n", aaaa);
	int aaaa = 1111;//若局部变量与全局变量重名，局部变量会屏蔽全局变量
	printf("%d\n", aaaa);

//static
	fun26();

//auto局部变量
	//auto 关键字，局部变量前默认有 auto 关键字，可省略，auto 是自动的意思，局部变量也叫自动变量，自动就是空间自动申请自动释放

//register
	//寄存器变量：寄存器不是物理内存，它是集成在 cpu 上的一块存储区域，所以不能取地址
	//register int a = 23;

//const
	//常量修饰符
	const int j = 23;//j不能赋值，只能读与取地址
	const int* k = &j;//*k不能赋值，即不能对所指向的地址赋值，可以修改指向其他地址
	int* const m = &j;//*m能赋值，即能对所指向的地址赋值，不可以修改其指向的地址
	const int* const r = &j;//*r不能赋值，即不能对所指向的地址赋值，不可以修改其指向的地址
	system("pause");
	return 0;
}

//static
	//静态局部变量
		//默认初始化为 0
		//相当于全局静态变量，其作用域仅是所在大括号
void fun26(void)
{
	static int cc = 1;//只能在fun26里面使用
	cc++;
	printf("%d\n", cc);
}
	//静态函数变量，同理，只在该源文件使用
static void fun27(void)
{
	static int a = 2;
	a++;
	printf("%d ", a);
}
*/

