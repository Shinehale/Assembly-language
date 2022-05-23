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

struct Node{
	int pos;
};
bool vised[N];

void dfs_nonrecursive( int pos ){
	stack<Node> S;
	S.push((Node){pos});
	while ( !S.empty() ){
		Node tmp = S.top();
		int x = tmp.pos;
		if (!vised[x]) printf("%d  ",x);
		vised[x] = true;
		bool flag = true;
		for (int i = 0; i < e[x].size(); i++ ){
			int y = e[x][i].to;
			if (!vised[y]) {
				S.push((Node) {y});
				flag = false;
				break;
			}
		}
		if (!flag) continue;
		S.pop(); 
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
	// for (int i=0; i<n;i++){
	// 	for (int j=0;j<e[i].size();j++)
	// 		cout<<e[i][j].to<<" ";
	// 	cout<<endl;
	// }
	int from;
	cin>> from;
	dfs_nonrecursive ( from );
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
1
*/