#include<bits/stdc++.h>
using namespace std;
typedef struct {
	int coef;
	int exp;
} PolyTerm;
typedef struct{
	PolyTerm *data;
	int length;
} SqPloy;
void init(SqPloy *A,int length){
	A->data=(PolyTerm*)malloc(sizeof(PolyTerm)*(length+1));
	A->length=length+1;
	printf("%s\n","please input each coefficient:");
	for (int i=A->length-1;i>=0;i--) {
		scanf("%d",&A->data[i].coef);
		A->data[i].exp=i;
	}
}
double calc(SqPloy *A,double x){
	double sum=1,ans=0;
	for (int i=0;i<A->length;i++){
		ans+=sum*A->data[i].coef;
		sum=sum*x;
	}
	return ans;
}
int main(){
	printf("%s\n", "Please input the maximum power of your PolyTerm:");
	int x;scanf("%d",&x);
	SqPloy S;
	init(&S,x);
	printf("%s\n","Please input the x you want to calculate:");
	double x_0;cin>>x_0;
	double ans=calc(&S,x_0);
	cout<<"the outcome is "<<ans<<endl;
	return 0;
}