#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
} Node;
typedef struct Linklist{
	Node *next;
} Linklist;
void init(Linklist *Link,int a[]){
	Link->next=NULL;
	for (int i=10;i>0;i--){
		Node * newNode=(Node*)malloc(sizeof(Node));
		newNode->data=a[i-1];
		newNode->next=Link->next;
		Link->next=newNode;	
	}
}
void merge(Linklist *A,Linklist *B,Linklist *C){
	Node *p1=A->next,*p2=B->next,*p=(Node*)malloc(sizeof(Node));
	p->data=0;p->next=NULL;C->next=p;
	while (p1&&p2){
		Node *newNode=(Node*)malloc(sizeof(Node));
		newNode->next=NULL;newNode->data=0;
		if (p1->data<p2->data){
			p->data=p1->data;
			p->next=newNode;
			p1=p1->next;
			p=p->next;
			continue;
		}
		if (p1->data>p2->data){
			p->data=p2->data;
			p->next=newNode;
			p2=p2->next;
			p=p->next;
			continue;
		}
		else{
			p->data=p2->data;
			p->next=newNode;
			p2=p2->next;
			p1=p1->next;
			p=p->next;
			continue;
		}
	}
	while (p1){
		Node *newNode=(Node*)malloc(sizeof(Node));
		newNode->next=NULL;newNode->data=0;
		p->data=p1->data;
		p->next=newNode;
		p1=p1->next;
		p=p->next;
	}
	while (p2){
		Node *newNode=(Node*)malloc(sizeof(Node));
		newNode->next=NULL;newNode->data=0;
		p->data=p2->data;
		p->next=newNode;
		p2=p2->next;
		p=p->next;
	}
}
void output(Linklist *Link){
	printf("\nthe data in the merged linklist are:\n");
	Node *p=Link->next;
	while (p&&p->data!=0){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main(){
	printf("%s\n", "the first linklist is :");
	int a1[10]={1,3,5,6,7,8,9,10,11,12};
	int a2[10]={2,4,5,6,7,8,9,10,13,15};
	for (int i=0;i<10;i++) printf("%d ",a1[i]);
	printf("\n%s\n","the seconde linklist is:");
	for (int i=0;i<10;i++) printf("%d ",a2[i]);
	Linklist A,B,C;
	init(&A,a1);
	init(&B,a2);
	merge(&A,&B,&C);
	output(&C);
	return 0;
}