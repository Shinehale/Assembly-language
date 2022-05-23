#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int *elem;
	int length;
	int listsize;
}SqList;
void insert(SqList *A,int value){
	int pos=A->length;
	for (int i=0;i<A->length;i++)
		if (A->elem[i]>value) {pos=i-1;break;}
	for (int i=A->length-1;i>=pos;i--)
		A->elem[i+1]=A->elem[i];
	A->elem[pos]=value;
}
void init(SqList *a){
	srand(time(NULL));
	a->length=20;
	for (int i=0;i<a->length;i++)
		a->elem[i]=i*2+1;
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
	insert(&A,12);
	output(&A);
	return 0;
}// time complexity:O(n)