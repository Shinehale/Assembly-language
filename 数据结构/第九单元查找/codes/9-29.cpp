/*
实现中就不按照标准的循环链表完成，而是借助数组来模拟循环链表
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
struct node{
	int pos;
	int data;
} P[N];
int h = 0, t = 0;
void find( int tar ,int n ){
	if ( tar < P[t].data ) {
		t = h;
		while ( true ){
			if ( tar == P[t].data ) break;
			t = t + 1;
			if ( t == n ) break;
		}
	}
	if ( tar > P[t].data ){
		while ( true ){
			if ( tar == P[t].data ) break;
			t = t + 1;
			if ( t == n ) break;
		}
	}
	if ( t != n )	printf("the %d is %d \n", tar, t+1);
	else printf(" We can not find the %d !\n", tar);
}
int main(){
	int n; cin>>n; 						// n 表示链表长度
	for (int i = 0; i < n ;i++) {
		int x ; cin >> x;
		P[i].data = x;
		P[i].pos = i;
	}
	int m; cin>> m;						// m 表示想要查询次数
	while ( m-- ){
		int x;cin >> x;
		find( x , n );
	}
	return 0;
}
/*
Input sample:
10
2 4 6 8 10 11 16 26 36 48 
3
36 8 49
OutPut sample:
the 36 is 9
the 8 is 4
 We can not find the 49 !
*/