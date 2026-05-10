//2025.8.22
#include <stdio.h>
#include <stdlib.h>
//整型常量：
/*
	0125  0 前缀的 8 进制，对应10进制85
	0x125 0x / 0X 前缀是 16 进制，对应10进制293
	0b1010 0b / 0B 前缀是 2 进制 1010，c23 标准新增，老版编译器不支持
*/

//整型常量输出
/*
	16 进制形式：%x %X 没有负数形式
	10 进制形式：%d 正负都有
	8 进制形式： %o 没有负数形式
	没有 2 进制的输出格式说明符。
*/

/*
int main(void)//无参数
{

	printf("value16:%x value10:%d value8:%o\n", 26, 26, 26);
	printf("value16:%x value10:%d value8:%o\n", 0253, 0253, 0253);
	printf("value16:%x value10:%d value8:%o\n", 0xa4, 0xa4, 0xa4);

	system("pause");//卡主

	return 0;
}
*/
//内存单位
/*
计算机常用的单位是字节，数据的读写都是按字节读写的，最小读写 1 字节
计算机最小的 存储单位 是一个二进制位，简称位，1 位存 1 或者 0。
位 bit
字节 byte 1byte == 8bit
千字节 KB 1kb == 1024byte
兆字节 MB 1mb == 1024kb
吉字节 GB 1GB == 1024MB 千兆字节
太字节 TB 1TB == 1024GB 万亿字节，一般个人电脑硬盘
帕字节 PB 1PB == 1024TB 千万亿字节
艾字节 EB 1EB == 1024PB
*/

//整型类型的分类-高效使用空间
/*
short                   短整形 2字节 -32768~32767
unsigned short          无符号短整形 2字节 0~65535
int                     整型 2字节 -32768~32767 or 4字节 -2147483648~2147483647
unsigned int            无符号整形 2字节 0~65535 or 4字节 0~4294967295
long                    长整型 4字节 -2147483648~2147483647 or 8字节-9223372036854775808~9223372036854775807
unsigned long           无符号长整形 4字节 0~4294967295 or 8字节 0~18446744073709551615
ong long(c99)           超长整型 8字节 -9223372036854775808~9223372036854775807
unsigned long long(c99) 无符号超长整形 8字节 0~18446744073709551615
*/


//整型常量后缀 2025.8.25
	//printf("%p", 12ull);//__int64 64位整型 8字节

/*
int main(void)//无参数
{

//变量的声明与定义
	int A;//声明变量
	unsigned int B = 23u;//定义变量

//连续定义
	int a, b = 3, d = b;//定义顺序从左到右

//变量的赋值
	a = 56;//右侧赋给左侧
	int e = 5, f = 3;
	printf("%d, %i\n", e, f); //int类型的格式说明符是%i,也可用%d，一般习惯用%d

//连续赋值
	a = b = 34;//从右到左

//其他整型格式说明符
	short s = 34;
	unsigned short us = 56;
	int i = 34;
	unsigned int ui = 45u;
	long l = 34l;
	unsigned long ul = 56lu;
	long long ll = 34ll;
	unsigned long long ull = 56llu;
	printf("%hd, %hu\n", s, us);
	printf("%d, %u\n", i, ui);
	printf("%ld, %lu\n", l, ul);
	printf("%lld, %llu\n", ll, ull);

//变量的地址
	printf("%p\n", &a);//输出a的地址

//scanf输入整型 2025.8.26
	printf("输入前：a=%d, b=%d\n", a, b);
	//scanf_s("%d%d", &a, &b); //一定要变量的地址 scanf_s更安全 也可以使用宏#define _CRT_SECURE_NO_WARNINGS去去掉scanf警告 分隔符%默认空格 回车 tab键
	printf("输入后：a=%d, b=%d\n", a, b);

//scanf的分隔符
	//scanf_s("%d,%d", &a, &b);//逗号分隔
	printf("输入后：a=%d, b=%d\n", a, b);

//sizeof 算对应变量所占字节数
	int M = 1;
	long long N = 2;
	printf("%zu,%zu\n", sizeof(long long), sizeof(M));

//signed 有符号的关键字，即有正负数，可省略，跟 unsigned 对应

	system("pause");//卡主
	return 0;
}
*/
