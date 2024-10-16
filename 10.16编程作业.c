#include <stdio.h>
#include <stdlib.h>
/*int main() {
	int a;
	scanf("%d",&a);
	if (a%2==0||a<0){
		printf("%d",a*a);}
		else{
			printf("%d",a/2);
		}
		

	return 0;
}*/
/*int main(){
	float a;
	scanf("%f",&a);
	if(a<=500){
		printf("%.2f",a);
	}
	else if(a>500||a<=1000){
		printf("%.2f",9*a/10);
		}else if(a>1000){
			printf("%.2f",8*a/10);
			
		}
	return 0;
}*/
/*int comparetwoa(int a,int b){
	if(a>b){
		return a;
		}
		else{
			return b;
		}
	}
int comparetwoi(int a,int b){
	if(a>b){
		return b;
		}
		else{
			return a;
		}
	}
int main(void){
	int comparetwoa(int a,int b);
	int comparetwoi(int a,int b);
	int a,b,c,d;
	scanf("%d,%d,%d,%d",&a,&b,&c,&d);
	printf("%d",comparetwoi(a,b)+comparetwoa(c,d));
	return 0;
}*/
/*int main(void){
	int a;
	float b;
	scanf("%d",&a);
	if(a<=200){
		b=8*a/10;
	}else if(a>200&&a<=300){
		b=160+(a-200)*9/10;
    }else if(a>300){
    	b=250+(a-300);  
	}
	if(b<100){
		b=100;
	}else if(b>400){
		b=b*1.15;
	}
	printf("%.2f",b);
	return 0;
	} */
#include <stdio.h>
int main(void) {
    int a;
    int b;
    scanf("%d", &a);
    if (a <= 19) {
        b = a;
        switch (b) {
            case 1: printf("one\n"); break;
            case 2: printf("two\n"); break;
            case 3: printf("three\n"); break;
            case 4: printf("four\n"); break;
            case 5: printf("five\n"); break;
            case 6: printf("six\n"); break;
            case 7: printf("seven\n"); break;
            case 8: printf("eight\n"); break;
            case 9: printf("nine\n"); break;
            case 10: printf("ten\n"); break;
            case 11: printf("eleven\n"); break;
            case 12: printf("twelve\n"); break; 
            case 13: printf("thirteen\n"); break; 
            case 14: printf("fourteen\n"); break;
            case 15: printf("fifteen\n"); break;
            case 16: printf("sixteen\n"); break;
            case 17: printf("seventeen\n"); break;
            case 18: printf("eighteen\n"); break;
            case 19: printf("nineteen\n"); break;
        }
    } else if (a < 100) { 
        b = a / 10;
        switch (b) {
            case 2: printf("twenty-"); break;
            case 3: printf("thirty-"); break;
            case 4: printf("forty-"); break;
            case 5: printf("fifty-"); break;
            case 6: printf("sixty-"); break;
            case 7: printf("seventy-"); break; 
            case 8: printf("eighty-"); break;
            case 9: printf("ninety-"); break; 
        }
        b = a % 10; 
        switch (b) {
            case 1: printf("one\n"); break;
            case 2: printf("two\n"); break;
            case 3: printf("three\n"); break;
            case 4: printf("four\n"); break;
            case 5: printf("five\n"); break;
            case 6: printf("six\n"); break;
            case 7: printf("seven\n"); break;
            case 8: printf("eight\n"); break;
            case 9: printf("nine\n"); break;
            default: printf("\n"); 
        }
    } 
    return 0;
}

/*int main(void){
	int i,a=1;
	for(i=0;i<10;i++){
		a=(a+1)*2;
	}
	printf("%d",a);
	return 0;
}*/
/*int main(void){
	int a[8];
	int i;
	int sum=0;
    scanf("%d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7]);
    for(i=0;i<8;i++){
    	if(a[i]%2==0){
    	sum=sum+a[i];
	    }else{
		sum=sum;
	    }
	}
    printf("%d",sum);
    return 0;
	}*/

