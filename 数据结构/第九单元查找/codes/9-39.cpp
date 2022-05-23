#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;


int n, n1; 										// n 表示二叉树上的结点数
struct node{
	int val;
	int lson,rson;
	int fa;
} P[N],P1[N];
int sum1, sum2;
int r1, r2;

void solve ( int );
void out ( int );
void addNode ( int ,int );
void dfs (int ,int , int ,int );


int main(){
	cin >> n;
	for ( int i = 0; i < n ;i++){
		int x; cin>> x;
		P[i+1].val = x;
	}
	for (int i = 0; i <  n - 1 ;i ++ ){
		int x, y, flag; cin>> x>> y >> flag; 	// flag 为 1 表示 y 是 x 右孩子
		if ( flag ) {
			P[x].rson = y;
			P[y].fa = x;
		}
		else {
			P[x].lson = y;
			P[y].fa = x;
		}
	}
	int tar; cin >> tar;
	r1 = 0, r2 = n+1;  							// let 0 as the first tree fake root , n+1 as the second tree fake root.
	sum1 = 0, sum2 = n+1;
	solve( tar );
	cout<<"the first tree is "; out ( r1 );
	cout<<"\nthe second tree is "; out ( r2 );
	return 0;
}

void solve( int tar ){ 					// merge r2 with r1 and the result reserves in the r1
	int root = 0;
	for (int i = 1; i <= n; i++ ) if ( P[i].fa == 0) root = i ;
	dfs( root, r2, r1, tar );
	int new_r1 = P1[r1].rson;
	P1[new_r1].fa = 0;
	r1 = new_r1;
	int new_r2 = P1[r2].rson;
	P1[new_r2].fa = 0;
	r2 = new_r2;
}


void out(int  x){
	if ( P1[x].lson ) out ( P1[x].lson );
	cout<<P1[x].val<<" ";
	if ( P1[x].rson ) out ( P1[x].rson );
}


void addNode( int val ,int R){
	int fa = R;
	while (true){
		if ( P1[fa].val == val ) return;
		if ( P1[fa].val > val ){
			if ( P1[fa].lson ) fa = P1[fa].lson;
			else break;
		}
		else {
			if ( P1[fa].rson ) fa = P1[fa].rson;
			else break;
		}
	}
	int sum;
	if ( R == 0 ) sum1++,sum = sum1;
	else sum2++,sum = sum2;
	P1[sum].val = val;
	P1[sum].fa = fa;
	if ( P1[fa].val > val ) P1[fa].lson = sum;
	else P1[fa].rson = sum;
}


void dfs ( int x ,int r1, int r2,int tar){
	int val = P[x].val;
	if ( val > tar ) addNode( val, r2 );
	else addNode ( val, r1 );
	if ( P[x].lson ) dfs( P[x].lson, r1, r2, tar );
	if ( P[x].rson ) dfs( P[x].rson, r1, r2, tar );
} 
/*
7
48 42 57 59 58 36 60
3 2 0
3 4 1
2 6 0
2 1 1
4 5 0
4 7 1
47
*/