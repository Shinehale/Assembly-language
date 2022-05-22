#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int M = 1e5+7;

int mp[N][N];

void addEdge ( int x, int y, int dist ){
	mp[x][y] = dist;
}
int m, n ;
bool vised[N];

void dfs ( int pos, int tar, bool & flag ,int dis ,int tardis ){

	if ( pos == tar ) {
		if ( dis  == tardis ) flag = true;
		return;
	}
	vised[ pos ] = true;
	for ( int i = 0;i < n; i++ ) {
		if ( mp[pos][i] ) 
			dfs ( i, tar, flag, dis+mp[pos][i], tardis);
	}
	vised[pos] = false;
}

int main(){

	cin>> n >> m ;
	for ( int times = 0; times < m ; times++ ){
		int x , y , dist;
		cin >> x >> y >> dist;
		addEdge ( x-1, y-1, dist );
	}
	int u,v,k;
	cin>> u >> v >> k;
	bool flag = false;
	dfs ( u-1, v-1, flag , 0, k );
	if ( flag ){ 
		cout<< "Yes"<< endl;
	}
	else cout << "No" << endl;
	return 0;
}

/*
4 7
1 2 2
2 3 2
2 4 1
1 3 5
3 4 3
1 4 4
4 1 5
2 1 10
*/