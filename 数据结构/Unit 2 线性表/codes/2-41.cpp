#include<bits/stdc++.h>
using namespace std;
typedef struct {
	int coef;
	int exp;
} PolyTerm;
typedef struct Polynode{
	PolyTerm data;
	struct Polynode *next;
}Polynode;
typedef struct Polylink{
	Polynode *next;
}Polylink;
void clear(Polynode *x){
	x->data.coef=0;
	x->data.exp=0;
	x->next=NULL;
}
void init(Polylink *A,int length){
	Polynode *p=(Polynode*)malloc(sizeof(Polynode));clear(p);
	A->next=p;
	printf("%s\n","please input each coefficient:");
	for (int i=length;i>=0;i--) {
		Polynode *newNode=(Polynode*)malloc(sizeof(Polynode));clear(newNode);
		int data;
		scanf("%d",&data);
		p->data.exp=i;
		p->next=newNode;
		p->data.coef=data;
		p=p->next;
	}
}
void calc(Polylink &A){
	Polynode *p=A.next;
	while (p->next){
		p->data.coef=p->data.coef*p->data.exp;
		p->data.exp-=1;
		if (p->data.exp==-1) {
			free(p->next);
			p->next=NULL;
			return;
		}
		p=p->next;
	}
}
void output(Polylink &A){
	Polynode *p=A.next;
	while (p->next){
		if (p->next->next!=NULL) printf("%dx^%d + ",p->data.coef,p->data.exp);
		else printf("%d",p->data.coef);
		p=p->next;
	}
	printf("\n");
}
int main(){
	printf("%s\n", "Please input the maximum power of your PolyTerm:");
	int x;scanf("%d",&x);
	Polylink link;
	init(&link,x);
	printf("%s","the expression you input is:");output(link);
	calc(link);
	printf("%s","the outcome is:");output(link);
	return 0;
}