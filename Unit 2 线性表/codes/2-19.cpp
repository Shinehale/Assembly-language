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
	for (int i=0;i<20;i++){
		int data=2*i+1;
		Node *newNode=(Node*)malloc(sizeof(Node));clear(newNode);
		p->data=data;
		p->next=newNode;
		p=p->next;
	}
}//rear insert method
void output(Linklist *A){
	Node *p=A->next;
	while (p&&p->data!=0){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void delete_range(Linklist *A,int mink,int maxk){
	Node *p=A->next;
	while (p->next){
		if (p->data>mink&&p->data<maxk){
			p->data=p->next->data;
			p->next=p->next->next;
		}
		else p=p->next;
	}
}
int main(){
	Linklist A;
	init(&A);
	output(&A);
	delete_range(&A,10,30);
	output(&A);
	return 0;
}