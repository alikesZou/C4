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
	QElemType *base;//����һ��ָ�룬ʵ��ҲΪ������
	int front;//����һ��ͷ�±ֻ꣬����������г��� 
	int rear; //����һ��β�±ֻ꣬�������������� 
}SqQueue;

//˳����еĳ�ʼ�� 
Status InitQueue(SqQueue &Q){
	Q.base = new QElemType[MAXSIZE];//����һ����СΪ100��sizeof(QElemType)�Ŀռ� 
//	Q.base = (QElemType*)malloc(MAXSIZE*sizeof(QElemType));
	if(!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK; 
}

//��˳����еĳ��Ȳ�����
int QueueLength(SqQueue Q){
	return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
} 
 
//˳����е����
Status EnQueue(SqQueue &Q,QElemType e){
	if((Q.rear + 1) % MAXSIZE == Q.front)
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
} 

//˳����еĳ���
Status DeQueue(SqQueue &Q,QElemType &e){
	if(Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK; 
} 

//ȡ��ͷԪ��
SElemType GetHead(SqQueue Q){
	if(Q.front != Q.rear)
		return Q.base[Q.front];
} 

int main(){
	SqQueue Q;//����һ��˳����� 
	InitQueue(Q);//���ٿռ� 
	//���1��2��3��4��5 
	for(int i = 1;i <= 5;i++)
		EnQueue(Q,i);
	//����ǰ�����������
	for(int i = 0;i < 2;i++){
		int n ;
		DeQueue(Q,n);
		printf("%d\n",n);
	}
	//ȡ����Ԫ�أ���һ�����ӣ�
	printf("����Ԫ��Ϊ%d",GetHead(Q)); 
}
