/*
@Filename: hrbeu-ai-kmeans.c
@Author: Ju Chengdong
@Description: Application of K-Means clustering algorithm.
@Version: 1.0
@Date: 2024-11-18
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 6 //坐标点个数 
#define k 2 //k个类簇 
/*定义顶点坐标结构体*/
typedef struct{
	float x;//横坐标
	float y;//纵坐标
}Point;
Point point[N]={{0,0},{1,2},{3,1},{8,8},{9,10},{10,7}};//6个坐标点
int center[N];//保存每个点属于k个簇中的哪一个簇
Point mean[k];//保存k个簇中心（质心）的坐标

/*函数声明*/
float getDistance(Point point1, Point point2);//计算欧式距离
void cluster();//对N个点聚类
float getE();//计算平方误差函数
void getMean(int center[N]);//计算k个簇中心（质心）坐标
void output();//输出k各簇中心（质心）坐标

/*int main(void){
	//重新为N个坐标点键盘输入赋值
	for(int i=0;i<N;i++){
		scanf("%f%f",&point[i].x,&point[i].y);
	}
	//初始化k个中心点，可采用随机生成的方法。
	//此处为简单起见，直接选定前k个顶点为中心点
	for(int i=0;i<k;i++){
		mean[i].x=point[i].x;
		mean[i].y=point[i].y;
	}
	int number = 0;//聚类次数，初始值为0 
	float temp1,temp2=0;
	while(1){
		if(number>=1){
			getMean(center);//对上次聚类结果，重新计算聚类中心
		}
		output();
		cluster();
		number++;
		temp1=getE();//对上次聚类结果计算误差平方和
		printf("第%d次聚类误差为:%.2f\n\n", number,temp1);
		if(fabs(temp1-temp2)>0.5){
			temp2=temp1;
		}
		else{
			break;
		}
	}
	printf("聚类次数共计:%d次\n",number);
	return 0;
}*/
//函数功能：计算欧式距离
float getDistance(Point point1,Point point2){
	/*******************start encoding*******************/
	//请编写本函数，计算两点的欧氏距离，并返回该距离 
	double distance=0;
    distance=sqrt(pow(point1.x-point2.x,2)+pow(point1.y-point2.y,2));
    return distance;

    
	/*******************end encoding*******************/
}
//函数功能：对N个点聚类
void cluster(){
	float distance[N][k];
	//循环处理每个点属于哪个簇 
	for (int i=0;i<N;i++){
		//计算顶点i与各个质心的距离 
		for (int j=0;j<k;j++){
			distance[i][j]=getDistance(point[i],mean[j]);
		}
		//计算与顶点i距离最小的质心后，将顶点i归类 
		float min=distance[i][0];
		center[i]=0; 
		for (int j=1;j<k;j++){
			if (distance[i][j]<min){
				min=distance[i][j];
				center[i]=j;
			}
		}
		printf("顶点(%.2f,%.2f)属于簇%d\n",	point[i].x,point[i].y,center[i]+1);
	}
}
//函数功能：计算平方误差函数
float getE(){
	float cnt=0, sum=0;
	for (int i=0;i<N;i++){
		for (int j=0;j<k;j++){
			if (center[i]==j){
				cnt=getDistance(point[i], mean[j]);
			}
		}
		sum+=cnt;
	}
	return sum;
}
//函数功能：计算k个簇中心（质心）坐标
void getMean(int center[N]){
	Point sum;
	int count;
	for (int i=0;i<k;i++){
		sum.x=0.0;
		sum.y=0.0;
		count=0;
		for (int j=0;j<N;j++){
			if (center[j]==i){
				sum.x+=point[j].x;
				sum.y+=point[j].y;
				count++;
			}
		}
		mean[i].x=sum.x/count;
		mean[i].y=sum.y/count;
	}
}
//函数功能：输出k各簇中心（质心）坐标
void output(){
	for (int i = 0; i < k; i++){
		printf("第%d个簇中心坐标为:(%.2f,%.2f)\n",i+1,mean[i].x,mean[i].y);
	}
}
/*
@Filename: 
@Author: Ju Chengdong
@Version: 1.0
@Date: 2024-11-18
@Description: Multi threaded parallel computation of sum of array elements.
@Other instructions: In addition to this program, it is also necessary to write a script program for Online Judge.
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*数组分割信息结构体：用于记录每个线程所负责的某个子数组的起止下标等信息*/
typedef struct {
	int *array;//数组名（数组的起始地址）
	int start;//子数组的起始下标
	int end;//子数组的截止下标
	//注：子数组的有效起止下标为：从start到end-1。
} ArraySplit;
double totalSum=0;//所有数组元素的总和

/*函数功能：计算子数组元素的和（从start到end-1的和）。*/
double sumArray(int *array, int start, int end) {
	double sum = 0;
	for (int i = start; i < end; i++) {
		//sum += array[i];
		sum += *(array+i);//与上条语句等价
	}
	return sum;
}

/*函数功能：线程执行函数。即：每个线程都要执行的函数*/
void *computeSum(void *args){
	ArraySplit *split = (ArraySplit *)args;
	double sum = sumArray(split->array, split->start, split->end);
	totalSum += sum;
	//printf("\nThread %lu computes sum: %d", pthread_self(), sum);
    free(split); //释放数组分割信息结构体的内存
	return NULL;
}

// 主函数
/*int main(void) {
	int arraySize = 10;//数组长度
	int pthreadNum = 4; //线程个数（建议为数组长度的因子）
	scanf("%d%d",&arraySize,&pthreadNum);//为数组长度和线程个数重新赋值
	
	int *array=(int*)malloc(sizeof(int)*arraySize);//动态创建数组array
	for(int i=0;i<arraySize;i++){
		//scanf("%d",&array[i]);
		array[i]=(i+1);
	}
	pthread_t threads[pthreadNum];//pthreadNum个线程
	for (int i = 0; i < pthreadNum; i++) {
		//（1）决定每个线程应负责哪个子数组
		int start = i * (arraySize / pthreadNum);
		//int end = (i + 1) * (arraySize / pthreadNum);
		int end = start + (arraySize / pthreadNum);//与上条等价
		if(i == pthreadNum-1){
			注：本例简单的将分割后的剩余元素都划分到最后一个子数组
			end=arraySize;
		}
		//printf("%d,%d,%d\n",i,start,end);//用于查看数组集合的划分是否准确？以确保既全无遗漏，又相互排斥
		//（2）为每个线程创建数组分割信息结构体指针变量
		ArraySplit *split = malloc(sizeof(ArraySplit));
		split->array = array;
		split->start = start;
		split->end = end;
		//（3）创建每个线程
		pthread_create(&threads[i], NULL, computeSum, (void *)split);
	}
	for(int i=0;i<pthreadNum;i++){
		//（4）等待所有线程完成
		
		//pthread_join()函数需要两个参数，请填空完善下行代码。 
		pthread_join(threads[i], NULL);

		
	}
	printf("%.0f", totalSum);
	free(array);//释放动态数组array
	return 0;
}*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>
#define STU_NUM 2
/*定义学生结构体类型*/
typedef struct student{
	int id;
	char name[50];
	int age;
}STU;
/*定义数据库文件名字串常量*/
const char* DB_FILE = "example.db";	//数据库文件名

/*声明函数*/
void input(int length, STU arr[]);//为学生结构体数组元素赋值 
sqlite3* initDatabase();//初始化数据库 
void createTable(sqlite3* db);//创建表 
void insertData(sqlite3* db, int id, const char* name, int age);//新增数据 
void selectData(sqlite3* db);//查询数据 
void updateData(sqlite3* db, int id, const char* name, int age);//更新数据 
void deleteData(sqlite3* db, int id);//删除数据 
void closeDatabase(sqlite3* db);//关闭数据库 

int main(){
	//(1)定义学生结构体数组并赋值 
	struct student stu[STU_NUM];
	input(STU_NUM, stu);
	//(2)初始化数据库 
    sqlite3* db = initDatabase();
    if(db==NULL){/*如果创建数据库失败*/
    	return -1;
    	//exit(0);
    }
	//(3)创建数据表 
	createTable(db);
	//(4)新增数据
	for(int i=0;i<STU_NUM;i++){
		insertData(db,stu[i].id,stu[i].name,stu[i].age);
	}
	//(5)查询数据 
	selectData(db);
		
	//(6)更新数据 
	//updateData(db, 1, "妮妮", 11);
	//selectData(db);
	//(7)删除数据 
	//deleteData(db, 3);
	//selectData(db);
	
	//(8)关闭数据库 
	closeDatabase(db);
   return 0;
}
/*函数功能：为学生结构体数组元素赋值*/
void input(int length, STU arr[]){
	for(int i=0;i<length;i++){
		scanf("%d",&arr[i].id);
        scanf("%s",arr[i].name);
		// fgets(arr[i].name,50,stdin); //使用fgets需要将最后字符置为'\0'作为结束符
        // arr[i].name[strcspn(arr[i].name, "\n")] = 0; 
		scanf("%d",&arr[i].age);;
	}
}

/*函数功能：初始化数据库连接*/
sqlite3* initDatabase(){
	sqlite3* db;
	int rc = sqlite3_open(DB_FILE, &db);
	if (rc != SQLITE_OK){
		fprintf(stderr, "无法打开数据库: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return NULL;
    }
	return db;
}
/*函数功能：关闭数据库连接，并删除数据库文件*/
void closeDatabase(sqlite3* db){
	if (db){
		//关闭数据库连接 
		sqlite3_close(db);
		
		//删除数据库文件
		/*
		注1：删除的目的仅仅是为了方便实验。
		注2：确保在调用remove()函数之前，SQLite已经关闭了所有对数据库文件的操作，
		否则可能会导致删除失败。
		*/
    	if (remove(DB_FILE) != 0) {
        	perror("Error deleting database file");
    	}
	}
}

/*函数功能：创建表*/
void createTable(sqlite3* db){
	char* errMsg;
	const char* createSql = "create table if not exists students (id int primary key, name text, age int);";
	int rc = sqlite3_exec(db, createSql, NULL, 0, &errMsg);
	
	if (rc != SQLITE_OK){
		fprintf(stderr, "无法创建表: %s\n", errMsg);
		sqlite3_free(errMsg);
	}
	else{
		printf("表创建成功\n");
	}
	
}

/*函数功能：插入数据*/
void insertData(sqlite3* db, int id, const char* name, int age){
    static int i=1;
	char insertSql[100];
	snprintf(insertSql, sizeof(insertSql), 
		"INSERT INTO students (id, name, age) VALUES (%d, '%s', %d);", id, name, age);
	char* errMsg;
	int rc = sqlite3_exec(db, insertSql, NULL, 0, &errMsg);
	
	if (rc != SQLITE_OK){
		//fprintf(stderr, "无法插入数据: %s\n", errMsg);
		//sqlite3_free(errMsg);
		printf("无法插入数据\n");
	}
	else{
		printf("数据插入成功%d\n",i++);
	}
}

/*函数功能：更新数据*/
void updateData(sqlite3* db, int id, const char* name, int age){
	char updateSql[100];
	snprintf(updateSql, sizeof(updateSql), 
		"UPDATE students SET name = '%s', age = %d WHERE id = %d;", name, age, id);
	char* errMsg;
	int rc = sqlite3_exec(db, updateSql, NULL, 0, &errMsg);
	if (rc != SQLITE_OK){
		fprintf(stderr, "无法更新数据: %s\n", errMsg);
		sqlite3_free(errMsg);
	}
	else{
		printf("数据更新成功\n");
	}
}

/*函数功能：删除数据*/
void deleteData(sqlite3* db, int id){
	char deleteSql[100];
	snprintf(deleteSql, sizeof(deleteSql), 
		"DELETE FROM students WHERE id = %d;", id);
	char* errMsg;
	int rc = sqlite3_exec(db, deleteSql, NULL, 0, &errMsg);
	if (rc != SQLITE_OK){
		fprintf(stderr, "无法删除数据: %s\n", errMsg);
		sqlite3_free(errMsg);
	}
	else{
		printf("数据删除成功\n");
	}
}
/*函数功能：查询数据*/
void selectData(sqlite3* db){
	int selectCallback(void* data, int argc, char** argv, char** azColName);
	
	char* errMsg;
	const char* selectSql = "SELECT * FROM students;";
    /**********Start encoding**********/
	//下面这条语句中的sqlite3_exec()函数调用需要5个参数，请填空完善。
	int rc = sqlite3_exec( db, selectSql, selectCallback, 0, &errMsg );
    
	/**********End encoding**********/
	if (rc != SQLITE_OK){
		//fprintf(stderr, "无法查询数据: %s\n", errMsg);
		//sqlite3_free(errMsg);
		return ;
	}
}

/*函数功能：回调函数，用于执行查询sql语句后的结果处理
形参1：void* data：通常用于在回调函数中传递上下文信息。
形参2：int argc：结果集中返回的列数。
形参3：char** argv：结果集中每一行的值所组成的数组。
形参4：char** azColName：结果集中每一列的列名所组成的数组。 
*/
int selectCallback(void* data, int argc, char** argv, char** azColName){
	int i;
	for (i = 0; i < argc; i++){
		printf("%s=%s;", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}
