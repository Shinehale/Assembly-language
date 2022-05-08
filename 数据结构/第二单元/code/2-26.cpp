#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
	int data;
	struct Node *next;
}Node;
typedef struct Linklist{
	Node *next;
}Linklist;
void clear(Node *A){
	A->next=NULL;
	A->data=0;
}
void init(Linklist &A){
	Node *p=(Node*)malloc(sizeof(Node));clear(p);
	A.next=p;
	for (int i=0;i<15;i++){
		int data=2*i+1;
		Node *newNode=(Node*)malloc(sizeof(Node));clear(newNode);
		p->data=data;
		p->next=newNode;
		p=p->next;
	}
}//rear insert method
void output(Linklist &A){
	Node *p=A.next;
	while (p&&p->data!=0){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void merge(Linklist &A,Linklist &B,Linklist &C){
	Node *p1=A.next,*p2=B.next,*p=(Node*)malloc(sizeof(Node));
	C.next=p;
	while (p1->next&&p2->next){
		Node *newNode=(Node*)malloc(sizeof(Node));clear(newNode);
		if (p1->data<=p2->data){
			p->data=p1->data;
			p->next=newNode;
			p=p->next;
			p1=p1->next;
		}
		else{
			p->data=p2->data;
			p->next=newNode;
			p=p->next;
			p2=p2->next;
		}
	}
	while (p1->next){
		Node *newNode=(Node*)malloc(sizeof(Node));clear(newNode);
		p->data=p1->data;
		p->next=newNode;
		p=p->next;
		p1=p1->next;
	}
	while (p2->next){
		Node *newNode=(Node*)malloc(sizeof(Node));clear(newNode);
		p->data=p2->data;
		p->next=newNode;
		p=p->next;
		p2=p2->next;
	}
}
int main(){
	Linklist A,B,C;
	init(A);init(B);
	output(A);output(B);
	merge(A,B,C);
	output(C);
	return 0;
}