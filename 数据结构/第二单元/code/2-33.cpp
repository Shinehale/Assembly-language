#include<bits/stdc++.h>
using namespace std;
typedef struct Node{
	char data;
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
	for (int i=0;i<30;i++){
		int type=rand()%3;
		Node *newNode=(Node*)malloc(sizeof(Node));clear(newNode);
		switch(type){
			case 0:p->data='!'+rand()%10;break;
			case 1:p->data='0'+rand()%10;break;
			case 2:p->data='A'+rand()%26;break;
		}
		p->next=newNode;
		p=p->next;
	}
}//rear insert method
void output(Linklist *A){
	Node *p=A->next;
	while (p->next){
		printf("%c ",p->data);
		p=p->next;
	}
	printf("\n");
}
void seperate(Linklist &A,Linklist &B,Linklist &C,Linklist &D){
	Node *p=A.next;B.next=C.next=D.next=NULL;
	while (p->next){
		char c=p->data;
		Node *newNode=(Node*)malloc(sizeof(Node));clear(newNode);
		newNode->data=c;
		p=p->next;
		if (c-'!'<10&&c-'!'>=0) {
			newNode->next=B.next;
			B.next=newNode;
			continue;
		}
		if (c-'0'<10&&c-'0'>=0) {
			newNode->next=C.next;
			C.next=newNode;
			continue;
		}
		if (c-'A'<26&&c-'A'>=0) {
			newNode->next=D.next;
			D.next=newNode;
		}
	}
}
void Output(Linklist &A){
	Node *p=A.next;
	while (p->next){
		printf("%c ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main(){
	Linklist A,B,C,D;
	srand(time(NULL));
	init(&A);output(&A);
	seperate(A,B,C,D);
	output(&B);
	output(&C);
	output(&D);
	return 0;
}