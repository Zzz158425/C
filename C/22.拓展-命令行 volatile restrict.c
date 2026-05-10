#include <stdio.h> 
#include <stdlib.h>
#include <malloc.h>

/*
//类型修饰符
struct Node 
{ 
	int a; double b;
};

//restrict
__declspec(restrict) void* fun(void);


int main(int argc, char* argv[])
{
//命令行参数介绍
	//命令行参数用来传递文件路径给软件，比如双击 stu.txt，系统就会自动用文本软件打开该文档    
	//本质就是系统通过文件后缀得知用什么软件打开，然后将文件的绝对路径传递给软件，软件内通过 fopen 打开了 stu.txt，这就是用到了命令行参数。
	//另外拖动文件到软件，或者选择打开方式，或者通过控制台指令，虽然操作不一样，但是本质一样。

//命令行参数主函数形式
	//int main(int argc, char* argv[], char* env[])
	//{
	//	return 0;
	//}
	//参数 1 是命令行参数的个数
	//参数 2 是字符串数组，装命令行参数的，本质就是字符串，也可写成 char** argv，因为数组做参数时，挨着变量名的方括号会被解释为指针
	//参数 3 是字符串数组，装所依赖的环境路径，不通用，有的编译器没有
	int i = 0;
	for ( i = 0; i < argc; i++)
	{
		puts(argv[i]);
	}
	getchar();
	//参数使用：
		//通过命令行 cmd 传递，比如：data.exe da1.txt da2.txt da3.txt
		//argc 为 4
		//argv[0]为 data.exe argv[1]为 da1.txt
		//argv[2]为 da2.txt
		//argv[3]为 da3.txt
	//调试参数传递：项目属性->调试->命令行参数

//类型修饰符
	//有三个：const(常量) volatile(易变) restrict(唯一)
	//volatile : 易变的，影响编译器优化
	//如果一个变量 a，在程序中使用的频率很高且变化频率不高，那么就会被优化存储入缓存，这样可以增加程序的执行效率，当声明成 volatile 变量，该变量就是易变的，表示在程序运行过程中会经常发生改变，所以就不能被优化存入缓存了
	volatile int a = 12; //a 是易变的
	volatile int b[5] = { 1,2,3,4,5 }; //每个元素都是易变的
	volatile struct Node c = { 12, 3.5 }; //每个成员都是易变的
	
//restrict
	//修饰指针变量，表示该变量是指向空间唯一、初始的，即该空间仅与此变量关联，一一对应
	//修饰变量：
		//C 语言里 : restrict(老), __restrict(C99)
		//C++里 : __restrict
	//修饰函数：
		//__declspec(restrict)
	int* __restrict d = (int*)malloc(20);//为了通用性，大家使用下划线版本，仅能修饰变量
	free(d);
	//它的作用是允许编译器对所修饰的变量进行优化
	int* __restrict p = (int*)malloc(20);//p 为 malloc所申请的空间的唯一操作方式
	p[0] = 5;
	//p[0] += 6;
	//p[0] += 3;由于 p 是该空间的唯一的访问方式，所以会优化成 p[0] += 9;
	p[0] += 9;
	free(p);

	system("pause");
	return 0;
}

//restrict
__declspec(restrict) void* fun(void)
{
	return 0;
}
*/