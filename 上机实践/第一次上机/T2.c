#include<stdlib.h>
#include<stdio.h>
typedef struct Lineseq{
	int *elem;
	int size;
} Lineseq;
void init(int n,Lineseq *Sq){
	printf("%s\n","the data which is contained in the Lineseq are:");
	Sq->size=n;
	Sq->elem=(int*)malloc(n*sizeof(int));
	for (int i=0;i<n;i++){
		int data=rand()%1000;
		Sq->elem[i]=data;
		printf("%d ",data);
	}
	printf("\n");
}
void solve(Lineseq *Sq,int p){//solve the problem
	int *newPos=(int*)malloc(p*sizeof(int));// have a new place to storage the datas
	int n=Sq->size;// let n as the size of the sequence
	for (int i=0;i<p;i++)
		newPos[i]=Sq->elem[i];//storage the first p datas
	for (int i=p;i<n;i++)
		Sq->elem[i-p]=Sq->elem[i];// change the next datas' positions
	for (int i=0;i<p;i++)
		Sq->elem[n-p+i]=newPos[i];//put the first p datas into the right postions
}
void output(Lineseq *sq){
	printf("%s\n","the new Lineseq is :");
	for (int i=0;i<sq->size;i++)
		printf("%d ",sq->elem[i]);
}
int main(){
	printf("%s\n","Please input the length of the Lineseq you want:");
	int n,p;
	Lineseq Sq;
	scanf("%d",&n);
	printf("%s\n","Please input the position you want to change:");
	scanf("%d",&p);
	init(n,&Sq);
	solve(&Sq,p);
	output(&Sq);
	return 0; 
}