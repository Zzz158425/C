#include <stdio.h> 
#include <stdlib.h>

/*
void fanzhuang();
int main(void)
{
	fanzhuang();

	system("pause");
	return 0;
}

void fanzhuang(void)
{
	//取数算法：
	//int az = 123456, af = 0;
	//while (az != 0) //az 为：123456,12345,1234,123,12,1,0,退出循环
	//{
	//	int w = az % 10; //w 装的依次是 6,5,4,3,2,1
	//	az /= 10; //对10自取整，az = az / 10，变化为：12345,1234,123,12,1,0
	//}
		
	int az = 12345678, af = 0;
	printf("翻转前：%d\n", az);
	while (az != 0)
	{
		int w = az % 10;
		af = w + 10 * af; //累加
		az /= 10;
	}
	az = af;
	printf("翻转后：%d\n", az);
	return 0;
}
*/