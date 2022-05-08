#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int M = 1e5+7;

struct Vertax{
	int pos,value;
} V[N];
struct Edge{
	int  to, dist;
}; 

vector<Edge> e[N];

void addEdge ( int x, int y, int dist ){
	e[x].push_back( ( Edge ) {y, dist} );
}

int main(){
	int n, m; 
	cin>>n>>m;
	// n presents the sum of the vertax 
	// m represents the sum of the arc
	while ( m -- ) {
		int x, y, dist;
		cin >> x >> y >> dist;
		addEdge( x, y, dist );// Unidirectional edge
	}
	while ( n-- ){
		int x, value;
		cin>>x >> value ;
		V[n].pos = x;
		V[n].value = value;
	}
	return 0;
}
/*
4 6 
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
*/