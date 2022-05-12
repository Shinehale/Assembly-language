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

bool BFS ( int pos, int tar){

	queue< int > que ;
	bool vised[ N ];
	memset ( vised , 0 , sizeof ( vised ) );
	que.push( pos );
	while ( ! que.empty() ) {
		int x = que.front();
		que.pop();
		vised[ x ] = true ;
		for ( int i = 0; i < (unsigned int) e[x].size() ;i++ ){
			int y = e[x][i].to;
			// int dist = e[x][i].dist;
			if ( ! vised [ y ] ) {
				que.push( y );
			}
		}
	}	
	return vised[tar];

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
	bool check = BFS( u, v );
	if ( check ){ 
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