#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int n; 										// n 表示二叉树上的结点数
struct node{
	int val;
	int lson,rson;
	int fa;
} P[N];
int cnt = 0;
int sum = 0;
int lis[N];
void dfs( int x ,int tar ){
	if ( P[x].rson ) dfs( P[x].rson , tar );
	if ( P[x].lson && P[x].val >= tar ) dfs( P[x].lson , tar );
	if ( P[x].val >= tar ) {
		int y = P[x].fa;
		if ( P[y].lson == x ) P[y].lson = 0;
		if ( P[y].rson == x ) P[y].rson = 0;
		P[x].fa = 0;
		P[x].val = 0;
		sum ++;
	}
}
void solve( int tar ){
	int root = 0;
	for (int i = 1;i <= n ;i++ ) if ( P[i].fa == 0 ) root = i;
	dfs( root , tar );
}
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
	solve( tar );
	cout<< sum<<endl; 
	return 0;
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
53
*/