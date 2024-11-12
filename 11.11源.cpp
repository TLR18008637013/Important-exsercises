#define ­_CRT_SECURE_NO_WARNINGS 1
/*
@Filename: ex601.c
@Author: Ju Chengdong
@Version: 1.0
@Date: 2021-03-18
@Description: Simple Application of Pointer
*/

#include <stdio.h>
/*主函数*/
/*int main(void) {
	int sum(int* a, int* b);
	int minus(int* a, int* b);
	void swap(int* a, int* b);

	int a, b;
	int* pa = &a, * pb = &b;
	scanf("%d,%d", &a, &b);

	int (*p)(int*, int*);
	p = sum;
	printf("%d", (*p)(pa, pb));
	p = minus;
	printf("\n%d", (*p)(pa, pb));

	void (*q)(int*, int*);
	q = swap;
	(*q)(pa, pb);

	printf("\n%d,%d", a, b);
	return 0;
}*/

/*
 * 函数名称：sum
 * 函数功能：对两个整数进行加法计算
 * 形式参数：a，整型指针
 * 形式参数：b，整型指针
 * 返 回 值：int型，为两个整数的加法和
 */
int sum(int* a, int* b) {
	int num;
	num = *a + *b;
	return num;
	//请编程实现本函数

}

/*
 * 函数名称：minus
 * 函数功能：对两个整数进行减法计算
 * 形式参数：a，整型指针
 * 形式参数：b，整型指针
 * 返 回 值：int型，为两个整数的减法差
 */
int minus(int* a, int* b) {
	int num;
	num = *a - *b;
	return num;
	//请编程实现本函数

}

/*
 * 函数名称：swap
 * 函数功能：交换两个整数数值
 * 形式参数：a，整型指针
 * 形式参数：b，整型指针
 * 返 回 值：无
 */
void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	//请编程实现本函数

}
/*
@Filename: ex602.c
@Author: Ju Chengdong
@Version: 1.0
@Date: 2021-03-18
@Description: Pointer As Function Parameter
*/
#include <stdio.h>
/*int main(void) {
	void assign(int* array, int length);
	int max(int* array, int length);
	int a[5];
	assign(a, 5); 
	printf("max=%d", max(a, 5)); 
	return 0;
}*/

/*
 * 函数名称：assign
 * 函数功能：通过键盘输入为一维数组元素赋值
 * 形式参数：array为int型指针；length为int型，可用于表示一维数组长度
 * 返 回 值：无
 */
void assign(int* array, int length) {
	int i = 0;
	for (i = 0; i < length; i++) {
		scanf("%d", &array[i]);
	}
	// 请编码实现assign函数

}

/*
 * 函数名称：max
 * 函数功能：求解一维数组元素最大值
 * 形式参数：array为int型指针；length为int型，可用于表示一维数组长度
 * 返 回 值：int型，为数组元素最大值
 */
int max(int* array, int length) {
	int i = 0;
	
	for (i = 1; i < length; i++) {
		if(array[i]>*array){
			*array = array[i];
		}
		
	}
	return *array;
	// 请编码实现max函数

}
#include <stdio.h>
#include <string.h>
#define ROWS 5
#define COLUMNS 20
#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLUMNS 20

/*
@Filename: ex603.c
@Author: Ju Chengdong
@Version: 1.0
@Date: 2021-03-18
@Description: Sort Words
@Features: 基于字符数组指针（行指针）实现
*/

/*
 * 函数名称：assign
 * 函数功能：通过键盘输入为多个一维字符数组（字串）赋值
 * 形式参数：arr为一维字符数组指针（行指针）；rows为int型，单词字串个数
 * 返 回 值：无
 */
void assign(char (*arr)[COLUMNS], int rows) {
	for (int i = 0; i < rows; i++) {
		scanf("%s", arr[i]);
	}
}

/*
 * 函数名称：show
 * 函数功能：输出显示所有单词（字串）
 * 形式参数：arr为一维字符数组指针（行指针）；rows为int型，单词字串个数
 * 返 回 值：无
 */
void show(char (*arr)[COLUMNS], int rows) {
	for (int i = 0; i < rows; i++) {
		printf("%s\n", arr[i]);
	}
}

/*
 * 函数名称：sort
 * 函数功能：对多个一维字符数组（字串）进行排序
 * 形式参数：arr为一维字符数组指针（行指针）；rows为int型，单词字串个数
 * 返 回 值：无
 */
void sort(char(*arr)[COLUMNS], int rows) {
	for (int i = 0; i < rows - 1; i++) {
		for (int j = 0; j < rows - 1 - i; j++) {
			if (strcmp(arr[j], arr[j + 1]) > 0) { 
				char temp[COLUMNS];
				strcpy(temp, arr[j]);
				strcpy(arr[j], arr[j + 1]);
				strcpy(arr[j + 1], temp);
			}
		}
	}
}

/*int main(void) {
	// ch为二维字符数组，包含ROWS个单词，每个单词最多COLUMNS个字母
	char ch[ROWS][COLUMNS];
	memset(ch, 0, sizeof(ch));
	// p是一个指向字符数组的指针，称为行指针，请参见教材Page189
	// 必须给p指定长度，否则编译不报错，运行也不报错，但会不正常
	// p与ch等价，因此既可引用p，也可引用ch
	char (*p)[COLUMNS] = ch;

	// 从键盘输入ROWS个单词，为ch赋值
	assign(p, ROWS);

	// 对ch中的ROWS个单词进行排序
	sort(p, ROWS);

	// 输出显示单词排序结果
	show(p, ROWS);

	return 0;
}*/
/*
@Filename: ex604.c
@Author: Ju Chengdong
@Version: 1.0
@Date: 2021-03-18
@Description: Number to Month
*/
#include <stdio.h>
/*
 * 函数名称：hundredsDigit
 * 函数功能：获取形参整数位于百位上的数字
 * 形式参数：num，一个整型数
 * 返 回 值：返回形参整数位于百位上的数字
 */
static int hundredsDigit(int num) {
	int k = num / 100;
	return k%10;
	// 请编程实现本函数

}

/*
 * 函数名称：tensDigit
 * 函数功能：获取形参整数位于十位上的数字
 * 形式参数：num，一个整型数
 * 返 回 值：返回形参整数位于十位上的数字
 */
static int tensDigit(int num) {
	int k = num / 10;
	return k % 10;
	// 请编程实现本函数

}

/*
 * 函数名称：unitsDigit
 * 函数功能：获取形参整数位于个位上的数字
 * 形式参数：num，一个整型数
 * 返 回 值：返回形参整数位于个位上的数字
 */
static int unitsDigit(int num) {
	return num % 10;
	// 请编程实现本函数

}

/*
 * 函数名称：searchMonth
 * 函数功能：对num进行判断，若1≤num≤12，返回month[num]；否则返回month[0]
 * 形式参数：month，为表示月份单词的字符指针数组
 *           num，为一个整数
 * 返 回 值：字符指针，为月份单词的首地址
 */
static char* searchMonth(char* month[], int num) {
	if (num <= 12 && num >= 1) {
		return month[num];
	}
	else {
		return month[0];
	}
	// 请编程实现本函数

}

/*
 * 函数名称：getNumber
 * 函数功能：从键盘输入一个三位正整数，若不符合要求，则重新输入
 * 形式参数：无
 * 返 回 值：返回所输入的三位正整数
 */
int getNumber() {
	int num;
	scanf("%d", &num);
	if (num >= 100 && num <= 999) {
		return num;
	}
	else {
		scanf("%d", &num);
	}
	// 请编程实现本函数

}

/*
 * 函数名称：bizProcess
 * 函数功能：业务处理函数，功能定义如下。
 *  （1）调用hundredsDigit等函数，对一个三位数的各位进行拆分并计算数字和
 *  （2）调用searchMonth函数，对上述数字和进行检索返回其月份单词
 *  （3）按题目要求的格式，打印输出上述结果
 * 形式参数：month，为一个指针数组，指向月份单词的字串数组
 *           num，一个整数
 * 返 回 值：无
 */
void bizProcess(char* month[], int num) {
	int unitsD, tensD, hundredsD, sum;
	unitsD = unitsDigit(num);
	tensD = tensDigit(num);
	hundredsD = hundredsDigit(num);
	sum = unitsD + tensD + hundredsD;

	printf("%s", searchMonth(month, sum));
}

/*int main(void) {
	
	char* month[] =
	{
	"***",
	"January", "February", "March",
	"April", "May", "June",
	"July", "August", "September",
	"October", "November", "December"
	};
	
	int number = getNumber();
	
	bizProcess(month, number);

	return 1;
}*/
//注：应耐心研读各函数模块功能及其逻辑关系。
#include <stdio.h>
#include <stdlib.h>
#define LENGTH 10

/* 函数声明 */
void input(int* p, int n);
void output(int* p, int n);
void move(int* p, int length, int m);
void moveToRight(int* p, int length, int m);
void moveToLeft(int* p, int length, int m);

/* 主函数 */
int main(void) {
	/* 定义数据结构 */
	int a[LENGTH], m; 
	int* p = a;

	/* 调用input函数，通过键盘输入为数组a赋值 */
	input(p, LENGTH);

	/* 从键盘输入为循环移动位置个数m赋值 */
	scanf("%d", &m);
	/* 调用move函数，完成数组元素的循环移动 */
	move(p, LENGTH, m);

	/* 调用output函数，输出移动后的数组元素 */
	output(p, LENGTH);

	return 0;
}

/*
 * 函数名称：input
 * 函数功能：通过键盘输入为一维数组元素赋值
 * 输入格式：各输入数据之间以空格分隔
 * 形式参数：p，int型指针变量，一维整型数组首地址
 * 形式参数：n，int型，一维数组长度
 * 返回值：无
 */
void input(int* p, int n) {
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
	}
}

/*
 * 函数名称：output
 * 函数功能：向屏幕打印输出一维数组元素值
 * 输出格式：各输出数据之间以空格分隔
 * 形式参数：p，int型指针变量，一维整型数组首地址
 * 形式参数：n，int型，一维数组长度
 * 返回值：无
 */
void output(int* p, int n) {
	for (int i = 0; i < n; i++) {
		if (i != 0) {
			printf(" ");
		}
		printf("%d", p[i]);
	}
	printf("\n");
}

/*
 * 函数名称：moveToRight
 * 函数功能：使一维数组各元素向右循环移动m个位置
 * 形式参数：p，int型指针变量，一维整型数组首地址
 * 形式参数：length，int型，一维数组长度
 * 形式参数：m，int型，循环移动的位置数
 * 返回值：无
 */
void moveToRight(int* p, int length, int m) {
	int temp[99]; 
	for (int i = 0; i < m; i++) {
		temp[i] = p[length - m + i];
	}
	for (int i = length - 1; i >= m; i--) {
		p[i] = p[i - m];
	}
	for (int i = 0; i < m; i++) {
		p[i] = temp[i];
	}
}

/*
 * 函数名称：moveToLeft
 * 函数功能：使一维数组各元素向左循环移动m个位置
 * 形式参数：p，int型指针变量，一维整型数组首地址
 * 形式参数：length，int型，一维数组长度
 * 形式参数：m，int型，循环移动的位置数
 * 返回值：无
 */
void moveToLeft(int* p, int length, int m) {
	int temp[99]; 
	for (int i = 0; i < m; i++) {
		temp[i] = p[i];
	}
	for (int i = 0; i < length - m; i++) {
		p[i] = p[i + m];
	}
	for (int i = 0; i < m; i++) {
		p[length - m + i] = temp[i];
	}
}

/*
 * 函数名称：move
 * 函数功能：使一维数组元素循环向左或向右移动m个位置
 * 形式参数：p，int型指针变量，一维整型数组首地址
 * 形式参数：length，int型，一维数组长度
 * 形式参数：m，int型，表示循环移动的方向和移动的位置个数
 *          当m>0时，执行向右循环移动（水平方向从左向右循环移动）
 *          当m=0时，不做任何移动
 *          当m<0时，执行向左循环移动（水平方向从右向左循环移动）
 * 返回值：无
 */
void move(int* p, int length, int m) {
	if (m > 0) {
		/* 向右循环移动 */
		moveToRight(p, length, m);
	}
	else if (m < 0) {
		/* 向左循环移动 */
		moveToLeft(p, length, -m);
	}
}
