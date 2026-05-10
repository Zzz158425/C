#include <stdio.h> 
#include <stdlib.h> 
/*
//函数功能简介 2025.9.3
	//C 语言模块编程的核心语法：将代码按照功能划分成一段一段独立的代码，有利于代码的管理，调试，维护

//无参无返函数定义
	//第一个 void：函数返回值，void 表示无返回值
	//fun：函数名字，合法的 C 语言标识符即可
	//()：叫参数列表，传递参数的，无参数就写个 void
	void fun(void) //函数头,无分号
	{
		//函数体：函数封装的内容。
		printf("hello\n");
	}
//函数声明 2025.9.4
	void fun(void);//全局位置，声明一次即可
	//当定义的函数放在 main 函数下面时，需在 main 函数前面加上函数声明
	//放在调用前的全局位置，全局就是最外层，跟主函数同逻辑层
	//也可放在局部位置，即 main 函数里面，调用函数前面

//函数返回值
	//可用可不用，虽然写了返回值，但是可以不用它。直接调用：fun1();
	int fun1(void);//函数声明
	int fun1(void) //函数定义
	{
		printf("hello C3~\n");
		return 12; //返回值 12，跟返回值 int 匹配
	}

//return 的作用
	//在有返回值的函数： 结束函数，返回一个值，回到调用处
	//在没有返回值的函数：结束函数，回到调用处
	int fun2(void);//函数声明
	int fun2(void) //函数定义
	{
		printf("C/C++\n");
		return ;//结束函数
		printf("hello C3~\n");
		return 12;//结束函数，返回值 12，跟返回值 int 匹配
	}

//不是所有的路径都有返回值
	int fun3(int n);//函数声明
	int fun3(int n) //函数定义
	{
		if (n == 3)
		{
			printf("------\n");
			return 1;//当if为假的时候将不执行if里面的代码，造成无返回值
		}
	}

//谨慎返回局部变量的地址
	int* fun4(void);//函数声明
	int* fun4(void)
	{
	
		//int b = 12;此处定义的b只能在函数 fun4 里面使用，与 main 里面的b无关
		//return &b; 局部变量b，执行完毕之后会被释放
	
	}

//函数参数 2025.9.5
	//函数参数是函数内外链接的接口，可以互通数据，内传外，外传内
	//调用时传递实参，可以常量，可以变量，可以是任何表达式
	//形参是函数的局部变量，只能在函数内使用
	//传递参数的本质是实参给形参初始化
	int Sum(int a, int b);
	int Sum(int, int);//声明二选一，声明的参数，叫形式参数，简称形参，声明可以不写变量名
	int Sum(int a, int b)//形式参数，简称形参
	{
		return a + b; //求和并返回
	}

//传递一维数组
	void fun5(int* p, int len);
	void fun6(int(*p)[5], int len);
	void fun6(int(*p)[5], int len)
	{
		int i = 0;
		for (i = 0; i < len; i++)
			printf("%d ", (*p)[i]); //不同类型的指针使用方式不一样，指针部分讲了
	}
	void fun5(int* p, int len)
	{
		int i = 0;
		for (i = 0; i < len; i++)
			printf("%d ", p[i]);
	}

//一维数组做参数
	//数组形式做参数，紧挨着变量名的方括号会被解析成 *
	//void fun1(int p[5], int len);int p[5]被编译器解释成 int* p
	//void fun1(int* p, int len);二者一模一样
	//void fun1(int p[], int len);[ ]就是*，注意只有 1 个，二维数组先不要惯性套用，再讲

//传递二维数组
	void fun7(int(*p)[2][3], int len1, int len2);
	void fun8(int(*p)[3], int len1, int len2);
	void fun9(int *p, int len1, int len2);
	void fun7(int(*p)[2][3], int len1, int len2)
	{
		int i, j = 0;
		for (i = 0; i < len1; i++)
		{
			for (j = 0; j < len2; j++)
			{
				printf("%d ", (*p)[i][j]);
			}
		}

	}
	void fun8(int(*p)[3], int len1, int len2)
	{
		int i,j = 0;
		for (i = 0; i < len1; i++)
		{
			for (j = 0; j < len2; j++)
			{
				printf("%d ", p[i][j]);
			}
		}
			
	}void fun9(int *p, int len1, int len2)
	{
		int i = 0;
		for (i = 0; i < len1*len2; i++)
		{
			printf("%d ", p[i]);
		}
	}

//二维数组做参数
	//数组形式做参数，紧挨着变量名的方括号会被解析成 *
	//void fun1(int p[2][5], int hang, int lie);[2]的方括号被编译器解释成*
	//void fun1(int p[][5], int hang, int lie);二者一模一样
	//void fun1(int (*p)[5], int hang, int lie);[ ]就是*，注意只有 1 个

//传址调用
	void fun10(int a);
	void fun10(int a) //a 是 fun 的局部变量，只在 fun 有效
	{
		a = 3;
	}
	void fun11(int* a);
	void fun11(int* a) //a 是 fun 的局部变量，只在 fun 有效
	{
		*a = 3;
	}

//传二级指针
	//如果想要修改指针的指向，那就传指针的地址
	void fun12(int** p);
	void fun12(int** p) //所以此处用 int** p
	{
		*p = NULL;
	}

//递归的初步理解
	//函数自己调用自己，就叫递归调用
	//递归的本质就是循环。循环可以完全代替递归，但是递归在某些情况下代码会简洁一些
	//递归层数不能太多，会爆栈
	//void fun(void)
	//{
	//	fun();
	//}


//循环角度理解递归
	void fun13(int i) //循环控制变量
	{
		if (i < 5) //循环的条件
		{
			printf("%d ", i);
			fun13(i + 1); //循环控制变量变化，不要用 i-- i++：会把自加/减前的值传出去
		}
	}

//展开理解递归
	void fun14(int i) //循环控制变量
	{
		if (i < 5) //循环的条件
		{
			fun14(i + 1);
			printf("%d ", i);
		}
	}

//通项公式递归方法
	//知道数列的指定项，然后根据通项公式
	//1、斐波拉契数列：
	//第 1 项 f(1) == 0
	//第 2 项 f(2) == 1
	//第 n 项 f(n) = f(n - 1) + f(n - 2)
	int Fibonacci(int n)
	{
		if (n == 1)
		{
			return 0;
		}
		else if (n == 2)
		{
			return 1;
		}
		else if (n >= 2)
		{
			return Fibonacci(n - 1) + Fibonacci(n - 2);
		}
		else
		{
			printf("输入错误\n");
		}
	}
	//2、阶乘：
	//第 1 项 f(1) == 1
	//第 n 项 f(n) == n * f(n - 1)
	int Factorial(int n)
	{
		if (n == 1)
		{
			return 1;
		}
		else if (n >= 2)
		{
			return n * Factorial(n - 1);
		}
		else
		{
			printf("输入错误\n");
		}
	}

//函数指针
	//函数也有地址，叫函数地址，对函数名取地址：&fun
	//特殊点：函数名就是函数地址：fun == &fun
	//去掉函数名，就是函数的类型，比如int fun(int a, double b) 函数类型是 int(int a, double b)
	//函数指针就是：int(*p)(int a, double b) = &fun; //fun = &fun *p = fun =*fun
	//函数调用形式是：函数名 + 参数列表，本质是：函数地址 + 参数列表
	void fun15(int a)
	{
		printf("------\n");
		printf("%d\n", a);
	}



	int main(void)
	{
//函数声明  2025.9.4
	void fun(void); //局部位置


//函数调用
	//函数名加上参数列表，有参数填参数，没参数什么都不要写，void 也不要写
	//函数只有在主函数逻辑中调用了，才能被执行
	//函数调用执行过程：调用时跳到函数内部执行，执行完跳回到函数调用处，再继续往下执行
	//函数调用比直接写代码执行慢，但是它的好处远远大于这点儿慢
	fun();

//函数返回值
	int a = fun1();//函数调用，将函数的返回值 12 赋值给 a
	printf("%d\n", a);
	printf("%d %d\n", a, fun1());//函数调用只要写了，就一定会执行函数的代码，调用几次，执行几遍。

//return的作用
	fun2();

//不是所有的路径都有返回值
	fun3(3);
	fun3(2);

//谨慎返回局部变量的地址
	//fun4函数执行完毕后b将会释放，此时返回的地址&b并非b的地址，若此时c被系统分配到了该地址，如果后续对*b进行操作，会改变c的值，造成无法估计的错误
	//int* b = fun4();此时不能通过*b 进行操作，因为空间已经被释放，非法操作
	//*b = 11;

//函数参数 2025.9.5
	int b = 10;
	int c = Sum(b, 4); //调用传参数，叫实际参数，简称实参
	printf("%d \n", c);

//传递一维数组
	int d[5] = { 5,7,3,8,2 };
	fun5(d, 5); //fun1 传递 d，数组名是首元素首地址，所以用 int*p 形参
	fun6(&d, 5); //fun2 传递&d,是一维数组地址，所以用 int(*p)[5]形参

//传递二维数组
	int e[2][3] = {5,7,3,8,2,6};
	fun7(&e, 2, 3);
	fun8(e, 2, 3);
	fun9(&e[0][0], 2, 3);

//传址调用
	a = 2;//a 是 main 的局部变量，只在 main 有效，跟 fun 函数里完全不一样
	fun10(a);//fun函数里面a的地址与主函数main里面a的地址是不一样的，传地址，即用一级指针来传递
	printf("%d\n", a);
	a = 2; 
	fun11(&a);//传地址，使得fun函数里面a的地址与主函数main里面a的地址一致
	printf("%d\n", a);

//传二级指针
	int* f= 2;
	fun12(&f);//修改一级指针的指向，传指针变量的地址，即用二级指针来传递
	printf("%p\n", f);

//循环角度理解递归
	fun13(1);//循环控制变量初始值

//展开理解递归
	fun14(1);

//通项公式递归方法
	printf("%d\n", Fibonacci(3));
	int i = 0;
	for (i = 1; i <= 10; i++)
		printf("%d ", Fibonacci(i));
	printf("%d\n", Factorial(3));
	for (i = 1; i <= 10; i++)
		printf("%d ", Factorial(i));

//函数指针
	void (*p)(int a) = &fun15;//void(int a) *p 
	(&fun15)(3);
	fun15(4);
	p(5);
	(*p)(6);//*p == p == &fun == fun
	(*fun)(7);

	system("pause");
	return 0;
}
*/