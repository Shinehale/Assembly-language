#include<bits/stdc++.h>
using namespace std;


const int N = 1e5+7;


struct node{
	int SerialNumber;
	int times;
} s[N];
struct Tnode{
	int number;
	int lson, rson;
} t[N];


int n,top; 						// n represents the number of the nodes in the tree.
int tot;


void dfs( int x ){						//default root is 1
	
	if ( t[x].lson ) dfs( t[x].lson );
	if ( t[x].rson ) dfs( t[x].rson );
	if (t[x].lson==0 && t[x].rson == 0){
		tot++;
	}

}
int main(){
	cin >> n ;
	for ( int i = 0; i< n-1; i++ ){
		int x, y;
		int flag;			// flag == 1 --> left son flag ==2 --> right son 
		cin>> x>> y >> flag ; 		//x --> father while y -> son
		if ( flag == 1 ) t[x].lson = y;
		else t[x].rson = y;
	}
	dfs(1);
	cout<<"The total number of the tree leaves are "<<tot<<endl;
	return 0;
}

/*
Input sample:
9
1 2 1
2 4 1
2 5 2
5 7 2
7 8 1
1 3 2
3 6 1
6 9 2
Output Sample:
The total number of the tree leaves are 3
*/