#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int *elem;
	int length;
	int listsize;
}SqList;
bool DeleteK(SqList *a,int i,int k){
	if (i<1||k<0||i+k>a->length) return false;
	for (int j=0;j<=k;j++)
		a->elem[i+j]=a->elem[i+j+k];
	a->length=a->length-k;
	return true;
}
void init(SqList *a){
	srand(time(NULL));
	a->length=20;
	for (int i=0;i<a->length;i++)
		a->elem[i]=rand()%100;
	a->listsize=1000;
}
void output(SqList *a){
	for (int i=0;i<a->length;i++)
		printf("%d ",a->elem[i]);
	printf("\n");
}
int main(){
	SqList A;
	init(&A);
	output(&A);
	DeleteK(&A,2,3);
	output(&A);
	return 0;
}