#include <stdio.h> 
#include <stdlib.h>

/*
//复杂指针
int fun(int a);
char* fun1(char* p);
char* fun2(char* p);
char* fun3(char* p);
//复杂指针的理解 2025.10.10
int fun4(float a);
int (*fun5(int a))(float a);
int* (*fun6(int a))[3];
int fun7(int* p);
int fun8(int* p);
int fun9(int* p);
int (*(*fun10(int* p))[3])(int* a);

int main()
{
//复杂指针 
	//复杂指针：按照运算符的优先级与结合性，一步一步分析
	//int (*pf)(int)
		//第一步：(*pf) 先跟* 结合，所以 pf 是一个指针
		//第二步：int(int) 该指针的类型为该类型函数的地址
		//第三步：这个函数的类型是：返回值是 int 有一个 int 参数
	int (*pf)(int) = &fun; //如果分析有误，放编译器里就警告了
	//char* (*pf[3])(char* p)
		//第一步：pf[3]先跟方括号结合，所以 pf 是一个 3 个元素数组
		//第二步：(*) 该数组元素都是是指针类型
		//第三步：char * (char* p) 元素指针是指向该类型函数的地址
		//第四步：该函数类型是：返回值为 char* 参数为 char*
	char* (*pff[3])(char* p) = { fun1, fun2, fun3 };//如果分析有误，放编译器里就警告了
//复杂指针的理解 2025.10.10
	//int (*(*pf)(int))(float)
		//第一步：(*pf)先跟* 结合，所以 pf 是一个指针
		//第二步：(*(int)) 该指针指向该类型的函数
		//第三步：该函数参数是一个 int，返回值是一个指针* 
		//第四步：int(float) 表示第三步返回值指针指向该类型的函数
		//第五步：该函数返回值是 int, 参数是一个 float
	int (*(*pfff)(int))(float) = &fun5;
	//int* (*pf(int))[3]
		//第一步：pf(int) 先跟小括号结合，所以 pf 是一个函数
		//第二步：函数参数有一个 int 参数，返回值是一个指针* 
		//第三步：int* [3] 该返回值指针指向 3 元素的指针数组的地址
	//int (*(*(*pf)(int*))[3])(int*)
		//第一步：(*pf)先跟* 结合，pf 是一个指针
		//第二步：(*(int*))该指针指向函数类型
		//第三步：该函数参数时一个 int* ，返回值是一个指针* 
		//第四步：(*[3])该返回值指针指向 3 个元素的指针数组
		//第五步：int(int*)指针数组每个元素该函数类型指针
		//第六步：该函数一个 int* 参数，返回值为 int 类型
	int (*(*(*pfffff)(int*))[3])(int*) = &fun10;

//内存分区总结
	//分区大概分 5 个区，有的资料分 6 个
	//栈区：局部变量
		//生命周期：所在大括号
		//作用域：所在大括号
		//空间特点：定义变量时系统申请空间，声明周期结束时系统检测释放
		//大小：默认 1M，定义变量太大会出现爆栈
		//修改大小：项目属性->连接器->系统->堆栈保留大小 改大，单位字节
	//堆区：malloc calloc 的空间，定义变量太大可用
		//生命周期：从 malloc 到 free，当程序结束时，我们忘记 free 了，系统会自动回收空间
		//作用域：整个工程，只需地址传递
		//空间特点：malloc 申请，我们自己 free 释放，无需系统额外的资源帮助我们管理释放
		//大小：默认很大，理论上可用的物理内存
		//修改大小：项目属性->连接器->系统->堆保留大小 改大，单位字节
	//静态存储区：全局变量，静态变量
		//生命周期：与程序共存亡，当程序结束时，释放。由于程序运行期间一直占用空间，所以不建议使用大空间的全局变量
		//作用域：整个工程
		//空间特点：自动初始化 0，系统申请，系统释放，无需像栈区一直检测
		//大小：默认很大，理论上可用的物理内存
	//代码区：存储每一行代码，函数调用就是跳到这里来执行代码
	//字符常量区：常量字符串，随叫随有。

	system("pause");
	return 0;
}

//复杂指针
int fun(int a)
{
	return 0;
}
char* fun1(char* p) 
{ 
	return NULL; 
}
char* fun2(char* p) 
{ 
	return NULL; 
}
char* fun3(char* p) 
{ 
	return NULL; 
}

//复杂指针的理解 2025.10.10
int fun4(float a)
{
	return 0;
}
int (*fun5(int a))(float a)
{
	return &fun4;
}
int* (*fun6(int a))[3]
{
	int* c[3];
	return &c;
}
int fun7(int* p) 
{ 
	return 0; 
}
int fun8(int* p)
{
	return 0;
}
int fun9(int* p)
{
	return 0;
}
int (*ppp[3])(int*) = { fun7, fun8 ,fun9 };
int (*(*fun10(int* p))[3])(int* a) 
{
	return &ppp; 
}
*/
