#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
const int M = 2e6+7;
const int INF = 2147483647;

struct edge {
	int from, to, dis;
} ed[M];

struct Edge{
	int to ,dist ;
}; 
int m, n, cnt;
vector<Edge> e[N],E[N];
void addEdge( int x, int y, int dist ){
	e[x].push_back ( ( Edge ) { y, dist } );
	E[y].push_back ( ( Edge ) { x, dist } );
	ed[cnt].from = x;
	ed[cnt].to = y; 
	ed[cnt].dis = dist;
	cnt++;
}
int order[N],last[N],early[N];
int arcEarly[M],arcLast[M];

void topSort(){
	int indeg[N] = {0};
	for (int i = 0; i < cnt; i++ ) indeg[ed[i].to]++;
	queue<int> que;
	stack<int> S;
	for (int i = 0 ; i < n ;i++ ) if ( indeg[i] == 0) que.push( i );
	while ( ! que.empty() ){
		int x = que.front( ); que.pop();
		S.push( x );
		for ( int i = 0; i < e[x].size( ) ; i++ ){
			int y = e[x][i].to;
			indeg[y]--;
			if ( indeg[y] == 0 ) {
				que.push( y );
			}
		}
	}
	for (int i = n-1; i >= 0 ; i-- ){
		order[i] = S.top();
		S.pop();
	}
}
void solve() {

	topSort();
	for (int i = 0 ; i < n ; i++ ) {
		int x = order[i];
		for ( int j = 0; j < e[x].size( ) ; j++ ){
			int y = e[x][j].to;
			int dist = e[x][j].dist;
			early [ y ] = max ( early [ y ], early[x] + dist );
		}
	}	
	for ( int i = 0 ;i < n ;i++ ) last [ i ] = INF ;
	last[n-1]=early[n-1];
	for (int i = n-1 ; i >=  0 ; i-- ) {
		int x = order[i];
		for ( int j = 0; j < E[x].size( ) ; j++ ){
			int y = E[x][j].to;
			int dist = E[x][j].dist;
			last [ y ] = min ( last[y], last[x] - dist );
		}
	}
	for ( int i = 0; i < m ;i++ ) arcEarly[i] = early[ed[i].from];
	for ( int i = 0; i < m ;i++ ) arcLast[i] = last[ed[i].to]-ed[i].dis;
	cout<< " The important arcs are:"; 
	for (int i = 0; i< m ;i++) 
		if ( arcEarly [ i ] == arcLast[ i ] ) cout << i+1 << " ";
}
int main(){
	cin >> n >> m;
	// m -> sum of the edges 
	// n -> sum of the points
	for ( int i = 0; i < m; i++ ){
		int x, y, z;
		cin >> x >> y >> z;
		addEdge( x-1, y-1, z );
	}
	solve ();
	return 0;
}

/*
9 11
1 2 6
1 3 4
1 4 5
2 5 1
3 5 1
4 6 2
5 7 9
5 8 7
6 8 4
7 9 2
8 9 4
*/