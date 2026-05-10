#include <stdio.h> 
#include <stdlib.h>
#include <stdarg.h>
#include <malloc.h>

/*
//赋值转换
void fun(int a, double b);
int fun1(void);
//函数参数提升转换
void fun2(int c, ...);

//指针的隐式转换
void fun3(void);

int main()
{
//赋值转换
	//类型转换：将一个数据转换成另外一种类型使用，不改变原数据
		//隐式类型转换：C 语言编译器帮我们做的默默转换
			//1、初始化：赋值左侧为目标类型
	int a = 12.6; //将 double 的 12.3 转成 int 的 12，然后赋值给 a
	short b[3] = { 3.4f, 4.5 }; //同上
			//2、赋值：转换为左操作数的类型
	a = 5.6f; //将 float 的 5.6f 转成 int 的 5，然后赋值给 a
	b[2] = 5.6; //同上
			//3、函数实参会被转换成形参类型
	fun(3.4, 5); //将 double 的 3.4 转成 int 的 5，然后赋值给 a，将 int 的 5 转成 double 的 5.0，然后赋值给 b
			//4、函数 return 值会被转成返回值类型
	double c = fun1(); //将 int 的 12 转成 double 的 12.0 赋值给 a
	printf("%f\n", c);

//函数参数提升转换
	//有无符号的 char、short 提升转换成 int 类型，vs编译器 提升，dev编译器 不提升
	//可变参数头文件 <stdarg.h>
	//在 short 与 int 同大小的情况下（51单片机 short int 都是 2 字节），unsigned short 提升为 unsigned int
	//float 提升为 double，vs编译器，dev编译器均不提升。书上说 k & r c。
	char d = 'c';
	short e = 4;
	fun2(2, d, e);

//表达式类型提升 2025.10.9
	//因为字节对齐，出现在表达式里的有无符号的 char, short，会被提升为 int。在 short 与 int 同大小的情况下，unsigned short 提升为 unsigned int
	char f = 'a';
	short g = 12;
	printf("%zd\n", sizeof(f + g)); //输出 4 字节
	printf("%p\n", f + g); //格式字符串中的" %p "与" int " 类型的参数 1 冲突
	//在包含两种不同的数据类型的计算中，会被提升为级别高的类型
	//在 long 大于 int 大小时，long > unsigned int 比如 64 位 gcc 下
		//long double > double > float > unsigned long long > long long > unsigned long > long > unsigned int > int
	//在 long 与 int 同大小时，unsigned int > long 比如 vs 下
		//long double > double > float > unsigned long long > long long > unsigned long > unsigned int > long > int
	//计算过程的提升是按照子表达式，运算一步转换一步，不是统一先转换
		//1.2f + 7 / 2 - 2.1
		//先执行 7/2 == 3
		//然后执行 1.2f+3，此时 3 提升为 float 3.0f，再加，得到 4.2f
		//然后执行 4.2f - 2.1，此时 4.2f 提升为 double4.2,再减，得到 2.1
	double h = 1.2f + 7 / 2 - 2.1;
	printf("%f\n", h);
	//在表达式计算中，类型是提升的，类型提升不会出现计算不精确的问题。在赋值表达式中，会出现类型降级，降级会出现一定的问题，比如降低精确度

//指针的隐式转换
	//数组地址到指针的转换
	int i[10];
	int(*j)[10] = &i; //标准写法
	int* j1 = &i; //&a 与 &a[0] 共首地址，将数组的地址转换为元素的地址 &a 转成了 int*
	//函数名字的转换：函数名就是函数地址
		//使用函数名 fun 时，自动转成 & fun
	void (*pp)(void) = &fun3;
	//void* 的转换：
	int k;
	void* m = &k; //&a 是 int*，转换 void*,再赋值给 p，void*可以直接装任意
	float* m1 = m; //p 转成 float*，再赋值给 p1，void*可以赋值给任意
	int* m2 = malloc(4); //malloc 的返回值是 void*,可以直接这么写
	int* m3 = (int*)malloc(4); //有的编译器不支持上述，所以写成如此，强制类型转换，推荐这样写
	free(m2);
	free(m3);

//强制类型转换
	//显式类型转换(强制类型转换)：书上有叫 指派 cast，形式：(类型)数据
	//基本数据类型
	int n = 3.4; //隐式类型转换
	int o = (int)3.4; //强制类型转换，可以理解为运算符，不改变强转值的大小与类型，二者都可，平时用上面即可

//指针的强制转换
	//指针类型，大指针不要操作小空间，比如：
	int p = 3; //4 字节
	long long* q = &p; //大指针指向小空间
	//*q = 45; *p 操作 8 字节，a 只有 4 字节，越界了，异常
	//小指针可以操作大空间，比如：
	long long r = 4; //8 字节
	int* s = &r; //小指针指向大空间
	printf("%llx\n", r);
	*s = 4; //操作前 4 字节,p[0]
	*(s + 1) = 5; //操作后四字节,p[1],相当于把 8 字节当 2 元素数组了
	printf("%llx\n", r); //输出看赋值效果

//a[2]与2[a]
	//下标运算的过程：
		//1、a + 2 得到偏移后的地址，即要求两个操作数，一个是地址，一个是偏移量
		//2、a[2]就是该地址起始的空间的名字
	//其过程与* (a + 2)一样：
		//1、a + 2 得到偏移后的地址，
		//2、对该地址取 * 操作，就是该空间的名字。
	//a[2] == 2[a] == *(a + 2) == *(2 + a)
	//区别：前者是 1 个运算符构成的表达式，后者是 3 个运算符构成的表达式，可以转汇编查看

	system("pause");
	return 0;
}

//赋值转换
void fun(int a, double b)
{
	printf("%d %f\n", a, b);
}
int fun1(void)
{
	return 12.6;//将 double 的 12.6 转成 int 的 12
}

//函数参数提升转换
void fun2(int c, ...)//int c 表示参数传递个数
{
	va_list ap;//数组变量
	va_start(ap, c);//va_start 拷贝参数 c 装入 ap 中
	size_t a = sizeof(va_arg(ap, char));//取出第 1 个可变参数后，自动指向第 2 个参数
	printf("%zd ", a); //4 字节
	a = sizeof(va_arg(ap, short));
	printf("%zd \n", a); //4 字节
	va_end(ap);//释放 
}

//指针的隐式转换
void fun3(void)
{
	printf("---\n");
}
*/