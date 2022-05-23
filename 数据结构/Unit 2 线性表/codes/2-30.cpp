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
void init(Linklist *A){
	Node *p=(Node*)malloc(sizeof(Node));clear(p);
	A->next=p;
	for (int i=0;i<15;i++){
		int data=2*i+rand()%2+1;
		Node *newNode=(Node*)malloc(sizeof(Node));clear(newNode);
		p->data=data;
		p->next=newNode;
		p=p->next;
	}
}//rear insert method
void output(Linklist *A){
	Node *p=A->next;
	while (p->next){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void solve(Linklist *A,Linklist *B,Linklist *C){
	Node *p=A->next,*p1=B->next,*p2=C->next;
	while (p1->next&&p2->next){
		if (p1->data<p2->data) p1=p1->next;
		if (p1->data>p2->data) p2=p2->next;
		if (p1->data==p2->data){
			while (p->next&&p->data<p1->data) p=p->next;
			if (p->data!=p1->data) {
				p1=p1->next;
				p2=p2->next;
				continue;
			}
			Node *pp=p->next;
			if (p->next==NULL) {
				p->data=0;
				p->next=NULL;
			}
			else{
				p->data=p->next->data;
				p->next=p->next->next;
			}
			free(pp);
			p1=p1->next;
			p2=p2->next;
		}
	}
}
int main(){
	Linklist A,B,C;
	srand(time(NULL));
	init(&A);output(&A);
	init(&B);output(&B);
	init(&C);output(&C);
	solve(&A,&B,&C);
	output(&A);
	return 0;
}