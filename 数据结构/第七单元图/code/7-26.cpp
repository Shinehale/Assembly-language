// considering that we can make a topsort to the map 
// because it does not have a circle 
// so there must be a topsorted order.
// then from the bottom to top give its order.
#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int M = 1e5+7;

struct Edge{
	int  to, dist;
}; 
int m, n;
vector<Edge> e[N];

void addEdge ( int x, int y, int dist ){
	e[x].push_back( ( Edge ) { y, dist } );
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
	for ( int  i = 0; i < n; i++ )
		printf("pre: %d  new : %d \n", a[i], i+1);
}

int main(){

	cin>> n >> m ;
	for ( int times = 0; times < m ; times++ ){
		int x , y , dist;
		cin >> x >> y >> dist;
		addEdge ( x-1, y-1, dist );
	}
	solve();
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
*/