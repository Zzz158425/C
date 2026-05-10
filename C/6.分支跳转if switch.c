#include <stdio.h> 
#include <stdlib.h>

/*
int main(void)
{
//if 结构 2025.8.30 条件为真 执行代码 
	int score = 80;
	if (score >= 60)
	{
		printf("及格\n");
	}
	if (score < 60)
	{
		printf("不及格\n");
	}

//if 结构注意点
	//当结构只有一条语句时，可以不加大括号。if (score >= 60) printf("及格\n");
	//if 后别加分号

//if-else 结构 
    //只判断一次 比用两个if效率更高
	//else 分支不能独立存在
	int a = 70;
	if (a >= 60)
	{
		printf("及格\n");
	}
	else
	{
		printf("不及格\n");
	}

//条件表达式
	//条件 ? 表达式 1 : 表达式 2;
	//条件为真时，执行表达式 1，整个条件表达式的结果就是表达式 1 的值
	//条件为假时，执行表达式 2，整个条件表达式的结果就是表达式 2 的值
	//if-else 是结构，专业名词是复合语句，其分支内可以写任何合法的语句。
	//条件运算符是运算符，其三个部分必须都是表达式，不能是语句，有返回值的函数也是表达式。条件表达式是有结果的，可以赋值，可以输出，int a = 3==3 ? 5 : 6;
	int age = 19;
	age >= 18 ? printf("成年人\n") : printf("未成年人\n");

//多选一结构：if  else if else if  else
	//从第一个条件判断，执行第一个条件为真的分支，执行完直接结束结构，即使下面的条件为真，也不看了
	//else 分支一般用来处理默认情况，即上面条件没有涉及的部分
	if (score >= 0 && score < 60)
	{
		printf("不及格\n");
	}
	else if (score >= 60 && score < 70)
	{
		printf("及格\n");
	}
	else if (score >= 70 && score < 90)
	{
		printf("良好\n");
	}
	else if (score >= 90 && score <= 100)
	{
		printf("优秀\n");
	}
	else
	{
		printf("成绩错误\n");
	}

//switch结构
    //用匹配标签与标签进行依次比较，相等的，就执行相应分支 
	//匹配标签是整型表达式，标签是整型常量表达式
	//break 的作用是跳出结构
	int b = 2;
	switch (b + 1)
	{
	case 1:
		printf("case 1\n");
		break;
	case 2:
		printf("case 2\n");
		break;
	case 3:
		printf("case 3\n");
		break;
	default:
		printf("default\n");
		break;//可以不写
	}

//switch结构表示范围
	//break 的作用是中断跳出 switch 结构，没有 break，对应的分支执行完不结束 switch，继续执行下一个分支，直到遇见 break 或者 switch 结构结束。
	switch (b)
	{
	case 1:
		printf("case 1\n");
		break;
	case 2:
		printf("case 2\n"); //无 break,执行完 2 继续执行 3
	case 3:
		printf("case 3\n");
		break; //此处结束 switch 结构
	default:
		printf("default\n");
	}

	int c;//判断输入的数是否在2~8 or 10~16之间
	scanf_s("%d", &c);
	switch (c)
	{
	case 2:case 3:case 4:case 5:case 6:case 7:case 8:
		printf("在范围2~8\n");
		break;
	case 10:case 11:case 12:case 13:case 14:case 15:case 16:
		printf("在范围10~16\n");
		break;
	default:
		printf("不在范围\n");
	}

	system("pause");
	return 0;

}
*/