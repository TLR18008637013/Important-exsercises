/*从键盘任意输入5个小写英文字母，将其加密后输出。加密规则是：用原来英文字母后面的第4个字母代替原来的字母。例如，小写字母a后面第4个字母是e，e代替a。再如，大写字母w后面第4个字母是a，a代替w。请编程实现上述加密方案。
输入说明：在一行内连续输入5个小写英文字母原文
输出说明：在一行内连续输出5个小写英文字母密文
样例输入：china
样例输出：glmre*/
/*#include <stdio.h>
#include <stdlib.h>
int main() {
    char a, b, c, d, e;
    printf("从键盘任意输入5个小写英文字母:");
    scanf(" %c %c %c %c %c", &a, &b, &c, &d, &e);
    a = (a - 'a' + 4) % 26 + 'a';//把输入的数减去a对应的ASCLL码再加4看是否超过26，超过26重新从a开始。
    b = (b - 'a' + 4) % 26 + 'a';
    c = (c - 'a' + 4) % 26 + 'a';
    d = (d - 'a' + 4) % 26 + 'a';
    e = (e - 'a' + 4) % 26 + 'a';
    printf("输出的密文是：%c%c%c%c%c\n", a, b, c, d, e);
    return 0;
} */  
//十六进制数是在程序设计时经常要使用到的一种整数的表示方式。它有0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F共16个符号，分别表示十进制数的0至15。十六进制的计数方法是满16进1，所以十进制数16在十六进制中是10，而十进制的17在十六进制中是11，以此类推，十进制的30在十六进制中是1E。给出一个非负整数，将它表示成十六进制的形式。  
/*#include <stdio.h>
#include<stdlib.h>
int main(){
    unsigned int a;//无符号整型数
    scanf("%u", &a);// %u表示为无符号整型数
    printf("%X\n", a);//  %X表示16进制
    return 0;
}*/
//现有一个非负的十进制整数n，请将它的各个十进制位上的数字累加求和，以得到一个新的十进制数，然后对新数进行同样的操作，直到最后的结果为一个个位数。请返回这个结果。
//输入258输出6
/*#include <stdio.h>
#include<stdlib.h>
int X(int n) {
    if (n == 0){
        return 0;
        }else {
        return 1 + (n - 1) % 9;//***如何把各个位数都加起来
        }
    }
int main(){
    int a;
    scanf("%d", &a);
    int b=X(a);
    printf("%d\n",b);
    return 0;}*/
#include<stdio.h>
#include<stdlib.h>
/*int main(){
    int a;
    scanf("%d",&a);
    if(a<=9){
        printf("%d",a);
    }else{
    while(a<10){
        a=(a/10)+(a%10);
    }
    printf("%d",a);    
    }
    return 0;
}*/
int main(){
    printf("Hallo world");
    return 0;
}

