#define ­_CRT_SECURE_NO_WARNINGS 1
//1
/*#include <stdio.h>
float sum(int n) {
    float a = 2.0f;
    int i;
    float sum = a;
for ( i = 1; i <n; i++) {
        a = 1 + 1 / a;
        sum += a;
    }
return sum;
}
int main() {
    int n;
    scanf("%d", &n);
    float result =sum(n);
    printf("%.2f\n", result);
    return 0;
}
*/
//6
/*#include<stdio.h>
int main() {
    int year, leap;
    scanf("%d",& year);
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                printf("%d is a leap year", year);
            }
            else {
                printf("%d is not a leap year", year);
            }
        }
        else {
            printf("%d is a leap year", year);

        }

    }
    else {
        printf("%d is not a leap year", year);
    }
    return 0;
}*/
//2
//5
/*#include<stdio.h>
float  P(int n,int x) {
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return x;
    }
    else {
        return ((2 * n - 1) * x * P(n - 1, x) - (n - 1) * P(n - 2, x)) / n;
    }
}
int main() {
    float  P(int n, int x);
    int n, x;
    scanf("%d,%d", &n,&x);
    if (n < 0) {
        printf("error");
    }
    else if(n>=0){
        printf("%.2f", P(n, x));
    }
    return 0;
}*/
//4
/*#include<stdio.h>
#include<stdlib.h>
double F(int a, double b, int c) {
    int i;
    double sum=0;
    for (i = 1; i <= c; i++) {
        sum = (a + sum) * (1 + b / 12);
    }
    return sum;
}

int main() {
   double F(int a, double b, int c);
    int a;
   double b;
    int c;
    scanf("%d,%lf,%d", &a, &b, &c);
    printf("%.2f", F(a, b, c));
    return 0;
}*/
//3
/*#include <stdio.h>
int X(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;  
}

int main() {
    int m, n;
    scanf("%d,%d", &m, &n);
    for (int i = m; i <= n - 2; i++) {
        if (X(i) && X(i + 2)) {
            printf("%d,%d\n", i, i + 2);
        }
    }
    return 0;
}
*/
//
#include <stdio.h>
int A(int num) {
    int a = num;
    int b = 0;
    while (num > 0) {
        b = b * 10 + num % 10;
        num /= 10;
    }
    return a == b;
}
void B(int n) {
    int count = 0;
    for (int i = 0; i <= n; i++) {
        if (A(i)) {
            printf("%d", i);
            if (count >=0) {
                printf(","); 
            }
            
            count++;
            if (count == 10) {
                printf("\n");
                count = 0;
            }
        }
    }
   
}

int main() {
    int n;
    
    scanf("%d", &n);
   
    B(n);

    return 0;
}
