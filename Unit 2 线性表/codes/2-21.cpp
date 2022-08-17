#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int *elem;
	int length;
	int listsize;
}SqList;
void init(SqList &a){
	a.elem=(int*)malloc(sizeof(int)*a.length);
	for (int i=0;i<a.length;i++)
		a.elem[i]=rand()%100+1;
	a.listsize=1000;
}
void output(SqList &a){
	for (int i=0;i<a.length;i++)
		printf("%d ",a.elem[i]);
	printf("\n");
}
void solve(SqList &A){
	for (int i=0;i<(A.length)/2;i++){
		int tmp=A.elem[i];
		A.elem[i]=A.elem[A.length-i-1];
		A.elem[A.length-i-1]=tmp;
	}
}
int main(){
	srand(time(NULL));
	SqList A;
	init(A);output(A);
	solve(A);output(A);
	return 0;
}// time complexity:O(n)