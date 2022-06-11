#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
typedef struct Linklist{
	Node *next;
}Linklist;
void init(Linklist *link,int length){
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=0;p->next=NULL;
	link->next=p;
	for (int i=0;i<length;i++){
		int data=rand()%1000;
		Node *newNode=(Node*)malloc(sizeof(Node));
		newNode->data=0;newNode->next=NULL;
		p->data=data;p->next=newNode;
		p=p->next;
	}
}	
void solve(Linklist *link,Linklist *link1,Linklist *link2){
	Node *p=link->next;
	Node *p1=(Node*)malloc(sizeof(Node));
	Node *p2=(Node*)malloc(sizeof(Node));
	p1->data=0;p1->next=NULL;p2->data=0;p2->next=NULL;
	link1->next=p1;link2->next=p2;
	int cnt=0;
	while (p){
		cnt++;
		if (cnt%2){
			Node *newNode=(Node*)malloc(sizeof(Node));
			newNode->data=0;newNode->next=NULL;
			p1->data=p->data;
			p1->next=newNode;
			p1=p1->next;
		}
		else{
			Node *newNode=(Node*)malloc(sizeof(Node));
			newNode->data=0;newNode->next=NULL;
			p2->data=p->data;
			p2->next=newNode;
			p2=p2->next;
		}
		p=p->next;
	}
}
void output(Linklist *link,char s[]){
	printf("the %s  Linklist is :\n",s);
	Node *p=link->next;
	while (p&&p->data!=0){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main(){
	srand(time(NULL));
	Linklist A,B,C;
	printf("%s\n","Please input the length of the linklist you want:");
	int n;scanf("%d",&n);
	init(&A,n);
	output(&A,"A");
	solve(&A,&B,&C);
	output(&B,"B");
	output(&C,"C");
	return 0;
}