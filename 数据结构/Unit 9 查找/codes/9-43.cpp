/*
In this program we would not case sensitive 区分大小写
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+7;

struct Node{
	int val;
	int num;
	int ch[26];
} P[N];
int cnt;

void insert(string s){
	int now = 0;								// number zero is the fake root.
	for ( int i = 0 ; i < int(s.length()); i++ ){
		int val = s[i]-'a';
		if ( !P[now].ch[val] ) {
			cnt++;
			P[cnt].val = val;
			P[now].ch[val] = cnt;
		}
		now = P[now].ch[val];
	}
	P[now].num++;
}
void Delete(string s){
	int now = 0;								// number zero is the fake root.
	for ( int i = 0 ; i < int(s.length()); i++ ){
		int val = s[i]-'a';
		if ( !P[now].ch[val] ) {
			cout<<"the "<<s<<"  is not found!"<<endl;
			return;
		}
		now = P[now].ch[val];
	}
	P[now].num--;
	cout<<"the "<<s<<" is deleted."<<endl;
}

int main(){
	int n; cin >> n;
	while ( n-- ){
		string s; cin>>s;
		insert(s);
	}
	int m; cin >> m;
	while ( m-- ){
		string s;
		cin >> s;
		Delete ( s ); 
	}
	return 0;
}
/*
Input Sample:
5
chart
chinese
longest
linguistic
challenge
2
longst
linguistic
*/