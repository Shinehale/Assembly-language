#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int indeg[ N ];

/* 
maybe we need to make a dfs or Bfs
to make sure all the points can be reached
if not , there is no root.
So , the program as follow are assuming that would not happen.
*/
int main(){
	int m, n;
	cin >> n >> m;
	for ( int i = 0; i < m ; i ++ ){
		int x, y, z;
		cin >> x >> y >> z;
		indeg[y-1]++;
	}
	cout << "the roots are:\n"; 
	for ( int i = 0 ;i < n ; i++ )
		if ( indeg[ i ] == 0 ) 
			printf("%d\n", i+1 );
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