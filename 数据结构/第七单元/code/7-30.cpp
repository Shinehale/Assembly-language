/*
有这样的想法：
首先对图进行拓扑排序
排序得到的图
首先处理入度大于等于2的点
从当前结点出发进行dfs搜索回溯并且完成路径记录
每当完成一次操作后，对于序列进行记录，并且对路径上入度为1的点进行打标
对于序列进行hash函数映射，对应函数空间，并且反向映射记录编号
当hash函数的函数值对不同序列相同时，更新即可
对于入度为1的点进行判断，若没有进行打标，则dfs搜索并且将得到的序列放入答案集中，
最终将答案集中结果进行输出
即得到所有答案，时间复杂度为O(nm)
经google搜索发现map中的值可以使用vector完成，这将替代hash函数的使用
使代码复杂度下降
*/


#include<bits/stdc++.h>
using namespace std;

const int N = 1000;
const int M = 1e5+7;

int mp[N][N];

void addEdge ( int x, int y, int dist ){
	mp[x][y] = dist;
}
int m, n ;
bool vised[N];
int indeg[N]={0};

void dfs ( int pos, int tar, bool & flag ,int dis ,int tardis ){

	if ( pos == tar ) {
		if ( dis  == tardis ) flag = true;
		return;
	}
	vised[ pos ] = true;
	for ( int i = 0;i < n; i++ ) {
		if ( mp[pos][i] ) 
			dfs ( i, tar, flag, dis+mp[pos][i], tardis);
	}
	vised[pos] = false;
}

void topSort(int a[]){
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

void solve(){
	topSort();
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
9 12
1 2 1
2 3 3
3 4 4
4 5 1
5 1 2
5 2 3
2 5 1
3 6 4
6 7 1
3 8 1
8 9 1
8 2 1
*/