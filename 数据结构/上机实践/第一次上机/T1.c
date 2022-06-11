#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
	int data;
	struct Node *next;
}Node;
Node* init(int length){
	printf("%s\n","the data which is contained in the linklist are:");
	Node* p=(Node*)malloc(sizeof(Node));
	Node* L=p;
	for (int i=0;i<length;i++){
		int data=rand();
		printf("%d ",data);
		p->data=data;
		Node* newNode=(Node*)malloc(sizeof(Node));
		newNode->data=0;
		newNode->next=NULL;
		p->next=newNode;
		p=newNode;
	}
	printf("\n");
	return L;
}
int max(int a,int b){
	if (a>b) return a;
	else return b;
}
int max_value(Node *L){
	int mx=L->data;
	Node* p=L->next;
	while (p){
		mx=max(mx,p->data);
		p=p->next;
	}
	free(L);
	return mx;
}
int main(){
	printf("%s\n","Please input the length of the linklist you want:");
	int n;
	srand(time(NULL));
	scanf("%d",&n);
	Node *P=init(n);
	int ans=max_value(P);
	printf("the maxvalue of the linklist is %d",ans);
	return 0;

}