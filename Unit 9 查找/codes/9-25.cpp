#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+7;
struct node{
	int data;
	int pos;
} P[N];
int find( int x ,int n ){
	P[0].data = x ;
	int pos = n ;
	for (; P[pos].data!=P[0].data&&pos>0 ;pos--);
	return pos;
}
int main(){
	int n; cin>>n;
	for (int i = 0; i < n ;i++) {
		int x ; cin >> x;
		P[i+1].data = x;
		P[i+1].pos = i;
	}
	int tar; cin >> tar;
	int pos = find ( tar, n);
	cout<<pos<<endl;  
	return 0;
}
/*
Input Sample:
10
10 9 8 7 6 5 4 3 2 1
4
Output Sample：
7
*/