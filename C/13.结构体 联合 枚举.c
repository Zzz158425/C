#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

/*
//结构体类型介绍	2025.9.8
	//通过一个语法结构，将不同的数据类型包在一起，这样操作时就一块操作了
	//整个这个结构是一个数据类型，跟 int double 一样，类型本身不占空间，用这个类型定义变量时，变量占空间。
	struct Node //struct 是关键字 Node 是名字，合法的标识符即可
	{
		char name[20]; //叫结构体成员
		int age;
		double score;
	}; //结尾加上分号，不加报错


//无名结构体
	struct //没有名字，无法通过名字定义结构体变量，使用受限
	{
		char name[20];
		int age;
		double score;
	} nd = { "栗子", 19, 78.9 }, * ne; //只能在这里定义变量，有名字的也可以在这定义变量

//特殊结构体成员
	//结构体内不能放函数，但是可以放函数指针
	void fun(void)
	{
		printf("-----------\n");
	}
	struct HU
	{
		int al;
	};
	struct Node1
	{
		struct HU tt;//结构体嵌套
		//struct Node uo;不能自己作为自己的成员
		void (*p)(void);
		double score;
	};
	struct Node2
	{
		int a;
		short s;
		double d;
		float f;
	};

//联合
	//所有成员共用一块空间，起始地址起一样，修改一个成员，其他的成员也会变化。
	//sizeof 得到最大成员的空间
	union UN
	{
		int a;// 4 字节
		short s;// 2 字节
		char c;// 1 字节
	};

//枚举
	//enum，一组有名字的 int 类型数据类型的类型
	//定义了一个整型类型，该整形类型有 6 个数据，默认 0 ~x 6，分别是各自的名字
	//int 整型类型的子集
		//char 类型可表示 256 个数据 - 128 ~127
		//short 类型可表示 65536 个数据 - 32768 ~32767
	enum color { yellow, red, black, white, pink, blue };

//枚举应用
	//贪吃蛇小游戏中方向的判断，设定：{ 0,1,2,3 }分别代表{ 东,西,南,北 }四个方向
	enum DIR { east, south, west, north } dir;

	int main(void)
	{
//结构体变量定义
	struct Node na; //声明结构体变量,类型名固定
	struct Node nb = { "小明", 23, 98.5 }; //依次初始化给成员
	struct Node nc = { "小明" }; //初始化部分元素，其他为 0
	struct Node* nd = &nb; //指针对象指向合法空间
	struct Node* ne = (struct Node*)malloc(sizeof(struct Node));
	free(ne);
//成员使用
	//成员访问
	//普通变量用" . "，指针变量用" -> "，叫取成员运算符
	printf("%s %d %lf\n", nb.name, nb.age, nb.score);
	printf("%s %d %lf\n", nd->name, nd->age, nd->score);
	printf("%s %d %lf\n", (&nb)->name, (&nb)->age, (&nb)->score);
	printf("%s %d %lf\n", (*nd).name, (*nd).age, (*nd).score);
	//成员赋值
	strcpy_s(nb.name, 20, "大华"); //字符串必须使用循环或者 strcpy_s 函数，不能=
	nd->age = 45;
	nb.score = 56.7;
	//互相赋值：结构体变量可以直接互相赋值
	struct Node nf = nb;
	nf = *nd;
	printf("%s %d %lf\n", nf.name, nf.age, nf.score);
	nf = (struct Node){ "栗子", 19, 78.9 }; //复合文字
	printf("%s %d %lf\n", nf.name, nf.age, nf.score);

//特殊结构体成员
	struct Node1 ng = { 12, fun };
	ng.p();
	printf("%zd\n", sizeof(struct Node2));

//联合
	union UN un = { 12 }; //只能初始化 1 个数据，即第一个数据
	printf("%d %hd %hhd\n", un.a, un.s, un.c);
	un.a = 66666;
	printf("%d %hd %hhd\n", un.a, un.s, un.c);//un.s = 66666 %(取余) 65536(共用数目) un.c = 66666 %(取余) 256(共用数目)
	//数值在可表示范围内，正常表示，数值不在可表示范围内，存余数
	//char % 256
	//short % 65536
	//int % 4294967296

//枚举
	printf("%d %d %d %d %d %d \n", yellow, red, black, white, pink, blue);
	enum color co = black;
	//int c = white;C++ 不行
	co = blue;
	printf("%zd\n", sizeof(co));

//枚举设置指定值
	enum color { yellow = 3, red, black, white = 20, pink, blue };
	printf("%d %d %d %d %d %d \n", yellow, red, black, white, pink, blue);

//枚举应用
	if (east == dir) {}
	else if (south == dir) {}
	else if (west == dir) {}
	else if (north == dir) {}

	system("pause");
	return 0;
}
*/