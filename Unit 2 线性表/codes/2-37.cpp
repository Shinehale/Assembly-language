#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
	int data;
	struct Node *next;
	struct Node *prev;
} Node;
typedef struct Linklist{
	Node *next;
} Linklist;
void init(Linklist *Link,int length){
	Node* p=(Node*)malloc(sizeof(Node));
	p->next=NULL;p->prev=NULL;p->data=0;
	Link->next=p;
	for (int i=0;i<length;i++){
		Node* newNode=(Node*)malloc(sizeof(Node));
		newNode->next=NULL;newNode->data=0;newNode->prev=NULL;
		int data=rand()%1000;
		p->data=data;
		p->next=newNode;
		newNode->prev=p;
		p=p->next;
	}
	p=Link->next;
	while (p->next->next){
		p=p->next;
	}
	p->next=Link->next;Link->next->prev=p;
}
void change_position(Linklist *link,int length){
	Node *p=link->next,*p1=link->next;
	while (p->next!=link->next){p=p->next;}
	if (length%2==0){
		while (p1->next!=p){
			p1->next=p1->next->next;
			p1=p1->next;
		}
		while (p->prev!=link->next){
			p->next=p->prev->prev;
			p=p->next;
		}
	}
	else{
		while (p1!=p){
			p1->next=p1->next->next;
			p1=p1->next;
		}
		p1->next=p1->prev;
		p1=p1->next;
		while (p1->prev!=link->next){
			p1->next=p1->prev->prev;
			p1=p1->next;
		}
	}
	p=link->next;
	while (p->prev!=link->next){
		p=p->next->prev;
		p=p->next;
	}
	p->next=link->next;
	link->next->prev=p;
}
void output(Linklist *Link){
	printf("%s\n","the data in the Linklist are:");
	Node *p=Link->next;
	while (p->next!=Link->next){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("%d \n",p->data);

}
int main(){
	printf("%s\n","Please input the length of Linklist you want");
	int n;scanf("%d",&n);
	Linklist A;
	srand(time(NULL));
	init(&A,n);
	output(&A);	
	change_position(&A,n);
	output(&A);
	return 0;
}