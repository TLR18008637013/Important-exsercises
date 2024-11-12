#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void inputArr(int* p, int length);
void printArr(int* p, int length);
int JosephCircle(int* p, int length);

/*int main() {
    int n; //围成一圈的人数
    scanf("%d", &n);

    // 动态申请n个int型的内存单元
    int* arr = (int*)calloc(n, sizeof(int));
    int* p = arr;

    inputArr(p, n);  // 为动态数组元素赋值
    printArr(p, n);   // 输出动态数组元素值
    printf("%d\n", JosephCircle(p, n));  // 输出约瑟夫环问题解

    free(arr);  // 释放动态数组
    arr = NULL;

    return 1;
}*/

/*
 * 函数名称：inputArr
 * 函数功能：为一维整型数组元素赋值。赋值规则：对于包含n个元素的数组，
 *           则从第1个数组元素开始，依次分别赋值为1、2、3 ... n-1、n
 * 形式参数：p，int型指针变量，一维整型数组首地址
 * 形式参数：length，int型，一维数组长度
 * 返回值：无
 */
void inputArr(int* p, int length) {
    for (int i = 0; i < length; i++) {
        p[i] = i + 1;
    }
}

/*
 * 函数名称：printArr
 * 函数功能：输出一维数组元素值。输出规则：每行输出10个元素值，每个值至少占4位位宽；
 *           每行除了最后一个值外，其他元素值之间以逗号分隔
 * 形式参数：p，int型指针变量，一维整型数组首地址
 * 形式参数：length，int型，一维数组长度
 * 返回值：无
 */
void printArr(int* p, int length) {
    printf("%d", p[0]);
    for (int i = 1; i < length; i++) {
        if ((i%10)!=0) {
            printf(",");
        }
        printf("%4d", p[i]);
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    if (length % 10 != 0) {
        printf("\n");
    }
}

/*
 * 函数名称：JosephCircle
 * 函数功能：求解约瑟夫环问题
 * 形式参数：p，int型指针变量，一维整型数组首地址
 * 形式参数：length，int型，一维数组长度
 * 返回值：int型，最后留下来的那个人的编号
 */
int JosephCircle(int* p, int length) {
    int step = 3;  // 步长为3
    int pos = 0;   // 起始位置

    for (int i = 2; i <= length; i++) {
        pos = (pos + step) % i;
    }

    return p[pos];  // 返回最终剩下的人的编号
}
/*
@Filename: ex607.c
@Author: Ju Chengdong
@Version: 1.0
@Date: 2021-03-18
@Description: Two Dimensional Dynamic Array
*/

#include<stdio.h>
#include<stdlib.h>

/*
 * 动态申请二维数组的方法：
 * 方法一：利用一个二级指针来实现（本例所采用的方法）
 * 方法二：利用数组指针来实现
 * 方法三：利用一维数组来模拟二维数组
 */

 /*
  * 1. 动态数组的创建和引用应遵循原则：
  * （1）申请的时候从外层往里层，逐层申请；
  * （2）释放的时候从里层往外层，逐层释放。
  * 2. 构建动态数组时所需指针：
  * （1）对于构建一维动态数组，需要一维指针；
  * （2）对于构建二维动态数组，需要一维、二维指针；
  * （3）对于构建三维动态数组，需要一维、二维、三维指针；
  * （4）依此类推。
  * 3. 构建动态数组时所需函数：
  * （1）malloc()
  * （2）calloc()
  * （3）free()
  * （4）realloc()等
  * 4. 使用malloc()函数创建一维动态数组的一般格式：
  *    类型说明符 *数组名 = (类型说明符 *)malloc(数组长度 * sizeof(类型说明符));
  * 5. 使用malloc()函数创建二维动态数组的一般格式：
  *    类型说明符 **数组名 = (类型说明符 **)malloc(第一维长度 * sizeof(类型说明符*));
  *    示例：
  *    int **arr=(int **)malloc(n1*sizeof(int *));
  *    for(i=0;i<第一维长度;i++){
  *        数组名[i] = (类型说明符 *)malloc(第二维长度 * sizeof(类型说明符));
  *    }
  */

int main(void) {
    void assignValuesTo2DArray(int** arr, int rows, int columns);
    void show2DArray(int** arr, int rows, int columns);
    int** create2DArray(int rows, int columns);
    void free2DArray(int** array, int rows);

    /*输入二维动态数组的行数和列数*/
    int rows, columns;
    scanf("%d,%d", &rows, &columns);

    /*创建二维动态数组*/
    int** array = create2DArray(rows, columns);
    if (array != NULL) {/*若创建成功*/
        /*为二维动态数组元素赋值*/
        assignValuesTo2DArray(array, rows, columns);
        /*屏显二维动态数组元素值*/
        show2DArray(array, rows, columns);
    }
    /*释放二维动态数组的内存空间*/
    free2DArray(array, rows);

    return 0;
}

/*
 * 函数名称：assignValuesTo2DArray
 * 函数功能：为形参arr所指向的二维数组的元素赋值，赋值公式为：
 *           arr[i][j]=i*columns+j+1
 * 形式参数：arr为指向int型二维数组首地址的指针的指针；
 *           rows为二维数组的行数（第一维长度）；
 *           columns为二维数组的列数（第二维长度）。
 * 返 回 值：无
 */
void assignValuesTo2DArray(int** arr, int rows, int columns) {
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            arr[i][j] = i * columns + j + 1;
        }
    }
    // 请编程实现本函数

}

/*
 * 函数名称：show2DArray
 * 函数功能：将形参arr所指向的二维数组的元素向屏幕输出显示，
 *           输出效果为rows行columns列
 * 形式参数：arr为指向int型二维数组首地址的指针的指针；
 *           rows为二维数组的行数（第一维长度）；
 *           columns为二维数组的列数（第二维长度）。
 * 返 回 值：无
 */
void show2DArray(int** arr, int rows, int columns) {
    int i = 0;
    int j = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
           printf("%d",arr[i][j]);
        }
    }
    // 请编程实现本函数

}

/*
 * 函数名称：create2DArray
 * 函数功能：创建rows行columns列的int型动态二维数组
 * 形式参数：rows为二维数组的行数（第一维长度）；
 *           columns为二维数组的列数（第二维长度）。
 * 返 回 值：无
 */
int** create2DArray(int rows, int columns) {
    int **arry= (int**)malloc(rows * sizeof(int));
    int i = 0;
    for (i = 0; i < rows; i++) {
        int** arry = (int**)malloc(columns * sizeof(int));
            if (arry = NULL) {
                exit(1);
            }
    }
    // 请编程实现本函数

}

/*
 * 函数名称：free2DArray
 * 函数功能：释放二维数组内存空间
 * 形式参数：arr为指向int型二维数组首地址的指针的指针；
 *           rows为二维数组的行数（第一维长度）。
 * 返 回 值：无
 */
void free2DArray(int** array, int rows) {
    for (int i = 0; i < rows; i++) { 
        free(array[i]); 
    } 
    free(array);
    // 请编程实现本函数

}