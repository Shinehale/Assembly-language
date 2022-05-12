#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int M = 1e5+7;

struct Edge{
	int  to, dist;
}; 

vector<Edge> e[N];
int fa[N];
void addEdge ( int x, int y, int dist ){
	e[x].push_back( ( Edge ) { y, dist } );
}

bool vised[N];

void dfs ( int pos, int tar,int from,int & ans){

	if ( pos == tar ) {
		int x =  tar;
		stack<int> S;
		S.push(x);
		while  (x != from) {
			x = fa[ x ];
			S.push(x);
		}
		while (!S.empty()){
			int x = S.top();
			S.pop();cout<< x<< " ";
		}
		cout<<endl;
		ans++;
		return;
	}
	vised[ pos ] = true;
	for (int i = 0; i < ( int ) e[pos].size(); i++ ){
		int x = e[pos][i].to;
		if (!vised[ x ]) {
			fa[x] = pos;
			dfs(x, tar , from , ans);
			fa[x] = 0;
		}
	}
	vised[pos] = false;

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
	int ans = 0;
	dfs ( u, v, u ,ans );
	cout<<ans<<endl;
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
1 4
*/