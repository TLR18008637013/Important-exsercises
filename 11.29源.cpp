/*#include <stdio.h>
#include <stdlib.h>
typedef struct Link {
	int data;
	struct Link* next;
}link;
int main(){
	link* Head = NULL;
	link* temp = (link*)malloc(sizeof(link));
	temp->data = 1;
	temp->next = NULL;
	Head = temp;
	for (int i = 2; i < 5; i++) {
		link* a = (link*)malloc(sizeof(link));
		a->data = i;
		a->next = NULL;
		temp->next = a;
		temp = temp->next;
	}
	while (Head) {
		printf("%d ", Head->data);
		Head = Head->next;
	}
	return 0;
	
}*/
/*
@Filename: ex704.c
@Author: Ju Chengdong
@Version: 1.0
@Date: 2021-03-18
@Description: Reverse Single Linked List
*/
#include <stdio.h>
#include <stdlib.h>
struct node {
	int value;
	struct node* next;
};
/*int main() {
	struct node* createList(int codeNum);
	struct node* reverse(struct node* pHead);
	void display(struct node* pHead);
	int num;
	scanf("%d", &num);
	struct node* pHead = createList(num);
	printf("\n");
	display(pHead);
	pHead = reverse(pHead);
	printf("\n");
	display(pHead);
	return 0;
}*/

/*
 * 函数名称：createList
 * 函数功能：使用头插法创建单链表，创建每个结点的同时为其value字段从键盘输入赋值
 * 形式参数：int型，链表结点个数
 * 返 回 值：返回struct node型指针，为单链表头结点
 */
struct node* createList(int codeNum) {
	/* 声明函数 */
	struct node* createNode();
	/* 声明一个头结点 */
	struct node* pHead = NULL;
	/*
	 * 生成单链表。有两种链表：空头链表和无空头链表
	 * 下面创建的是无空头链表
	 */
	int i;
	for (i = 1; i <= codeNum; i++) {
		/* 创建新结点 */
		struct node* newNode = createNode();
		/*
		 * 将新结点插入链表中，常用方式有：头插法、尾插法等。
		 * 头插法算法简单，但结点次序与输入数据的顺序不一致。
		 * 若希望两者次序一致，可采用尾插法。
		 *
		 * 以下采用头插法
		 */
		newNode->next = pHead; /*将newNode指向上一步的头结点*/
		pHead = newNode; /*将newNode作为新的头结点*/
	}
	return pHead;
}

/*
 * 函数名称：createNode
 * 函数功能：创建一个新结点
 * 形式参数：无
 * 返 回 值：无
 */
struct node* createNode() {
	// 动态申请内存，创建新结点 
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	if (newNode != NULL) {
		// 为新结点的各字段赋值
		scanf("%d", &newNode->value);
		newNode->next = NULL; // 好习惯，不要让指针处于未赋值状态
	}
	return newNode;
}

/*
 * 函数名称：display
 * 函数功能：输出单链表所有结点的value字段值
 * 输出格式：在一行内输出所有结点的value字段值，用空格分隔
 * 形式参数：struct node型指针，为单链表头结点
 * 返 回 值：无
 */
void display(struct node* pHead) {
	while (pHead) {
		printf("%d ", pHead->value);
		pHead = pHead->next;
	}
	// 请编程实现本函数 

}

/*
 * 函数名称：reverse
 * 函数功能：反转单链表
 * 算法特点：可采用迭代算法、递归算法、尾递归算法等算法实现
 * 形式参数：struct node型指针，为单链表头结点
 * 返 回 值：返回struct node型指针，为反转后的单链表头结点
 */
struct node* reverse(struct node* pHead) {
	if (pHead == NULL || pHead->next == NULL) {
		return pHead;
	}
	struct node* prev = NULL;
	struct node* current = pHead;
	struct node* next = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return prev;
	// 请编程实现本函数 
}

#include <stdio.h>
#include<string.h>
/*int main() {
	char* filename = "calcCharNum.txt";
	char s[200], p[200];
	//gets(s);
	fgets(s, 200, stdin);
	FILE* f = fopen(filename, "w");
	if (f == NULL) {
		return 1;
	}
	
	fputs(s, f);
	

	
	fclose(f);

	f = fopen(filename, "r");
	if (f == NULL) {
		return 1;
	}
	
	fgets(p, 200, f);

	
	fclose(f);
	fputs(p, stdout);
	return 0;
}*/



#include<stdio.h>  
int fun(char* source, char* target) {
	FILE* fs, * ft;
	char ch;
	if ((fs = fopen(source, "r")) == NULL)
		return 0;
	if ((ft = fopen(target, "w")) == NULL)
		return 0;
	printf("The data in file :\n");
	ch = fgetc(fs);

	while (!feof(fs)) {
		/**********start coding**********/
		//请在此处编码，完成如下功能：
		//（1）将ch输出到显示器
		//（2）将ch写入到ft所指文件中
		//（3）从fs所指文件中再次读入一个字符，并赋值为ch
		printf("%c", ch);
		fputc(ch, ft);
		ch = fgetc(fs);





		/**********start coding**********/
	}
	fclose(fs);
	fclose(ft);
	printf("\n");
	return 1;
}
/*void main() {
	char sfname[20] = "myfile", tfname[20] = "myfile2", text[100];
	char c;
	FILE* myf;
	myf = fopen(sfname, "w");
	gets(text);
	fputs(text, myf);
	fclose(myf);
	if (fun(sfname, tfname))
		printf("succed!");
	else
		printf("Fail!");
}*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void WriteText(FILE*);
void ReadText(FILE*);
void main() {
	FILE* fp;
	if ((fp = fopen("myfile4.txt", "w")) == NULL) {
		printf("open fail!!\n");
		exit(0);
	}
	WriteText(fp);
	fclose(fp);
	if ((fp = fopen("myfile4.txt", "r")) == NULL) {
		printf("open fail!!\n");
		exit(0);
	}
	ReadText(fp);
	fclose(fp);
}
/**********found**********/
void WriteText(FILE *fw) {
	char str[81];
	printf("\nEnter string with -1 to end :\n");
	gets(str);
	while (strcmp(str, "-1") != 0) {
		/**********found*********/
		fputs(str, fw);
		fputs("\n", fw);
		gets(str);
	}
}
void ReadText(FILE* fr) {
	char str[81];
	printf("Read file and output to screen :\n");
	fgets(str, 81, fr);
	while (!feof(fr)) {
		/**********found**********/
		printf("%s",str);
		fgets(str, 81, fr);
	}
}
