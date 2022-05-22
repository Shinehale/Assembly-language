#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+7;
const int M = 1e2+7;
struct node{
	int data;
	int pos;
} P[N];
struct block{
	int val;
	int pos;
} B[M];
int find( int x ,int numBlock ){
// return the position of the block not the specific position of value 
	int L = 0, R = numBlock-1;
	while ( L <= R ){
		int mid = (L+R)>>1;
		if ( B[mid].val <= x && B[mid+1].val > x ) return mid;
		if ( B[mid].val > x ) R = mid-1; 
		else L = mid+1 ;
	}
	return L;

}
int main(){
	int n; cin>>n;
	for (int i = 0; i < n ;i++) {
		int x ; cin >> x;
		P[i+1].data = x;
		P[i+1].pos = i;
	}
	int numBlock = int(sqrt(n));
	int size = numBlock;
	if ( sqrt( n ) * sqrt( n ) != n ) numBlock+=1;
	for (int i = 0;i < numBlock; i++)
		B[i].val = P[i*size+1].data;
	B[ numBlock ].val = P[ n ].data + 1 ;
	int tar; cin >> tar;
	int pos = find ( tar, numBlock );
	cout<<pos<<endl;  
	return 0;
}
/*
Input Sample:
10
1 2 3 4 5 6 7 8 9 10
10
Output Sample：
3
*/