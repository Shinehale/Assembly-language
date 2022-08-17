#include<stdlib.h>
#include<stdio.h>
#include<time.h>
typedef struct Lineseq{
	int *elem;
	int size;
} Lineseq;
void init(int n,Lineseq *Sq){
	Sq->size=n;
	Sq->elem=(int*)malloc(n*sizeof(int));
	for (int i=0;i<n;i++){
		int data=rand()%10+1;
		int signal=rand()%2;
		Sq->elem[i]=signal==0?-data:data;
	}
}
void solve(Lineseq *sq){
	int cnt=0,p1=0,p2=0;
	for (int i=0;i<sq->size;i++)
		if (sq->elem[i]>0) cnt++;
	int *pos=(int*)malloc(sizeof(int)*cnt);

	for (int i=0;i<sq->size;i++)
		if (sq->elem[i]<0){
			sq->elem[p1]=sq->elem[i];
			p1=p1+1;
		}
		else{
			pos[p2]=sq->elem[i];
			p2++;
		}
	for (int i=0;i<p2;i++){
		sq->elem[p1+i]=pos[i];
	}
}
void output(Lineseq *sq){
	printf("%s\n","the data which is contained in the line sequence are:");
	for (int i=0;i<sq->size;i++)
		printf("%d ",sq->elem[i]);
	printf("\n");
}
int main(){
	printf("%s\n","Please input the length of the line sequence you want:");
	int n;Lineseq Sq;srand(time(NULL));
	scanf("%d",&n);
	init(n,&Sq);
	output(&Sq);
	solve(&Sq);
	output(&Sq);
	return 0;
}