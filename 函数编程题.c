#include <stdio.h>
#include <stdlib.h>
//2
int GC(int n){
	if(n==0||n==1){
		return 1;
	}else {
		return n*GC(n-1);
    }
}
int GL(int n,int m){
	int GC(int n);
	return GC(n)/GC(m)*GC(n-m); 
}
int main(int argc, char *argv[]) {
	int n,m;
	int GC(int n);
	int GL(int n,int m);
	printf("please write down the number of n,m:\n");
	scanf("%d,%d",&n,&m);
	printf("%d",GL(n,m));
	return 0;
}
//3
int MAXTwo(int a,int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}
int MAXThree(int a,int b,int c){
	int MAXTwo(int a,int b);
	if(MAXTwo(a,b)<c){
		return c;
	}else {
		return MAXTwo(a,b);
	} 
}
int main(){
	int MAXThree(int a,int b,int c);
	int a=5,b=7,c=9;
	printf("%d",MAXThree(a,b,c));
	return 0;
}
//4
int WS(int n){
	if(n<=9){
		return 1;
	}else {
		return WS(n/10)+1;
	}
} 
int main(){
	int WS(int n);
	int a=1500;
	printf("%d",WS(a));
	return 0;
}
//5
int add(int a,int b){
	return a+b;
}
int JF(int a,int b){
	return a-b;
}
int CF(int a,int b){
	return a*b;
}
int DV(int a,int b){
	return a/b;
}
int M(int a,int b){     
	if(b==1){
		return a;
	}else {
	return a*M(a,b-1); 
	}
	 
}
int GC(int n){
	if(n==0||n==1){ 
		return 1;
	}else {
		return n*GC(n-1);
    }
}
int YS(int a,int b){
	return a%b;
}
int main() {
	int add(int a,int b);
	int JF(int a,int b);
	int CF(int a,int b);
	int DV(int a,int b);
	int M(int a,int b);
	int GC(int n);
	int YS(int a,int b);
	char c;
	int a,b;
	printf("please write down the operator:\n ");
	scanf("%c",&c);
	if (c=='!'){
		printf("please write down the number :\n");
		scanf("%d",&a);
		printf("%d",GC(a));
	}else if(c=='+'){
		printf("please write down the number of a,b:\n");
		scanf("%d,%d",&a,&b);
		printf("%d",add(a,b));
	}else if(c=='-'){
		printf("please write down the number of a,b:\n");
		scanf("%d,%d",&a,&b);
		printf("%d",JF(a,b));
	}else if(c=='*'){
		printf("please write down the number of a,b:\n");
		scanf("%d,%d",&a,&b);
		printf("%d",CF(a,b));
	}else if(c=='/'){
		printf("please write down the number of a,b:\n");
		scanf("%d,%d",&a,&b);
		printf("%d",DV(a,b));
	}else if (c=='^'){
		printf("please write down the number of a,b:\n");
		scanf("%d,%d",&a,&b);
		printf("%d",M(a,b));
	}else if (c=='%'){
		printf("please write down the number of a,b:\n");
		scanf("%d,%d",&a,&b);
		printf("%d",YS(a,b));
    }
    return 0;
}
//6
int Digitsum(int a){
	if (a<=9){
		return a;
	}else {
		while(a>=10){
			return Digitsum(a/10)+a%10;
		}
	}
} 
int main (){
	int Digitsum(int a);
	int a;
	printf("Please write down the nunmber of a:\n");
	scanf("%d",&a);
	printf("%d",Digitsum(a));
	return 0;
}
//7 
#include <stdio.h>
#include <math.h>

#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001  // 精度要求
#define MAX_ITER 1000   // 最大迭代次数

// 迭代函数 g(x)，用于将方程 x^5 + 5x^4 - 2 = 0 转化
double g(double x) {
    return pow(2 - 5 * pow(x, 4), 1.0 / 5);  // 迭代公式
}

int main() {
    double x0 = -5.0;  // 初始猜测值
    double x1;         // 更新后的值
    int iter = 0;      // 迭代计数

    do {
        x1 = g(x0);
        iter++;
        // 打印每次迭代的结果
        printf("Iteration %d: x = %lf\n", iter, x1);
        
        if (fabs(x1 - x0) < EPSILON) {
            break;  // 满足精度要求，退出循环
        }

        x0 = x1;
    } while (iter < MAX_ITER);

    if (iter == MAX_ITER) {
        printf("未能在指定的迭代次数内收敛。\n");
    } else {
        printf("在第 %d 次迭代后收敛，根为: %lf\n", iter, x1);
    }

    return 0;
}
#include <stdio.h>
#include <math.h>

double F(double x) {
    return pow((2 - 5 * pow(x, 4)), 1.0 / 5);  
}
int main(void) {
    int i, Max;
    double x0, x1, epsilon;
    printf("请输入迭代的初值：");
    scanf("%lf", &x0);
	printf("请输入求解根的精度：");
    scanf("%lf", &epsilon);
    printf("请输入最大迭代次数：");
    scanf("%d", &Max);
	i = 1;
    while (i < Max) {  
        x1 = F(x0);
        printf("\ni = %4d, x1 = %10.6f", i, x1);
        
        if (fabs(x1 - x0) < epsilon) {  
            break;
        }
        x0 = x1;
        i++;
    }
	if (i < Max) {
        printf("\n方程的根 x = %lf\n", x1); 
    } else {
        printf("\n求解方程的迭代次数超过给定的最大迭代次数\n");  
    }

    return 0;
}
//8
#include<math.h>
double F(double x) {
    return x-(pow(x,3)-3*x-1)/(3*pow(x,3)-3);
}
int main(void) {
    int i, Max;
    double x0, x1, epsilon;
    printf("请输入迭代的初值：");
    scanf("%lf", &x0);
	printf("请输入求解根的精度：");
    scanf("%lf", &epsilon);
    printf("请输入最大迭代次数：");
    scanf("%d", &Max);
	i = 1;
    while (i < Max) {  
        x1 = F(x0);
        printf("\ni = %4d, x1 = %10.6f", i, x1);
        
        if (fabs(x1 - x0) < epsilon) {  
            break;
        }
        x0 = x1;
        i++;
    }
	if (i < Max) 
        printf("\n方程的根 x = %lf\n", x1); 
    else
        printf("\n求解方程的迭代次数超过给定的最大迭代次数\n");  
}
//9
#include<math.h>
double F(double x){
	return pow(x,3)+3*x-2;
} 
double G(double x1,double x2) {
    return x2-F(x2)*(x2-x1)/(F(x2)-F(x1));
}

int main(void) {
    int i, Max;
    double x0, x1,x, epsilon;
    printf("请输入迭代的初值1：");
    scanf("%lf", &x0);
    printf("请输入迭代的初值2：");
    scanf("%lf",&x1);
	printf("请输入求解根的精度：");
    scanf("%lf", &epsilon);
    printf("请输入最大迭代次数：");
    scanf("%d", &Max);
	i = 1;
    while (i < Max) {  
        x=G(x0,x1);
        printf("\ni = %4d, x1 = %10.6f", i, x);
        if (fabs(x1 - x0) < epsilon||fabs(F(x))<epsilon) 
            break;
        x0 = x1;
        x1=x;
        i++;
    }
	if (i < Max) 
        printf("\n方程的根 x = %lf\n", x1); 
    else
        printf("\n求解方程的迭代次数超过给定的最大迭代次数\n");  
}
//10
double reliability(double r1,double r2,double r3,double r4){
	return 1-(1-r1*r2)*(1-r3*r4);
}
int main (void){
	double R,R1,R2,R3,R4;
	printf("请输入4个元件的可靠度：");
	scanf("%lf%lf%lf%lf",&R1,&R2,&R3,&R4);
	printf("系统解析可靠性结果：%lf",reliability(R1,R2,R3,R4)); 
	return 0;
}
                                      
    

   

