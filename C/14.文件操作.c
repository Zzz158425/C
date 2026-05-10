#include <stdio.h>
#include <stdlib.h>

/*
//fread与fwrite
	struct Node
	{
		int a;
		char str[20];
		double d;
	};

int main(void)
{
//文件操作简单介绍 2025.9.8	
	//磁盘中的各种文件，图片文件(jpg,png,bmp,gif...)，文本(doc,txt,dot,rtf,doct,wps,wpt, pdf,c,cpp,html,css,py...)，其他(zip,7z,exe,msi,dll,lib,apk...)无数种文件类型。
	//不同的文件存储的数据类型不同，文件内存储数据的格式不同。
	//打开文件：fopen fopen_s 
	//读文件：  fgetc fgets  fscanf  fread
	//写文件：  fputc fputs  fprintf fwrite 
	//文件指针：fseek rewind ftell
	//关闭文件：fclose

//fopen与fopen_s
	//FILE：文件类型，* ，就是文件指针，打开文件的本质就是将文件内容从磁盘存进文件缓冲区，对缓冲区进行修改后保存进磁盘，FILE* 可以理解为文件缓冲区首地址。随着操作，文件指针偏移，指向哪儿就从哪儿开始操作
	//返回值：旧函数：直接返回文件操作地址。新函数：通过参数 1 的传址调用获得文件地址新函数返回值表示错误码，0 表示成功，非 0 表示打开失败
	//参数 1：新函数，参数 1 的传址调用获得文件地址，参数 2：相对路径：默认相对于项目文件所在目录，写个名字即可。绝对路径：完整路径名，参数 3：打开方式：文本模式，二进制模式
		
	//FILE* pFile = fopen("stu.txt", "r"); 旧版的函数
	FILE* pFile = NULL;
	FILE* PFile1 = NULL;
	errno_t a = fopen_s(&pFile, "stu.txt", "r");//新版的函数，返回errno_t类型，0 表示成功，非 0 表示打开失败
	//errno_t b = fopen_s(&PFile1, "../stu.txt", "r");//" ../ " 表示在工程文件上一级查找
	if (a != 0 || NULL == pFile)//判断文件是否打开成功
		return 0;
	fclose(pFile);

//相对路径与绝对路径
	//相对路径：工程文件所在目录，工程文件："D:\\Visual Studio2022SharedProject\\2025.8.22\\2025.8.22"
	//绝对路径："D:\\Visual Studio2022SharedProject\\2025.8.22\\2025.8.22\\stu.txt"
	//层级分离需要：正斜杠 " / "，反斜杠 " \\ " 

//文本模式与二进制模式
	//文本模式：
		//"r" / "rt" 只读，只能调用读函数，文件必须存在，否则失败。文件指针指向头字节。
		//"r+"       可读可写读，读写函数都能调用，文件必须存在，否则失败。文件指针指向头字节。
		//"w" / "wt" 擦除写，只能调用写函数，文件不存在时创建文件。文件指针指向头字节。
		//"w+"       可读可写，读写函数都能调用，文件不存在时创建文件。文件指针指向头字节。
		//"a" / "at" 附加写，只能调用写函数，文件不存在时创建文件。文件指针指向尾字节。
		//"a+"       可读可写，读写函数都能调用，文件不存在时创建文件。文件指针指向尾字节。 
	//二进制模式：
		//"rb"  只读，只能调用读函数，文件必须存在，否则失败。文件指针指向头字节。
		//"rb+" 可读可写读，读写函数都能调用，文件必须存在，否则失败。文件指针指向头字节。
		//"wb"  擦除写，只能调用写函数，文件不存在时创建文件。文件指针指向头字节。
		//"wb+" 可读可写，读写函数都能调用，文件不存在时创建文件。文件指针指向头字节。
		//"ab"  附加写，只能调用写函数，文件不存在时创建文件。文件指针指向尾字节。
		//"ab+" 可读可写，读写函数都能调用，文件不存在时创建文件。文件指针指向尾字节。 
	//二者区别：对文件行结尾代码层面处理不同，在 windows 系统中，行结尾是\r\n，文本模式读到的是\n，二进制模式读到的是\r\n 在 linux 系统下都是\n，没有区别。
	FILE* pFile2 = NULL;
	errno_t c = fopen_s(&pFile2, "stuu.txt", "w");//"w" / "wt" 擦除写，打开时就擦除
	if (c != 0 || NULL == pFile2)//判断文件是否打开成功
		return 0;
	
//fputc与fgetc
	fputc('Q', pFile2);//一次写入文件 1 个字符，返回值是字符的 ASCII 整数
	fputc('a', pFile2);
	fputc('Q', pFile2);
	fputc('\n', pFile2);
	fputc('Q', pFile2);
	fclose(pFile2);
	c = fopen_s(&pFile2, "stuu.txt", "r");
	if (c != 0 || NULL == pFile2)
		return 0;
	char d = fgetc(pFile2);
	d = fgetc(pFile2);
	d = fgetc(pFile2);
	d = fgetc(pFile2);
	d = fgetc(pFile2);
	d = fgetc(pFile2);
	d = fgetc(pFile2);
	fclose(pFile2);

//循环读文件 2025.9.9
	//文件结尾标记 EOF 即 -1
	//feof(pFile) 当到结尾时，返回真，不是结尾返回假
	c = fopen_s(&pFile2, "stuu.txt", "r");
	if (c != 0 || NULL == pFile2)
		return 0;
	while (1)//法一
	{
		char e = fgetc(pFile2);
		if (EOF == e)//也可以用if (feof(pFile))
			break;
		putchar(e);
	}
	//while (feof(pFile2) == 0) //while (!feof(pf)) 法二
	//{
	//	char f = fgetc(pFile2);
	//	putchar(f);
	//}
	fclose(pFile2);

//fputs与fgets 2025.9.10
	//一次读写 n 个字符
	c = fopen_s(&pFile2, "stuu.txt", "r");
	if (c != 0 || NULL == pFile2)
		return 0;
	char str[50] = { 0 };
	while (1)
	{
		fgets(str, 45, pFile2);//fgets一行一行的拿 fgetc一个一个的拿
		puts(str);
		if (feof(pFile2))
			break;
	}
	fclose(pFile2);
	c = fopen_s(&pFile2, "stuu.txt", "w");
	if (c != 0 || NULL == pFile2)
		return 0;
	fputs("hello c3", pFile2);
	fclose(pFile2);

//fscanf与fprintf 文件读写 2025.9.21
	c = fopen_s(&pFile2, "stuu.txt", "w");
	if (c != 0 || NULL == pFile2)
		return 0;
	fprintf(pFile, "e:%d, f:%lf,s:%s", 12, 45.6, "hello c3"); //格式化字符串写入文件
	fclose(pFile2);
	c = fopen_s(&pFile2, "stuu.txt", "r");
	if (c != 0 || NULL == pFile2)
		return 0;
	int e = 0;
	double f = 0.0;
	char str1[20] = { 0 };
	fscanf_s(pFile2, "e:%d, f:%lf,s:%s", &e, &f, str1, 20); //成对使用，格式需保持一样，新版，把空格当成了分隔符 只能读出hello
	//fscanf(pFile, "e:%d, f:%lf,s:%s", &a, &b, str1); 老版
	fclose(pFile2);

//fread与fwrite 2进制数据读写
	//以数值类型的数据存储，可以直接使用 fread fwrite，比前三者效率高，因为前三者要先转换，然后存
	c = fopen_s(&pFile2, "stuu.txt", "w");
	if (c != 0 || NULL == pFile2)
		return 0;
	struct Node no = { 12,"hello", 34.5 };
	fwrite(&no, sizeof(no), 1, pFile2);
	fclose(pFile2);
	c = fopen_s(&pFile2, "stuu.txt", "r");
	if (c != 0 || NULL == pFile2)
		return 0;
	struct Node nd;
	fread(&nd, sizeof(nd), 1, pFile2);//可能显示乱码状态，因为不是文本模式 速度比fprintf快
	fclose(pFile2);
	c = fopen_s(&pFile2, "stuu.txt", "w");
	if (c != 0 || NULL == pFile2)
		return 0;
	fprintf(pFile2, "e:%d, f:%lf,s:%s", no.a, no.d, no.str);//用fprintf写入就可以显示正确
	fclose(pFile2);

//ftell rewind fseek
	//rewind 将文件指针指向文件首
	//ftell 返回文件指针指向的文件中的字节下标
	//fseek(参数1，参数2，参数3) 设置文件指针指向哪个字节，成功返回 0
		//参数 1：地址，参数 2：相对位置
	    //参数 3：SEEK_SET 文件首，配合参数 2，比如 3，就是首 + 3 的位置，即第四个字，SEEK_END 文件尾，配合参数 2，比如 - 3，就是结尾 - 3 的位置，即倒数第四个字节，SEEK_CUR 当前位置，配合参数 2，负数左移，正数右移
	c = fopen_s(&pFile2, "stuu.txt", "r+");
	if (c != 0 || NULL == pFile2)
		return 0;
	putchar(fgetc(pFile2));
	putchar(fgetc(pFile2));
	putchar(fgetc(pFile2));
	long l = ftell(pFile2);
	printf("%d\n", l);
	rewind(pFile2);
	l = ftell(pFile2);
	printf("%d\n", l);
	putchar(fgetc(pFile2));
	fseek(pFile2, 3, SEEK_SET);
	putchar(fgetc(pFile2));
	fseek(pFile2, -1, SEEK_END);//最后一个字符为-1 == EOF。若换行，上一行结尾为：内容\r\n
	putchar(fgetc(pFile2));
	fseek(pFile2, -2, SEEK_CUR);
	fputc('w', pFile2);//覆盖当前字符并写入
	fputc('z', pFile2);
	fclose(pFile2);

	system("pause");
	return 0;
}
*/