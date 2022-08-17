#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
typedef struct Linklist{
	Node * next;
}Linklist;
void init(int length,Linklist *Link){
	printf("%s\n","the data which is contained in the linklist are:");
	Node *p=(Node*)malloc(sizeof(Node));
	Link->next=p;
	for (int i=0;i<length;i++){
		Node *newNode=(Node*)malloc(sizeof(Node));
		newNode->data=0;newNode->next=NULL;
		int data=rand()%1000;
		p->data=data;
		printf("%d ",p->data);	
		p->next=newNode;
		p=newNode;
	}
	printf("\n");
}
void solve(Linklist *A,Linklist *Link1,Linklist *Link2){
	int cnt=0;
	Link1->next=(Node*)malloc(sizeof(Node));
	Link2->next=(Node*)malloc(sizeof(Node));
	Node *p=A->next,*p1=Link1->next,*p2=Link2->next;

	while (p){
		cnt++;
		Node *newNode=(Node*)malloc(sizeof(Node));
		newNode->data=0;newNode->next=NULL;
		if (cnt%2==0){
			p1->data=p->data;
			p1->next=newNode;
			p1=newNode;
		}
		else{
			p2->data=p->data;
			p2->next=newNode;
			p2=newNode;
		}
		p=p->next;
	}

}
void output(Linklist *Link,char s[]){
	printf("the linklist %s is:\n",s);
	Node *p=Link->next;
	while (p&&p->data!=0){
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
int main(){
	printf("%s\n","Please input the length of the linklist you want:");
	int n;
	Linklist A,B,C;
	char s1[]="B",s2[]="C";
	scanf("%d",&n);
	init(n,&A);
	solve(&A,&B,&C);
	output(&B,s1);
	output(&C,s2);
	return 0;

}