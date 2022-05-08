#include<bits/stdc++.h>
using namespace std;
typedef struct{
	int *elem;
	int length;
	int listsize;
}SqList;
bool cmp(SqList *A,SqList *B){
	int p1=0,p2=0;
	while (p1<A->length&&p2<B->length){
		if (A->elem[p1]<B->elem[p2]) return true;
		if (A->elem[p1]>B->elem[p2]) return false;
		p1++;
		p2++;
	}
	if (p1==A->length) return true;
	return false;
}
void init(SqList &a){
	a.elem=(int*)malloc(sizeof(int)*a.length);
	for (int i=0;i<a.length;i++)
		a.elem[i]=rand()%3+1;
	a.listsize=1000;
}
void output(SqList *a){
	for (int i=0;i<a->length;i++)
		printf("%d ",a->elem[i]);
	printf("\n");
}
int main(){
	srand(time(NULL));
	SqList A,B;
	A.length=rand()%15+1;B.length=rand()%15+1;
	init(A);init(B);
	output(&A);output(&B);
	if (cmp(&A,&B)) printf("A<B");
	else printf("A>B");
	return 0;
}// time complexity:O(n)