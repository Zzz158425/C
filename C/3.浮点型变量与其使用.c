#include <stdio.h>
#include <stdlib.h>

/*
int main(void)
{
//浮点型常量 2025.8.26
	4.5e-5;//0.000045

//浮点型属性
	//float       4       f/F %f -3.40e+38~3.40e+38 8(6)
	//double      8       无  %lf -1.79e+308~1.79e+308 17(10)
	//long double 8/10/16 l/L %Lf -1.79e+308~1.79e+308 17(10)/-1.18e+4932~1.18e+4932 22(10)/-1.18e+4932~1.18e+4932 38(10)
	printf("%e\n",5671.567);//将其转化为科学技术法
	printf("%f\n", 123442345.23243253f);
	printf("%lf\n", 45.6263724687);
//控制小数位数
	printf("%.11lf\n", 45.62637246871);

//浮点型的输入
	float a = 2.3f;
	double b = 4.5;
	long double c = 0.01;
	printf("a:%f,b:%lf,c:%Lf\n", a, b , c);
	//scanf_s("%f%lf%Lf", &a, &b, &c);//不能混用格式说明符
	printf("a:%f,b:%lf,c:%Lf\n", a, b, c);

//浮点型转换成整型
	int d = 34.56; //直接舍弃小数部分，没有四舍五入，a==34
	int e = (int)56.67; //强制类型转换，结果一样
	printf("d:%d,e:%d\n", d, e, c);

	system("pause");
	return 0;
}
*/