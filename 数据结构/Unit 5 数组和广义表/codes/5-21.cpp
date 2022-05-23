#include<bits/stdc++.h>
using namespace std;
const int MAXSIZE=1e3+5;
typedef struct Triple{
	int i,j;
	int data;
}Triple;
typedef struct Matrix{
	Triple p[MAXSIZE];
	int mu,nu,tu;
}Matrix;
void init(Matrix &M,int n){
	M.mu=M.nu=n;
	int tot=n;
	M.tu=tot;
	for (int i=0;i<tot;i++){
		M.p[i].i=i;
		M.p[i].j=rand()%n;
		M.p[i].data=rand()%100;
		// cout<<M.p[i].j<<"  "<<M.p[i].data<<endl;
	}
}
void add_two_matrix(Matrix &ans,Matrix &M1,Matrix &M2){
	ans.mu=M1.mu;
	ans.nu=M2.nu;
	int p1=0,p2=0,ptr=0;
	while (p1<M1.tu&&p2<M2.tu){
		if (M1.p[p1].i<M2.p[p2].i||(M1.p[p1].i==M2.p[p2].i&&M1.p[p1].j<M2.p[p2].j)){
			ans.p[ptr].i=M1.p[p1].i;
			ans.p[ptr].j=M1.p[p1].j;
			ans.p[ptr].data=M1.p[p1].data;
			p1++;
			ptr++;
		}else if (M1.p[p1].i==M2.p[p2].i&&M1.p[p1].j==M2.p[p2].j){
			ans.p[ptr].i=M1.p[p1].i;
			ans.p[ptr].j=M1.p[p1].j;
			ans.p[ptr].data=M1.p[p1].data+M2.p[p2].data;
			p1++;
			ptr++;
			p2++;
		}
		else{
			ans.p[ptr].i=M2.p[p2].i;
			ans.p[ptr].j=M2.p[p2].j;
			ans.p[ptr].data=M2.p[p2].data;
			ptr++;
			p2++;

		}
	}
	while (p1<M1.tu){
		ans.p[ptr].i=M1.p[p1].i;
		ans.p[ptr].j=M1.p[p1].j;
		ans.p[ptr].data=M1.p[p1].data;
		p1++;
		ptr++;
	}
	while (p2<M2.tu){
		ans.p[ptr].i=M2.p[p2].i;
		ans.p[ptr].j=M2.p[p2].j;
		ans.p[ptr].data=M2.p[p2].data;
		ptr++;
		p2++;
	}
	ans.tu=ptr;
}
void output(Matrix &M){
	int i=0,j=0,ptr=0;
	while (i<M.nu){
		if (ptr==M.tu){
			printf("%4d",0);
		}else if (i==M.p[ptr].i&&j==M.p[ptr].j){
			printf("%4d",M.p[ptr].data);
			ptr+=1;
		}
		else {
			printf("%4d",0);			
		}
		j++;
		if (j==M.mu){
			i++;
			j=0;
			printf("\n");
		}
	}
}
int main(){
	printf("Please input the number size of the matrix:");
	srand(time(NULL));
	int n;scanf("%d",&n);
	Matrix M1,M2,ansMatrix;
	init(M1,n);
	init(M2,n);
	output(M1);
	cout<<endl;
	output(M2);
	cout<<endl;
	add_two_matrix(ansMatrix,M1,M2);
	output(ansMatrix);
	return 0;
}