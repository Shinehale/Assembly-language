#include<stdio.h>
#include<stdlib.h>

#ifndef BASE
#define BASE
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int bool;
#endif

typedef int ElemType;
typedef struct NodeType{
	ElemType data;
	struct NodeType *next;
}QNode, *QPtr;
typedef struct{
	QPtr rear;
}Queue;

Status InitQueue(Queue *pQ) {
	QNode *newNode;
	newNode = (QNode *)malloc(sizeof(QNode));
	if (!newNode) exit(OVERFLOW);
	newNode->next = newNode; 
	pQ->rear = newNode; 
	return OK;
}

Status EnQueue(Queue *pQ, ElemType e) {
	QNode *newNode;
	newNode = (QNode *)malloc(sizeof(QNode));
	if (!newNode) exit(OVERFLOW);
	newNode->data = e;
	newNode->next = pQ->rear->next;
	pQ->rear->next = newNode;
	pQ->rear = newNode;
	return OK;
}

Status DeQueue(Queue *pQ,ElemType *e) {
	QNode *tmp, *top;
	
	if (pQ->rear->next==pQ->rear) return ERROR; //空
	top = pQ->rear->next; 
	tmp = top->next; 
	*e = tmp->data; 
	top->next = tmp->next;
	free(tmp);
	if (top->next==top) pQ->rear=top;
	return OK;
}

Status Debug(Queue Q, void (*Visit)(ElemType e)) {
	QNode *top,*tmp;
	printf("----------------\n");
	printf("rear指向：%d\n", Q.rear->data);
	top = Q.rear->next;
	tmp = top;
	do {
		Visit(tmp->data);
		tmp=tmp->next;
	}while(tmp!=top);
	printf("\n----------------\n");
	return OK;
}

void visit(ElemType e) {
	printf("%d\t", e);
}

int main() {
	int c;
	int tmp;
	Queue Q;
	InitQueue(&Q);
	Debug(Q, &visit);
	while (1) {
		scanf("%d", &c);
		switch(c) {
		case 1:scanf("%d",&tmp);EnQueue(&Q, tmp);Debug(Q,&visit);break;
		case 2:DeQueue(&Q, &tmp);printf("抛出%d\n", tmp);Debug(Q,&visit);break;
		}
	}
	return 0;
}
