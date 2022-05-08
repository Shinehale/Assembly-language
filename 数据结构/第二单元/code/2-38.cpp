#include<bits/stdc++.h>
using namespace std;
const int Tar_length=20;
typedef struct Node {
	int data;
	struct Node *next;
	struct Node	*prev;
	int freq; 
}Node;
typedef struct Linklist{
	Node *next;
}Linklist;
void clear(Node &p){
	p.next=NULL;
	p.freq=0;
	p.data=0;
	p.prev=NULL;
}
void init(Linklist &link,int length){
	Node *p=(Node*)malloc(sizeof(Node));
	link.next=p;
	for (int i=0;i<length;i++){
		Node *newNode=(Node*)malloc(sizeof(Node));clear(*newNode);
		p->data=rand()%1000;
		p->next=newNode;
		p=p->next;
	}
}
void locate(Linklist &link,int value){
	Node *p=link.next,*p1=link.next;
	int fre=0;
	while (p->next&&p->data!=value){
		p=p->next;
	} 
	fre=p->freq;
	while (p1->next&&p1->freq!=fre){
		p1=p1->next;
	}
	if (p1==p) {
		p->freq++;
		return;
	}
	swap(p1->data,p->data);
	p1->freq++;
}
void output(Linklist &A){
	Node *p=A.next;
	while (p->next){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main(){
	srand(time(NULL));
	Linklist A;A.next=NULL;
	init(A,Tar_length);
	printf("Original:");output(A);
	while(true){
		printf("please input the value you want to locate:");
		int x;scanf("%d",&x);
		locate(A,x);
		printf("%s","After this locate:");output(A);
	}
	return 0;
}