#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;


int n, n1; 										// n 表示二叉树上的结点数
struct node{
	int val;
	int lson,rson;
	int fa;
} P[N],P1[N];
int sum;


void merge ( int, int );
void out ( int );
void addNode ( int ,int );
void dfs ( int ,int );


int main(){
	cin >> n;									// input the first tree
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
	sum = n;
	cin >> n1;									// Input the second tree
	for (int i = 0; i< n1 ;i++){
		int x; cin>> x;
		P1[i+1].val = x;
	}
	for (int i = 0; i <  n1 - 1 ;i ++ ){
		int x, y, flag; cin>> x>> y >> flag; 	// flag 为 1 表示 y 是 x 右孩子
		if ( flag ) {
			P1[x].rson = y;
			P1[y].fa = x;
		}
		else {
			P1[x].lson = y;
			P1[y].fa = x;
		}
	}	
	int root1, root2;
	for ( int i = 1; i<= n; i++ ) if ( P[i].fa == 0 ) root1 = i;
	for ( int i = 1; i<= n1; i++ ) if ( P1[i].fa == 0 ) root2 = i;
	merge ( root1, root2 );
	out (root1); 								// output the new tree
	return 0;
}


void merge( int r1, int r2 ){ 					// merge r2 with r1 and the result reserves in the r1
	dfs( r2, r1 );
}


void out(int  x){
	if ( P[x].lson ) out ( P[x].lson );
	cout<<P[x].val<<" "<<endl;
	if ( P[x].rson ) out ( P[x].rson );
}


void addNode( int val ,int r1){
	int fa = r1;
	while (true){
		if ( P[fa].val == val ) return;
		if ( P[fa].val > val ){
			if ( P[fa].lson ) fa = P[fa].lson;
			else break;
		}
		else {
			if ( P[fa].rson ) fa = P[fa].rson;
			else break;
		}
	}
	++sum;
	P[sum].val = val;
	P[sum].fa = fa;
	if ( P[fa].val > val ) P[fa].lson = sum;
	else P[fa].rson = sum;
}


void dfs ( int x ,int r1){
	int val = P1[x].val;
	addNode( val, r1 );
	if ( P1[x].lson ) dfs( P1[x].lson, r1);
	if ( P1[x].rson ) dfs( P1[x].rson, r1);
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
5
38 69 19 27 49
1 3 0
1 5 1
3 4 1
5 2 1  
*/