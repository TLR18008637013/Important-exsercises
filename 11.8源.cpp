/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void change(int n, char k[33]) {
    int i;
    for (i = 0; i < 32; i++) {
        k[31 - i] = (n % 2) + '0';
        n = n / 2;
    }
    k[32] = '\0';
}

int main() {
    char a[99], b[99];
    char c[33]; 
    scanf("%s %s", a, b);
    int a1 = strtol(a, NULL, 2);
    int b1 = strtol(b, NULL, 2);
    change(a1 + b1, c);

    int i = 0;
    while (i < 32 && c[i] == '0') {
        i++;
    }
    if (i == 32) {
        printf("%c", '0');
    }
    else {
        for (; i < 32; i++) {
            printf("%c", c[i]);
        }
    }
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
void change(int n, char k[33]) {
    int i;
    for (i = 0; i < 32; i++) {
        k[31 - i] = (n % 2) + '0';
        n = n / 2;
    }
    k[32] = '\0';
}
int main() {
    char a[100], b[100];
    scanf("%s", a); 
    scanf("%s", b); 

    int a1 = strtol(a, NULL, 2); 
    int b1 = strtol(b, NULL, 2); 

    int sum = a1 + b1; 

    char Result[33];
    change(sum, Result);
    int i = 0;
    while (i < 32 && Result[i] == '0') {
        i++;
    }
    if (i == 32) {
        printf("0");
    }
    else {
        printf("%s", Result + i);
    }

    return 0;
}*/


#/*include<stdio.h>
#include<stdlib.h>
int main() {
    char a[32];
    scanf("%s", a);
    int num = strtol(a, NULL, 8);
    printf("Enter a string(Ocatal digits):The original string:%s\n", a[32]);
    printf("%s is convered to integer number:%d", a[32],num);
    return 0;
}*/
/*#include<stdio.h>
int k(int n) {
    return n * n * n * n;
}
int main() {
    int a;
    scanf("%d", &a);
    if (a >= 3 && a <= 10) {
        printf("%d", k(a) + k(a + 3) + k(a + 6) + k(a + 9) + k(a + 12) + k(a + 15));
    }
    else {
        printf("error");
    }
    return 0;
}*/
/*#include <stdio.h>
int find(int n) {
    int sum = 0;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

int main(void) {
    int m, n;
    scanf("%d,%d", &m, &n);
    if (m < 0 || m>9999 || n > 9999 || n < 0) {
        printf("error");
        return 0;
    }else if (m > n) {
        int temp = m;
        m = n;
        n = temp;
    }
    

    int a[99];
    int k = 0;

    for (int i = m; i <= n; i++) {
        if (find(i)) {
            a[k++] = i;
        }
    }

    for (int i = 0; i < k; i++) {
        if (i != 0) {
            printf(",");
        }
        printf("%d", a[i]);
    }

    return 0;
}*/
/*#include<stdio.h>
int main() {
    float a;
    scanf("%f", &a);
    if (a <= 200000) {
        a = a *  0.03;
    }
    else if (a > 200000 && a <= 500000) {
        a = (a - 200000) * ( 0.25) + 200000 *(0.03);
    }
    else if (a> 500000) {
        a = (a - 500000) * (0.02) + 300000 * (0.25) + 200000 * ( 0.03);
    }
    printf("%.2f", a);
    return 0;
}*/
/*#include<stdio.h>
int main() {
    int n = 0;
    scanf("%d", &n);
    int k = 0;
    scanf("%d", &k);
    int num[20];
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &num[i]);
    }
    int count = 0;
    for (i = 0; i < n; i++) {
        if (num[i] <= k + 30) {
            count++;
        }else{}
    }
    printf("%d", count);
    return 0;
}*/
/*#include<stdio.h>
int find(int n) {
    int i=0;
    if (n < 2) {
        return 0;
    }
    for (i = 2; i < n/2; i++) {
        if (n % i == 0) {
            return 0;
        }else{
            
        }
    }
    return 1;
}
int main() {
    int find(int n);
    int a = 0;
    int b = 0;
    scanf("%d %d", &a,&b);
    int i=0;
    int k[100];
    int m = 0;
    for (i = a; i < a + 100; i++) {
      if(find(i) == 1 ) {
          k[m++] = i;
    }
    }
    for (i = 0; i < b; i++) {
        printf("%d ", k[i]);
    }
    return 0;
}*/
#include <stdio.h>
int main() {
    int n;
    scanf("%d", &n);
    int i, j, k = 0, temp;
    int num[1000];
    for (i = 1; i <= n; i++) {
        if (i % 7 == 0 || i % 10 == 7) {
            num[k++] = i;
        }
    }
    for (i = 0; i < k - 1; i++) {
        for (j = 0; j < k - 1 - i; j++) {
            if (num[j] > num[j + 1]) {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < k; i++) {
        if(i != 0) {
            printf(" ");
            
        }
        printf("%d", num[i]);
    }
    return 0;
}
/*#include <stdio.h>
int three(int n) {
    return n * n * n;
}
int main() {
    int a;
    for (a = 2; a < 1000; a++) { 
        int temp = a; 
        int b[10] = { 0 }; 
        int i = 0;
        while (temp > 0) {
            b[i] = temp % 10;
            temp = temp / 10;
            i++;
        }
        int sum = 0;
        for (int j = 0; j < i; j++) {
            sum += three(b[j]);
        }
        if (sum == a) {
            printf("%d\n", a);
        }
    }
    return 0;
}*/
/*#include <stdio.h>
#include<string.h>
#include<stdlib.h>
int  fun(char* p){
    int n;
  
   n= strtol(p, NULL, 8);
   
}
main(){
    char s[6];
    int i;
    int n;
    printf("Enter a string (Ocatal digits):  "); 
    gets(s);
    if (strlen(s) > 5) {
        printf("Error: String too longer !\n\n");
    }
    for (i = 0; s[i]; i++)
        if (s[i] < '0' || s[i]>'7')
        {
            printf("Error: %c not is ocatal digits!\n\n", s[i]);
        }
    printf("The original string:  "); 
    puts(s);
    n = fun(s);
    printf("\n%s is convered to integer number: %d\n\n", s, n);
}*/