#include<bits/stdc++.h>
using namespace std;


const int N = 11;

int Hash(int val){
	return ( 3 * val )%11;
}
int tar[N];
int a[N] = {22,41,53,46,30,13,01,67}; 					// tot sum is 8.
int main(){
	int tot = 0;
	for (int i =0; i < 8;i++){
		int x = a[i];
		int tarPos = Hash(x);
		int cnt = 1;
		while ( tar[tarPos] ) tarPos = (tarPos+1)%11,cnt++;		// better option is that 11 will be replaced by constant
		tar[tarPos] = x;
		tot += cnt;
	}
	for (int i = 0;i< 11;i++) printf("%d : %d  \n",i,tar[i]);
	cout<<"The average search length is "<<(tot+3.0)/8<<endl;
	return 0;
}