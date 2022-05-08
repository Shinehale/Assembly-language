#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
struct Node{
	char data;
	int ls,rs;
	int index;
};
Node n[N];
Node calc(string s){
	int tot=0;
	stack<Node> S;
	string tmp="+-*/";
	for (int i=s.length()-1;i>=0;i--){
		int value=tmp.find(s[i]);
		if (value>=0&&value<4){
			Node p1=S.top();S.pop();
			Node p2=S.top();S.pop();
			tot++;
			n[tot].data=s[i];n[tot].index=tot;
			n[tot].ls=p1.index;n[tot].rs=p2.index;
			S.push(n[tot]);
		}
		else{
			tot++;
			n[tot].data=s[i];n[tot].index=tot;
			n[tot].ls=0;n[tot].rs=0;
			S.push(n[tot]);
		}
	}
	Node root=S.top();
	S.pop();
	return root;
}
void dfs(int pos,string &s){
	if (n[pos].ls!=0) dfs(n[pos].ls,s);
	if (n[pos].rs!=0) dfs(n[pos].rs,s);
	s+=n[pos].data;
}
int main(){
	cout<<"Please input the prefix expression you want to convert:\n";
	string s;cin>>s;
	Node root=calc(s);
	string ans;
	dfs(root.index,ans);
	cout<<"the postfix expression is:\n"<<ans<<endl;
	return 0;
}
//-+1*+2345 -> 123+4*+5-
// reversely construct the tree and Postoder traverse the tree and finally get the answer.
