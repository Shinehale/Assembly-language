#include<bits/stdc++.h>
using namespace std;
const int MAXSIZE=100;
typedef struct Node{
	int i,j,data;
	struct Node *Rnext,*Cnext;
} Node;
typedef struct Matrix{
	Node *Rhead,*Chead;
	int mu,nu,tu;
}Matrix;
void clear(Node *p){
	p->i=p->j=p->data=0;
	p->Rnext=p->Cnext=NULL;
}
void init(Matrix &M,int n){
	int tot=rand()%n+n;
	M.mu=M.tu=n;
	M.Rhead=(Node*)malloc(sizeof(Node)*(n+1));
	M.Chead=(Node*)malloc(sizeof(Node)*(n+1));
	for (int i=0;i<n;i++){
		clear(&M.Rhead[i]);
		clear(&M.Chead[i]);
	}
	for (int times=0;times<tot;times++){
		Node *newNode=(Node*)malloc(sizeof(Node));
		int i=rand()%n,j=rand()%n;
		int data=rand()%100+1;
		newNode->i=i;newNode->j=j;newNode->data=data;
		if (M.Rhead[i].j>j||M.Rhead[i].Cnext==NULL){
			newNode->Cnext=&M.Rhead[i];
			M.Rhead+i=newNode;
		}else{
			Node *p=M.Rhead[i];
			while (p->j<j&&p->Cnext) p=p->Cnext;
			newNode->Cnext=p->Cnext;p->Cnext=newNode;
		}
		if (M.Chead[j]->i>i||M.Chead[j]==NULL){
			newNode->Rnext=M.Chead[j];
			M.Chead[i]=newNode;
		}else{
			Node *p=M.Chead[j];
			while (p->i<i&&p->Rnext) p=p->Rnext;
			newNode->Rnext=p->Rnext;p->Rnext=newNode;
		}
	}
}
void Output(Matrix &M){
	for (int i=0;i<M.nu;i++){
		Node *p=M.Rhead[i];
		while (p->data!=0){
			printf("(%d %d %d)\n",p->i,p->j,p->data);
			p=p->Cnext;
		}
	}
}
int main(){
	srand(time(NULL));
	printf("%s\n","Please input the size of the Matrix you want:");
	int n;scanf("%d",&n);
	Matrix M1;
	init(M1,n);
	Output(M1);
	return 0;
}