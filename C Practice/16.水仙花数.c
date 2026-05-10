#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

/*
void shuixianhua1(void);
void shuixianhua2(void);
int main(void)
{
	shuixianhua1();
	shuixianhua2();

	system("pause");
	return 0;
}

void shuixianhua1(void)
{
	int i, j, k, l, n, m;
	for ( i = 100; i <= 999; i++)
	{
		l = i;
		k = n = m = 0;

		j = l % 10;//个位
		k = j * j * j;
		l = l /= 10;
		j = l % 10;//十位
		n = j * j * j;
		l = l /= 10;
		j = l % 10;//百位
		m = j * j * j;

		if (k + n + m != i)
		{
			k = n = m = 0;
		}
		else
		{
			printf("%d \n", i);
			k = n = m = 0;
		}
	}
}

void shuixianhua2(void)
{
	int i = 0, ge, shi, bai;
	for (i = 100; i <= 999; i++)
	{
		ge = i % 10; //个位
		shi = i / 10 % 10; //十位
		bai = i / 100; //百位
		if (ge * ge * ge + shi * shi * shi + bai * bai * bai == i)
		//if((int)(pow(ge,3) + pow(shi, 3) + pow(bai, 3)) == i)，pow为double类型，转成int类型输出
			printf("%d ", i);
	}
}
*/