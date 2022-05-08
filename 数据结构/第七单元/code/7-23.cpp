#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int M = 1e5+7;

struct Edge{
	int  to, dist;
}; 

vector<Edge> e[N];

void addEdge ( int x, int y, int dist ){
	e[x].push_back( ( Edge ) { y, dist } );
}

bool vised[N];

void dfs ( int pos, int tar, bool & flag ){

	if ( pos == tar ) {
		flag = true;
		return;
	}
	vised[ pos ] = true;
	for (int i = 0; i < ( int ) e[pos].size(); i++ ){
		int x = e[pos][i].to;
		if (!vised[ x ]) dfs(x, tar , flag);
	}

}

int main(){
	int n, m ;
	cin>> n >> m ;
	for ( int times = 0; times < m ; times++ ){
		int x , y , dist;
		cin >> x >> y >> dist;
		addEdge ( x, y, dist );
	}
	int u,v;
	cin>> u >> v;
	bool flag = false;
	dfs ( u, v, flag );
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
4 1 7
2 4
*/