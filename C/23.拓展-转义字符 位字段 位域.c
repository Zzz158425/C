#include <stdio.h> 
#include <stdlib.h>

/*
//位域、位字段简介 2025.10.11
struct hh
{
	unsigned int a : 1;
	unsigned int b : 1;
	unsigned int c : 1;
	unsigned int d : 1;
	unsigned int e : 1;
	unsigned int f : 1;
	unsigned int g : 1;
	unsigned int h : 1;
}bit;

//多个位的字段
struct hhh
{
	unsigned int a : 2;
	unsigned int b : 3;
	unsigned int d : 4;
}bit1;

//位字段对齐
struct hhhh
{
	unsigned int a : 24;
	unsigned int b : 4;
	unsigned int c : 16;
	unsigned int d : 24;
}bit2;

//位字段控制
struct hhhhh
{
	unsigned int a : 1;
	unsigned int   : 3; 
	unsigned int   : 0;
	unsigned int d : 4;
};

int main()
{
//字母的转义字符
	//转义字符: \，转义字符就是将字符原本的含义进行转换，比如\n，n 本身就是字母，\n 就是换行符了，把 n 原本的含义转换了。
	//C 语言支持的转义后字符，也叫控制字符：
		//0  NUL \0 字符串结尾
		//7  BEL \a 响铃
		//8  BS  \b 光标退1格
		///9 HT  \t tab 水平制表符，空 5 格
		//10 LF  \n 换行
		//11 VT  \v 垂直制表符 PgUp/pgDn
		//12 FF  \f 换页
		//13 CR  \r 光标到首
	printf("\a");
	printf("123\b456");
	printf("\t");
	printf("123\r4567\n");
	//其他的字符也是转义字符，但是 C 语言没有定义其含义，所以其无意义 '\c' '\x' '\y'

//特殊转义
	//特殊：想要输出如下字符，一般加上转义字符
	printf("\\n");//从左到右
	printf("\\ \' \" ");
	putchar('\'');
	//另外：想输出% ，写%% ，这个不是转义字符
	printf("%%\n");

//数字转义
	//\ + 数字 : '\000' '\123' ，该数字默认是 8 进制，其范围是 '\000' - '\377', 对应 10 进制的 0 - 255，刚好 1 字节，转义字符都是 1 字节
	//\ + x + 数字 : '\xa3' '\x12' ，该数字是 16 进制，其范围是 '\x00' - '\xff', 对应 10 进制的 0 - 255，刚好 1 字节，转义字符都是 1 字节
	printf("%hhu", '\377');//%hhu \377 均为 1 字节
	printf("%hho", '\123');// \123 就是八进制 123

//单引号装多个字符
	//单引号里理论上只能放 1 个字符，放多个字符叫字符串，要用双引号
	//一些编译器对单引号里放多个字符也进行了相应处理，但是由于此行为是 C 语言的未定义行为，属于编译器行为，所以该行为可能是不通用的。
	//字符的本质就是 int 整数，4 个字节，每个字符是 1 字节，所以单引号内最多放四个字符
	char a = 'abcd';
	printf("%c\n", a);//a 里装的 d,默认最后一个字符
	//'abcd' 
		//四个字节: 97       98       99       100
		//                01100001 01100010 01100011 01100100(数据高位 -> 地位)
		//小端存储: 数据的低位存在内存的低位
		//                100      99       98       97
		//                0x10     0x11     0x12     0x13
		//' ' 为 4 字节空间，a 只能装 1 个字节，就是 0x10 首地址，这个字节的数据，即 100，

//位域、位字段简介 2025.10.11
	//位的操作可以使用位运算符，第二种方式就是位字段，也叫位域。位运算符可以实现任何操作，而且操作灵活简单快捷
	//由于存储模式取决于系统，所以位域的移植性会有问题，即在当前环境下是 123，代码原模原样移到另一个环境，就变成 789 了，程序运行出现二义性，造成不可预知的错误，即移植性很差
	//形式跟结构体差不多
		//1、成员类型用 unsigned int，或者 signed int，C99 后可以用 bool 别的不行
		//2、a b c d e f g h 叫做标签，跟 switch 那个标签意思一样
		//3、1 表示 1 位，即 a 这个标签代表 1 个 2 进制位，该标签只能赋值 1, 0
		//4、连续的 8 个位，即 1 字节的空间数据，可以 bit.b = 0 操作专门对 1 个位进行读写。
		//5、该 bit 变量本质是 unsigned int 类型变量，上 8 位是 4 字节中的低八位
	struct hh c = { 0 };
	c.a = 1;
	c.b = 0;
	c.c = 1;
	printf("%x\n", *(unsigned int*)&c); //输出 5，c 为位域类型，需要转为unsigned int 类型
	printf("%zd\n", sizeof(struct hh));

//多个位的字段
	//a 字段赋值 : 0 - 1
	//b 字段赋值 : 000 - 111
	//c 字段赋值 : 00000 - 11111
	//d 字段赋值 : 0000 - 1111
	//总字段数是 13 位，即 unsigned int 空间的低 13 位
	struct hhh f = { 0 };
	f.a = 0b01;
	f.b = 0b010;
	f.d = 0b1010;
	printf("%x\n", *(unsigned int*)&f);

//位字段对齐
	//不允许一个字段跨两个 unsigned int 边界，第二个字段会自动移到下一个 unsigned int，相当于 4 字节对齐
	//a b 在第 1 个 unsigned int 的 4 字节          aaaaaaaaaaaaaaaaaaaaaaaabbbb---- 
	//c 在第 2 个 unsigned int 的 4 字节，不能跨字段 cccccccccccccccc----------------
	//d 在第 3 个 unsigned int 的 4 字节            dddddddddddddddddddddddd--------
	//所以 bit 总字段是 12 字节 96 个位
	struct hhhh g = { 0 };
	g.a = 0b000000000000000000001001;
	g.b = 0b0110;
	g.c = 0b00000000000000001010;
	g.d = 0b000000000000000001010011;
	printf("%x\n", g.a);
	printf("%x\n", *(unsigned int*)&g);//小端存储，输出 b a 的内容 0110 0000 0000 0000 0000 0000 1001
	printf("%x\n", *((unsigned int*)&g + 1)); //输出 c 的内容
	printf("%x\n", *((unsigned int*)&g + 2));//输出 d 的内容
	printf("%zd\n", sizeof(struct hhhh));

//位字段控制
	//struct hhhhh
	//{
	//	unsigned int a : 1;                                  a空空空----------------------------
	//	unsigned int : 3; 无名 3 位字段，空闲，无法使用
	//	unsigned int : 0; 0 无名，将 d 字段推到下一个 4 字节
	//	unsigned int d : 4;                                  dddd----------------------------
	//};
	printf("%zd\n", sizeof(struct hhhhh));

	system("pause");
	return 0;
}
*/
