#define ­_CRT_SECURE_NO_WARNINGS 1
//
/*#include<stdio.h>
int main() {
	int a[10];
	int i=0;
	scanf("%d %d %d %d %d %d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4], &a[5], &a[6], &a[7], &a[8], &a[9]);
	int sum=0;
	for (i = 0; i < 9; i++) {
		sum = sum + a[i];
	}
	a[9] = sum / 9;
	printf("%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
	return 0;
}*/
//
/*#include <stdio.h>
int main() {
    int a[5];
    int b[5];
    int c[10];
    int i;
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < 5; i++) {
        scanf("%d", &b[i]);
    }
    for (i = 0; i < 5; i++) {
        c[i] = a[i];
    }
    for (i = 0; i < 5; i++) {
        c[i + 5] = b[i];
    }
    
    for (i = 0; i < 10; i++) {
        if (i != 0) {
            printf(",");
        }else{}
        printf("%d", c[i]);
    }
    printf("\n");
    for (i = 0; i < 9; i++) {
        for (int j = 0; j < 9 - i; j++) {
            if (c[j] >c[j + 1]) {
                int temp = c[j];
                c[j] = c[j + 1];
                c[j + 1] = temp;
            }
        }
    }
    for (i = 0; i < 10; i++) {
        if(i != 0) {
            printf(",");
        }else{}
        printf("%d", c[i]);
    }
    return 0;
}
*/
//
/*#include <stdio.h>
#include <string.h>
int main() {
    char s1[256], s2[256];  
    int hashTable[256] = { 0 };
    fgets(s1, 256, stdin);
    fgets(s2, 256, stdin);
    s1[strcspn(s1, "\n")] = 0;
    s2[strcspn(s2, "\n")] = 0;
    for (int i = 0; s2[i] != '\0'; i++) {
        hashTable[(unsigned char)s2[i]] = 1;
    }
    int k = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        if (!hashTable[(unsigned char)s1[i]]) {
            s1[k++] = s1[i];
        }
    }
    s1[k] = '\0';  
    printf("%s", s1);
    return 0;
}*/
//
/*#include<stdio.h>
#include<string.h>
int main() {
    char s1[101];
    char s2[101];
    fgets(s1, sizeof(s1), stdin);
    fgets(s2, sizeof(s2), stdin);
    s1[strcspn(s1, "\n")] = '\0';
    s2[strcspn(s2, "\n")] = '\0';
    if (strlen(s2) >= strlen(s1)) {
        printf("-1");
        return 0;
    }
    int i = 1;
    int position = -1;
    for (i = 0; i <= strlen(s1) - strlen(s2); i++) {
        if (strncmp(&s1[i], s2, strlen(s2)) == 0) {
            position = i + 1;
            break;
        }else{}
    }
    printf("%d", position);  
    return 0;
}*/
//
#include <stdio.h>

int main() {
    int n;
    do {
       scanf("%d", &n);
    } while (n < 3 || n > 20);

    int a[20][20]; 
    int value = 1;     
    int left = 0, right = n - 1;
    int top = 0, bottom = n - 1; 
    while (value <= n * n) {
        for (int i = right; i >= left; i--) {
            a[top][i] = value++;
        }
        top++;
        for (int i = top; i <= bottom; i++) {
            a[i][left] = value++;
        }
        left++;
        for (int i = left; i <= right; i++) {
            a[bottom][i] = value++;
        }
        bottom--;
        for (int i = bottom; i >= top; i--) {
            a[i][right] = value++;
        }
        right--;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%4d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
