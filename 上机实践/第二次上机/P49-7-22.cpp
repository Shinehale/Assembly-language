#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int M = 1e5+7;

struct Edge{
	int  to, dist;
}; 

vector<Edge> e[N];

void addEdge ( int x, int y, int dist ){
	e[x].push_back( ( Edge ) { y, dist } ); 			//using vector as the container to reserve the map
}

bool vised[N];							// as a icon to save the outcome
void dfs ( int x ){

	vised[x] = true;
	for (int i = 0; i < int(e[x].size()); i++ ){
		int y = e[x][i].to;
		if ( !vised[y] ) {
			dfs(y);
		}
		else continue;
	}

}

int main(){
	int n, m ;   									// n --> the number of the nodes in the map
													// m --> the number of the paths in the map
	cin>> n >> m ;
	for ( int times = 0; times < m ; times++ ){
		int x , y , dist;
		cin >> x >> y >> dist;
		addEdge ( x, y, dist );
	}
	int u,v;
	cin>> u >> v;
	dfs( u );
	if ( vised[v] ){ 
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