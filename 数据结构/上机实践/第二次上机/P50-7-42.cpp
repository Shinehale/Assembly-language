#include<bits/stdc++.h>
using namespace std;


const int N=2e5+7;
const int INF=0x7f7f7f7f;


int m,n,k,p,cnt;
int dis[N];

struct edge{
	int to, dist;
};
vector<edge> e[N];


struct node
{
	int pos,dist;
	bool operator<(const node &x) const
	{
		return dist>x.dist;
	}
};

priority_queue<node> que;
bool vis[N];


void dijkstra(int pos)
{
	for ( int i=0; i < N; i++ ) dis[ i ]=INF;
	que.push( ( node ) { pos, 0 } ); dis[ pos ]=0;
	while ( !que.empty() )
    {
    	node tmp = que.top();que.pop();
    	int x = tmp.pos;
    	if ( vis[ x ] ) continue;
    	vis[ x ]=true;
    	for ( int i = 0; i < e[x].size() ; i++ )
    	{
    		int y = e[ x ][ i ].to;
    		int dist = e[ x ][ i ].dist; 
    		if ( dis[ y ] > dis[ x ] + dist )
    		{
    			dis[ y ] = dis[ x ] + dist;
    			if ( !vis[ y ] ) que.push( ( node ) { y,dis[y] } );
			}
		}
	}
}
void add_edge(int a,int b,int dist)
{
	e[a].push_back( (edge) { b , dist } );
}
int main()
{
	cin >> n >> m >> k;
	while ( m -- )
	{
		int x,y,z;
		scanf( "%d%d%d", &x, &y, &z );
		add_edge( x-1, y-1, z );
	}
	dijkstra(k-1);
	for ( int i = 0; i < n; i++ )
	printf("%d ",dis[ i ]);
	return 0;
}
