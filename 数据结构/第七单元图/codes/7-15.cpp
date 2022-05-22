#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int M = 1e5+7;

int mp[N][N];
int v[N];


void insertArc( int x, int y , int dist ){
	mp[ x ][ y ] = dist;
}
void insertVer ( int x ,int value ){
	v [ x ] = value ;
}
void deleteArc ( int x, int y ){
	if ( mp [ x ][ y ] == 0 ) return;
	else mp[ x ][ y ] = 0;
}
void deleteVer ( int x ){
	if ( v[ x ] == 0) return;
	else v[ x ] = 0;
}

int main(){
	int m, n ,p;
	cin>> m >> n >> p ;
	// m -> sum of the map edges 
	// n -> sum of the vertaxes
	// p -> sum of the operations

	// assume the map is Unidirectional edge
	while ( m-- ){
		int x, y, dist;
		cin>> x >> y >> dist ;
		insertArc( x, y , dist );
	}
	while ( n-- ){
		int pos, value;
		cin>> pos >> value;
		insertVer( pos, value );
	}
	while ( p-- ){
		int opt, x, y;
		// opt == 1 represents delete arc x -> y;
		// opt == 2 represents delete vertax x;
		cin >> opt;
		if ( opt == 1 ) {
			cin>> x >> y;
			deleteArc( x, y );
		}
		else if ( opt == 2 ){
			cin >> x;
			deleteVer( x );
		}
	}
	return 0;
}
/*
4 6 3
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
1 15
2 36
4 69
3 45
1 2 4
1 3 4
2 4
*/