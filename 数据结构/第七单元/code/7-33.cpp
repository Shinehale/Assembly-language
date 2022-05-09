#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+7;
const int M = 1e5+7;

struct Edge{
	int from, to, dist;
} e[M];
int fa[ N ];
int cnt;// this used for the sum of the edge.

int find(int x){
	if ( fa[ x ] != x )  return fa[ x ] = find ( fa[ x ] );
	else return x;
}
bool cmp ( Edge a , Edge b ){
	return a.dist < b.dist;
}
int solve( int n ){
	int tot = 0, sum = 0 ;
	for ( int i = 0 ;i < n ; i++ ) fa[i] = i;
	for ( int j = 0 ;j < cnt ; j++) {
		int x = e[j].from , y = e[j].to , dis = e[j].dist;
		int faX = find( x ),faY = find( y );
		if ( faX == faY ) continue; 
		fa[faX] = faY;
		tot ++;
		sum += dis;
		if ( tot == n-1 ) break;
	}
	return sum;
}

int main(){
	int n; cin >> n;
	for ( int i = 0; i < n; i++ ){
		for ( int j = 0; j < n ; j++ ) {
			int x; cin >> x;
			if ( i >= j ) continue;
			if ( x > 0 ) {
				e[ cnt ].from = i;
				e[ cnt ].to = j ;
				e[ cnt ].dist = x;
				cnt++;
			}
		}
	}
	sort ( e, e+cnt, cmp );
	int ans = solve( n );
	cout << ans ;
	return 0;
}
/*
this problem has the input of the adjacency matrix
if you need to change the input 
I think it easy for you to solve it.
*/