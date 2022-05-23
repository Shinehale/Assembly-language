#include<bits/stdc++.h>
using namespace std;
struct node{
	int lr,rs;
	int value;
}
void init(int dep)
void dfs(int fa,int pos){
	if (n[pos].ls==NULL && n[pos].rs == NULL){
		cnt++;
	}
	if (n[pos].ls) dfs(pos,n[pos].ls);
	if (n[pos].rs) dfs(pos,n[pos].rs);
}
int main(){
	cout<<"Please input the depth you want to generate";
} 