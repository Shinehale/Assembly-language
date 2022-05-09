#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
const int M = 2e5+7;

struct Edge{
	int  to, dist;
}; 
int m, n;
vector<Edge> e[N], E[N];
int MPL[N];
void addEdge ( int x, int y, int dist ){
	e[x].push_back( ( Edge ) { y, dist } );
	E[y].push_back( ( Edge ) { x, dist } );
}

struct Node{
	int pos;
};
bool vised[N];


void topSort(int a[]){
	int indeg[N]={0};
	for ( int i = 0; i < n; i++ ){
		for ( int j = 0; j < e[i].size(); j++ ){
			int y = e[i][j].to;
			indeg[y]++;
		}
	}
	queue< int > que;
	for (int i = 0; i < n; i++ ){
		if ( indeg [ i ] == 0 ) que.push( i ); 
	} 
	stack< int >S;
	while (!que.empty()){
		int x = que.front();
		que.pop();
		for (int i = 0;i < e[x].size(); i++ ){
			int y = e[x][i].to;
			indeg[y]--;
			if ( indeg[y] == 0 ){
				que.push( y );
			}
		}
		S.push(x);
	}
	for (int i = 0; i < n ; i++){
		int y = S.top();
		S.pop();
		a[i]=y;
	}
}
void solve( ){
	int a[N];
	topSort(a);
	for ( int i = 0; i < n ;i++ ){
		for ( int j = 0 ; j < E[a[i]].size(); j++ ){
			int y = E[ a[ i ] ][ j ].to, x = a[i];
			int dis = E[ a[ i ] ][ j ].dist;
			if ( MPL[ y ] < MPL [ x ] + dis ) 
				MPL[ y ] = MPL [ x ] + dis;
		}
	}
}

int main(){

	cin>> n >> m ;
	for ( int times = 0; times < m ; times++ ){
		int x , y , dist;
		cin >> x >> y >> dist;
		addEdge ( x-1, y-1, dist );
	}
	solve();
	for ( int i = 0; i < n ;i++ ) cout<<i<<":"<<MPL[i]<<endl;
	return 0;
}
// the time is O (E)
// E is the sum of the graph;