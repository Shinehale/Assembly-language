/*
直接中序遍历之后判断得到的序列是否单调即可
*/
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
int lis[N];
void dfs( int x ){
	if ( P[x].lson ) dfs(P[x].lson);
	lis[++cnt] = P[x].val;
	if ( P[x].rson ) dfs(P[x].rson);
}
void check(){
	int root = 0;
	for (int i = 1;i <= n ;i++ ) if ( P[i].fa == 0 ) root = i;
	dfs( root );
	bool flag = true;
	// for (int i = 1; i<= n;i++) cout<<lis[i]<<" "<<endl;
	for (int i = 1;i <  n ;i++ ) if ( lis[i] > lis[i+1]) flag = false;
	if ( !flag ) printf(" %s\n", "This tree is not a BST");
	else printf("%s\n", "This tree is a BST");
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
	check();
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
*/