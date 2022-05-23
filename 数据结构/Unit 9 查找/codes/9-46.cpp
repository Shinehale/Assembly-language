/*
when you input m = 1000 n = 1000 then this program can satisfy your wanting.
*/


#include<bits/stdc++.h>
using namespace std;

const int M = 19997;
const int N = 2e4+7;

struct Node{
	int L,R,val;
} P[ N ];

int MyHash( int l, int r ){
	int ans = ( l * l * r ) % M;
	return ans ;
}

void addNode( int L, int R, int val ){
	int ans = MyHash( L, R );
	int key = ans;
	while ( P[key].val ) key = ( key + 1 ) % M;
	P[key].val = val;
	P[key].L = L;
	P[key].R = R;
}
int find(int L,int R){
	int val = MyHash ( L, R );
	int key = val;
	while ( P[key].L != L && P[key].R != R ) key = ( key + 1 ) % M;
	return P[key].val;
}
int main(){
	int m,n; cin>> m>> n;
	for ( int i = 0; i < m ;i++ ){
		for (int j = 0 ; j < n ;j++ ){
			int x; cin>>x;
			if ( x ) addNode ( i, j, x );
		}
	}
	int Q;cin>>Q; 											// Q -> the sum of the query
	while ( Q-- ){
		int L, R;
		cin>> L >> R;
		cout<< find(L,R);
	}
	return 0;
}
/*
2 3
0 6 0 
0 0 9
1
1 2
*/