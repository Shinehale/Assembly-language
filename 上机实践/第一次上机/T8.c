#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct Node{
	int data;
	struct Node *next;
} Node;
typedef struct Linklist{
	Node *next;
} Linklist;
void init(Linklist *Link,int length){
	printf("%s\n","the data in the Linklist are:");
	Link->next=NULL;
	for (int i=length;i>0;i--){
		Node * newNode=(Node*)malloc(sizeof(Node));
		newNode->data=rand()%1000;
		newNode->next=Link->next;
		Link->next=newNode;	
	}
	Node *p=Link->next;
	while (p){
		printf("%d ",p->data);
		p=p->next;
	}
}
int search(Linklist *lis,int k){
	Node *p1=lis->next,*p2=lis->next;
	int cnt=0;
	while (p2){
		cnt++;
		if (cnt==k+1) break;
		p2=p2->next;
	}
	if (cnt<k+1){
		return 0;
	}
	while (p2){
		p2=p2->next;
		p1=p1->next;
	}
	return p1->data;
}
int main(){
	printf("%s\n","Please input the length of Linklist you want");
	int n;scanf("%d",&n);
	printf("%s\n","Please input the value of k you want to search");
	int k;scanf("%d",&k);
	Linklist A;
	srand(time(NULL));
	init(&A,n);	
	int ans=search(&A,k);
	printf("\nthe value you want is %d",ans);
	return 0;
}