#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;
const int M = 97;
int a[N];
int b[N];

void random( int n ){
	srand(time(NULL));
	for (int i = 0; i< n ;i++){
		int x = rand() % M;
		a[i] = x;
		cout << a[ i ] << " ";
		b[ i + 1 ] = a[ i ];
	}
}

int ans = 0;

void solve( int tar, int length ){
	int stad = b[1], sum = 0;
	int c[N];
	int cnt = 0;
	for ( int i = 2; i <= length; i++ ){
		if ( b[i] < stad ) b[++sum] = b[i];
		else c[++cnt] = b[i];
	}
	if (sum == tar-1 ) ans = stad;
	else if ( sum > tar-1 ) solve(tar, sum);
	else{
		for (int i = 1;i<= cnt ; i++ ) b[i] = c[i];
		int newTar = tar-sum-1;
		solve( newTar, cnt );
	}
}


int main(){
	cout<<"Pleas input the number of the values"<<endl;
	int n; cin >> n;
	random(n); 
	int tar = ceil( 1.0*n/2 );
	solve(tar,n);
	cout<<"\nThe target value is "<<ans<<endl;
	return 0;
}