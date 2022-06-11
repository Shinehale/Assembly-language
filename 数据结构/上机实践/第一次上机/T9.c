#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
} Node;
typedef struct Linklist{
	Node *next;
} Linklist;
void init(Linklist *link,int length){
	Node *p=(Node*)malloc(sizeof(Node));
	p->data=0;p->next=NULL;
	link->next=p;
	for (int i=0;i<length;i++){
		int data=rand()%10+1;
		Node *newNode=(Node*)malloc(sizeof(Node));
		newNode->data=0;newNode->next=NULL;
		p->data=data;p->next=newNode;newNode->prev=p;
		p=p->next;
	}
	p->next=link->next;
	link->next->prev=p;
}	
void delete_element(Linklist *link,int target){
	Node *p=link->next;
	while (p->next!=link->next){
		if (p->data==target){
			p->data=p->next->data;
			p->next=p->next->next;
			p->next->next->prev=p;
		}
		else p=p->next;
	}
	if (p->data==target){
		p->prev->next=link->next;
		link->next->prev=p->prev;
	}
}
void output(Linklist *Link){
	printf("\nthe data in linklist are:\n");
	Node *p=Link->next;
	while (p&&p->data!=0){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main(){
	srand(time(NULL));
	printf("%s\n","Please input the length of the linklist you want:");
	int n;scanf("%d",&n);
	Linklist A;init(&A,n);output(&A);
	printf("%s\n","Please input value of the target element you want to delete:");
	int x;scanf("%d",&x);
	delete_element(&A,x);
	output(&A);
	return 0;
}