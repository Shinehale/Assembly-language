#include<bits/stdc++.h>
using namespace std;

const int N  = 26;

struct Node{
	string s;
	int key;
} HashP[N];



int Hash(string s){
	int val = s[0]-'a';
	return val;
}


void print(){
	for ( int i = 0; i < 26; i++ ){
		int key = i;
		while ( HashP[key].s.length() ){
			if ( Hash(HashP[key].s) == i ) cout<<HashP[key].s<<endl;
			key = ( key + 1 ) % 26;
		}
	}
}


int main(){
	int n; cin>> n ;
	for (int i = 0; i< n ;i++){
		string s;cin>>s;
		int val = Hash(s);
		int key = val;
		while ( HashP[ key ].s.length() ) key = (key+1)%26;
		HashP[key].s = s;
		HashP[key].key = val;
	}
	print();
	return 0;
}
/*
9
absent
chapter
bright
fight_against
extremely
incredible
meaningful
france
aventure

*/