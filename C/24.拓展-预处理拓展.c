#include <stdio.h> 
#include <stdlib.h>

/*
//#与##
#define X(a) #a
#define X1(a) #a##"bbb"
#define Y(a,b) #a###b

//__VA_ARGS__与#undef
#define PRINT(...) printf(__VA_ARGS__)
#define X2 123
#undef X2 

//条件编译
#if 0 //假
int b = 0;
#elif 1//真
int a = 0;
#else
int c = 4;
#endif //结尾，必须要有

#define _H_
#ifdef _H_ //如果定义了宏_H_ 则该代码有效
int b = 12;
#endif //结尾

#ifndef _HH_ //如果没有定义了宏_H_ 则该代码有效
int c = 12;
#endif //结尾

//宏拼接
#define FOR int i;for (i = 0; i < 5; i++){ printf("%d ", i); }
#define FOR1 int i;\
for (i = 0; i < 5; i++)\
{ \
	printf("%d ", i); \
}

int main()
{
//#与##
	//预处理：在程序预处理阶段进行执行
	//利用宏创建字符串：#，将 X(a) 中 a 转换为字符串
	printf(X(qwerty));//参数 a 是 qwerty，#将这个参数 qwerty 变成了字符串"qwerty"
	//宏拼接：##
	printf(X1(aaa)); //输出：aaabbb
	printf(Y(xxxx,yyyy));//输出：xxxxyyyy

//__VA_ARGS__与#undef
	//可变参数宏
	//... 表示参数可变，__VA_ARGS__ 用来获取可变参数，即传递的所有东西，直接替换该宏处
	PRINT("%d,%lf\n", 12, 34.5);//将 "%d,%lf\n", 12, 34.5 三个参数替换 __VA_ARGS__ 处
	//取消宏定义：#undef
	//printf("%d",X2);#undef X2 取消 X2，后面不能用了

//条件编译
	//条件编译：#if #else #ifdef #ifndef #endif
	printf("%d\n", a);
	//#if 0
	//代码段
	//#endif 注释了代码段
	printf("%d\n", b);
	//#ifdef 如果定义了宏
	//#endif 结尾
	//ifndef 如果没有定义宏
	//#endif 结尾
	printf("%d\n", c);

//预定义宏名
	//预定义宏名：C 语言定义的一些具有特定功能的宏
	printf(__TIME__); //当前时间 15:04:36
	printf(__DATE__); //当前日期 May 22 2022
	printf(__FILE__); //当前源文件的完整路径
	printf("%d", __LINE__); //当前宏所在行号
	printf("%ld", __STDC_VERSION__);//当前 C 语言标准版本，工程属性->C 语言版本 老旧版本不支持
	//__STDC__ 如果当前有它并指定为 1，说明是符合 C 标准，但是新环境无此宏
	printf("%d", __STDC_HOSTED__);//如果当前环境有它并为 1，说明支持完整的标准库

//#line
	//用来重置 __LINE__ __FILE__
	//但是尽量不要改，改了行号就乱了，调试功能就不能用了
	////#line 10 "test,er"//下一行生效
	//第 10 行

//#error
	//报错，发出错误信息
	//#error "not hello" //后边是错误描述
	//一般与 #if 一起使用
		//#if 1
		//#error not hello
		//#endif

//#pragma常用
	//该指令部分不是通用的，不同的编译器之间移植性不一，并且不同的 C 语言环境有很多各自的用法，使用的时候如果涉及，就查具体文档即可
	//#pragma once 防止头文件重复包含
		//#ifndef _H_
		//#define _H_
		//#endif 与#pragma once等效
	//#pragma pack(4) 设置内存字节对齐数
		//#pragma pack(4) 将当前对齐设置为值 4。该数 1,2,4,8,16
		//#pragma pack() 将当前对齐设置为默认值
		//#pragma pack(push) 将当前对齐的值存储
		//#pragma pack(push,4) 将当前对齐的值存储，然后再将当前对齐设置为 4
		//#pragma pack(pop) 取出栈顶存的对齐数，并设置为当前对齐数
	//#pragma message( "hello world ") 编译时显示双引号的内容，不同的编程器可能会不支持
	//#pragma comment(lib, 库名)，保护库
		//#pragma comment(lib, "Winmm.lib") #include <Mmsystem.h>
		//#pragma comment(lib, "Ws2_32.lib") #include <winsock2.h>
	//#pragma warning vs 编译器专属
		//#pragma warning(disable: 4996 4477)//编译信息窗口，不显示4996和4477号警告
		//#pragma warning(once: 4996 ) //编译信息窗口，4996 号警告仅显示 1 次
		//#pragma warning(error: 4996) //编译信息窗口，把 4996 号警告提升为 error

//#pragma不常用
	//#pragma section 设置其下变量的使用权限
		//#pragma section("mycode", read)
		//__declspec(allocate("mycode"))
		//int i = 0; //变量 i 只能 read 操作
		//#pragma section("mycode", read,write)
		//__declspec(allocate("mycode"))
		//int a = 0; //变量 a 可读可写
	//#pragma push_macro(" macro-name ") 以栈结构存储宏名
		//#define X 1
		//#pragma push_macro("X") 入栈
		//#pragma pop_macro("X") 出栈

	//#pragma region 设置编译器内代码折叠
		//#pragma region
		//代码段 //该部分可以折叠
		//#pragma endregion

	//#pragma data_seg 共享数据段
	//应用在动态链接库里，设置成共享数据，那么 a 这个变量就可以在多进程间共享使用，实现进程间通信。
		//#pragma data_seg("data")
		//	int a = 12;
		//#pragma endregion

//宏拼接
	//一个宏名仅是其同一行的名字，跟别的行没有关系了
	//宏拼接符：\ 连接下一行

	system("pause");
	return 0;
}
*/