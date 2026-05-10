//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
int main(void)
{
//字符数组 2025.9.7	
	char ch1[5] = { 'A', 66, 'C', 'D' };//初始化部分元素，其余默认初始化为 0
	char ch2[] = { 'A', 66, 'C' }; //初始化时，可不写个数
	int i;
	for (i = 0; i < 5; i++)
		printf("%d, %c\n", ch1[i], ch1[i]);

//字符串结尾
	//字符串：以 \0 结尾的字符数组，\0 就是数字 0，ASCII 表上第一个字符
	//'\0' : 字符，数字 0 的字符形式，\叫转义字符，\0 共同构成 1 个字符，站 1 字节，如n -> \n 转义为换行
	//0 : 数字 0 ，数值上'\0'，NULL，0 三者一样，作用在不同场景，以经验区分，字符\0，数字0，地址NULL
	//'0' : 字符 0，48 的字符形式
	printf("%d %d %d\n", '\0', 0, '0');

//字符串简介
	//字符串的本质还是字符数组
	char ch3[5] = { 'A', 'B', 'C', 'D', '\0' }; //字符串
	char ch4[5] = { 'A', 'B', 'C', 0 }; //字符串
	char ch5[] = { 'A', 'B', 'C', NULL }; //字符串，但是一般不这么写
	char ch6[5] = { 'A', 'B', 'C' }; //字符串，char ch6[5] = { 'A', 'B', 'C',0 ,0}默认有 0

//常量字符串
	//双引号包着
	//常量字符串本质就是字符数组，该字符串就是数组的名字
	"hello c3";
	//自带\0 结尾，"hello c3"就是：'h', 'e' 'l', 'l', 'o', ' ', 'c', '3', '\0' 共 9 个字符。
	putchar("hello c3"[0]);
	putchar("hello c3"[4]);
	putchar("hello c3"[5]);//访问元素，可以输出，但是不能赋值修改，因为是常量字符串
	printf("%zd \n", sizeof("hello c3"));

//常量字符串初始化
	char ch7[10] = { "hello c3" };//字符串若超出承载个数，\0将不会存入ch7里面，输出将会出现未知符号
	char ch8[10] = "hello c3"; //常用
	char ch9[] = "hello c3"; //初始化时，可不写个数
	puts(ch7);//遇到\0停止
	puts(ch8);
	printf("%zd", sizeof(ch9));
	ch9[2] = 'w';//数组 ch7,ch8,ch9 是三块空间，初始化的过程是将常量字符串复制进数组里，操作 ch9 是操作的复制份，是不是常量字符串本身。
	puts(ch9);

//字符指针
	char* str = "hello c3~"; //C 语言里可以，c++ 要用下面
	const char* str1 = "hello c3~"; //最完美写法，最精确的写法，const 就是常的意思，常量指针，指向常量字符串，因为字符串就是自身的数组名字
	const char* str2 = "he\0llo c3~";
	puts(str2);
	puts(str2 + 3);

//字符串输出 %s
	char ch10[10] = "hello c";
	char ch11[5] = { 'A', 'C', 'y','r', 'y' };
	printf("str : %s\n", ch10);//%s 从首地址 ch10 输出，一直到 \0 结束，没有 \0 就会越界
	printf("str : %s\n", ch11);//越界，字符数组不包含 \0 会一直输出
	printf(ch10);//printf 的第一个参数就是常量字符串，所以可直接输出
	puts(ch10);//puts 专门用于输出字符串

//字符串输入
	char ch12[20] = { 0 };
	//scanf("%s", ch12);老版输入，不推荐使用
	//puts(ch12);
	//scanf_s("%s", ch12, 20);两个参数，原版 1 个参数，空格会作为分隔符，所以无法获取到空格
	//puts(ch12);

	//gets_s(ch12, 15);//可以获取到空格，专用于字符串输入
	//puts(ch12);
	//char* str3 = (char*)malloc(15);
	//if (NULL == str3)
	//	return 0;
	//gets_s(str3, 15);//可以获取到空格，专用于字符串输入
	//puts(str3);
	//free(str3);

//字符串操作函数 string.h
	//字符串拷贝：将字符串装进参数 1 的数组，注意别越界
	char str4[20] = { 0 }; //必须有合法空间，char* str 不行，除非 malloc
		//strcpy(str4, "hello world");旧版，不推荐使用 可以加 #define _CRT_SECURE_NO_WARNINGS 避免警告
	strcpy_s(str4, 20, "hello world"); //新版
	puts(str4);
	//字符串拷贝 n 个：将字符串前 n 个字符
	char str5[20] = { 0 };
		//strncpy(str5, "hello world", 3); 旧版，无\0，不推荐使用
	strncpy_s(str5, 20, "hello world", 3); //新版，自动加\0
	puts(str5);
	//字符串拼接：将一个字符串拼接在另一个字符串尾部，注意别越界
	char str6[20] = "hello ";
		//strcat(str6, "world"); 旧版，不推荐使用 可以加 #define _CRT_SECURE_NO_WARNINGS 避免警告
	strcat_s(str6, 20, "world"); //新版
	puts(str6);
	//字符串拼接 n 个：将一个字符串前 n 个拼接在另一个字符串尾部，注意别越界
	char str7[20] = "hello ";
		//strncat(str7, "world", 3);旧版，#define _CRT_SECURE_NO_WARNINGS
	strncat_s(str7, 20, "world", 3); //新版
	puts(str7);
	//字符串比较：从头依次比较，直到第一个不同的字符，此时谁大就谁大，否则相等 比较ASCII码值
	int a = strcmp("abc", "abc"); //一样大，返回 0
	int b = strcmp("abr", "abcde"); //前大，返回 1 ASCII(r) > ASCII(a)
	int c = strcmp("abcde", "ar"); //后大，返回-1 ASCII(b) < ASCII(r)
	printf("%d %d %d\n", a, b, c);
	//字符串比较前 n 个：从头依次比较，直到第一个不同的字符，此时谁大就谁大，否则相等
	int d = strncmp("ab", "abc", 1); //一样大，返回 0
	int e = strncmp("abr", "abcde", 2); //一样大，返回 0
	int f = strncmp("abcde", "ar", 2); //后大，返回-1
	printf("%d %d %d\n", d, e, f);
	//字符串长度：到\0 终止，不算\0
	size_t g = strlen("abcd"); //长度是 4
	size_t h = sizeof("abcd"); //5 个字节
	size_t j = strlen("abc\0def"); //长度是 3
	size_t k = sizeof("abc\0def"); //8 个字节
	printf("%zd %zd %zd %zd", g, h, j, k);

	system("pause");
	return 0;
}
*/