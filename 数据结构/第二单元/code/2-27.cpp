#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int *elem;
	int length;
	int listsize;
}SqList;
void init(SqList &a){
	a.length=15;
	a.elem=(int*)malloc(sizeof(int)*a.length);
	for (int i=0;i<a.length;i++)
		a.elem[i]=2*i+rand()%2+1;
	a.listsize=1000;
}
void output(SqList &a){
	for (int i=0;i<a.length;i++)
		printf("%d ",a.elem[i]);
	printf("\n");
}
void merge(SqList &A,SqList &B){
	int p1=0,p2=0,k=0;
	while (p1<A.length&&p2<B.length){
		if (A.elem[p1]<B.elem[p2]){
			p1++;
		}
		if (A.elem[p1]>B.elem[p2]){
			p2++;
		}
		if (A.elem[p1]==B.elem[p2]){
			A.elem[k]=A.elem[p1];
			k++;
			p1++;p2++;
		}
	}
	A.length=k;
}
int main(){
	srand(time(NULL));
	SqList A,B;
	init(A);init(B);
	output(A);output(B);
	merge(A,B);output(A);
	return 0;
}// time complexity:O(n)