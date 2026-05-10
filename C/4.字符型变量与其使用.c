#include <stdio.h>
#include <stdlib.h>

/*
int main(void)
{
//字符常量 2025.8.27
	char a = 'w';//char 1字节 -128~127 %hhd 10进制显示  %c 字符显示
	unsigned char b = '@';//unsigned char 1字节 0~255 %hhd 10进制显示  %c 字符显示
	char c = '!';
	char d = -34;

//字符的输出 大写字母+32=小写字母 大小写转换
	printf("%hhd, %c\n", a , a);
	printf("%hhd, %c\n", b , b);
	printf("%hhd, %c\n", c , c);
	printf("%hhd, %c\n", d , d);
	putchar(a);//putchar 只能输出字符
	putchar('\n');//换行
	putchar(b);
	putchar('\n');
	putchar(c);

//字符变量的输入

	
	char e = 'a';
	putchar(e);
	scanf_s("%c", &e, 1);//需添加参数'1' 表示1字节
	printf("%c\n", e);
	e = getchar();//getchar 只能输入字符 只能取一个字符
	putchar(e);
	

//字符输入前清空缓冲区
	char f, g, h, i;
	f = getchar();
	g = getchar();
	h = getchar();
	i = getchar();
	printf("%hhd, %c\n", f, f);
	printf("%hhd, %c\n", g, g);
	printf("%hhd, %c\n", h, h);
	printf("%hhd, %c\n", i, i);
	char j;
	int k;
	scanf_s("%d", &k);//缓冲区输入 12\n
	rewind(stdin);//清除缓冲区 否则 a将会把上述输入的 12\n 中的\n将被取出作为输入
	j = getchar();
	printf("%d\n", k);
	printf("%hhd,%c", j, j);

	system("pause");
	return 0;
}
*/