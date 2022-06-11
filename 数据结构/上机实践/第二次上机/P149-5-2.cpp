#include<bits/stdc++.h>
using namespace std;

const int N = 1e4+7;
const int M = 1e3+7;

struct tnode{
	string value;
	char cval;
	int lson,rson;
} t[N];


struct node{
	int value;
	int number;					// number--> the number of the tnode 
	bool operator<(const node &x) const{
		return value > x.value;
	}
};
priority_queue<node> que;
map<char,string> func;

int cnt;
int root;
string tarcode;
string ans;


void calc(){
	while ( true ){
		node tmp1 = que.top();
		que.pop();
		if (que.empty()) {
			root = tmp1.number;
			break;
		}
		node tmp2 = que.top();
		que.pop();
		node tmp; tmp.value = tmp1.value + tmp2.value;
		tmp.number = ++cnt;
		que.push( tmp );
		tnode newNode; newNode.lson = tmp1.number;
		newNode.rson = tmp2.number;
		newNode.cval = '#';
		t[cnt] = newNode;
	}
}

void dfs( int x ){
	if ( t[x].lson ) {
		t[ t[x].lson ].value = t[x].value+'0';
		dfs( t[x].lson );
	}
	if ( t[x].rson ){
		t[  t[x].rson ].value = t[x].value+'1';
		dfs( t[x].rson );
	}
}

void encode(string s){
	cout<<"The corresponding encoding is:"<<endl;
	for (int i = 0; i < int(s.length());i++)
		tarcode += func[s[i]];
	cout<<tarcode<<endl;
}	

void dfsWords(int r,int x){
	if ( r == int(tarcode.length())-1) return;
	if ( t[x].lson == 0 && t[x].rson == 0 ) {
		ans += t[x].cval;
		dfsWords( r,root );
		return;
	}
	if ( tarcode[r] == '1' ) dfsWords(r+1,t[x].rson);
	if ( tarcode[r] == '0' ) dfsWords(r+1,t[x].lson);
}
void decode(){
	cout<<"The corresponding decoding is:"<<endl;
	dfsWords(0,root);
	cout<<ans<<endl;
}
int main(){

	tnode tmp;tmp.cval = ' '; tmp.lson = 0;tmp.rson = 0;t[ ++cnt ] = tmp;
	node newNode;newNode.value = 186; newNode.number = cnt;
	que.push(newNode);
	//  The data of character space has been set up advanced.
	int n; cin>>n;
	for (int i = 0; i <n ; i++ ){
		char c = 'A'+i;
		int val; cin >> val;
		tnode tmp; 
		tmp.cval = c;
		tmp.lson = 0;tmp.rson = 0;
		t[ ++cnt ] = tmp;
		node newNode;newNode.value = val;newNode.number = cnt;
		que.push(newNode);
	}
	char c; cin>>c;											// read the last enter at the end of the line
	string s;getline(cin,s);
	s=c+s;
	
	calc();
	dfs(root);
	for (int i = 1;i <= cnt; i++ ) 
		if ( t[i].cval!='#' ) {
			cout<<t[i].cval<<":"<<t[i].value<<endl;
			func[t[i].cval] = t[i].value;
		}
	encode(s);
	decode();
	return 0;
}
/*
Input sample:
26
64 13 22 32 103 21 15 47 57 1 5 32 20 57 63 15 1 48 51 80 23 8 18 1 16 1
THIS PROGRAM IS MY FAVORITE
*/