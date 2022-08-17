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



void solve(){
	// the default root is 1.
	node tmp; tmp.SerialNumber = 1; tmp.times = 0;
	s[top++] = tmp;
	while ( top != 0 ){
		s[top-1].times += 1;
		node topNode = s[top-1];		
		if ( topNode.times == 1 ) {
			cout<<topNode.SerialNumber<<" "<<endl;
			if ( t[topNode.SerialNumber].lson ) {
				node newNode;
				newNode.SerialNumber = t[topNode.SerialNumber].lson;
				newNode.times = 0;
				s[top++] = newNode;
				continue;
			}
		}
		if ( topNode.times == 2){
			if ( t[topNode.SerialNumber].rson ) {
				node newNode;
				newNode.SerialNumber = t[topNode.SerialNumber].rson;
				newNode.times = 0;
				s[top++] = newNode;
				continue;
			}
		}
		if (topNode.times == 3){
			top--;
		}
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
	// for (int i = 1; i<=n ;i++) cout<<t[i].lson<<"   "<<t[i].rson<<endl;
	solve();
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
1 2 4 5 7 8 3 6 9
*/