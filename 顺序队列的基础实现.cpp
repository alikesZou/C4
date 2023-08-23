#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
#define MAXSIZE 100
#define OVERFLOW -2
typedef int QElemType;
typedef int Status;
typedef int SElemType;

typedef struct SqQueue{
	QElemType *base;//定义一个指针，实际也为数组名
	int front;//定义一个头下标，只能在这里进行出队 
	int rear; //定义一个尾下标，只能在这里进行入队 
}SqQueue;

//顺序队列的初始化 
Status InitQueue(SqQueue &Q){
	Q.base = new QElemType[MAXSIZE];//开辟一个大小为100个sizeof(QElemType)的空间 
//	Q.base = (QElemType*)malloc(MAXSIZE*sizeof(QElemType));
	if(!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK; 
}

//求顺序队列的长度并返回
int QueueLength(SqQueue Q){
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
} 
 
//顺序队列的入队
Status EnQueue(SqQueue &Q,QElemType e){
	if((Q.rear + 1) % MAXSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
} 

//顺序队列的出队
Status DeQueue(SqQueue &Q,QElemType &e){
	if(Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK; 
} 

//取对头元素
SElemType GetHead(SqQueue Q){
	if(Q.front != Q.rear)
		return Q.base[Q.front];
} 

int main(){
	SqQueue Q;//定义一个顺序队列 
	InitQueue(Q);//开辟空间 
	//入队1，2，3，4，5 
	for(int i = 1;i <= 5;i++)
		EnQueue(Q,i);
	//出队前两个，并输出
	for(int i = 0;i < 2;i++){
		int n ;
		DeQueue(Q,n);
		printf("%d\n",n);
	}
	//取队首元素（下一个出队）
	printf("队首元素为%d",GetHead(Q)); 
}
