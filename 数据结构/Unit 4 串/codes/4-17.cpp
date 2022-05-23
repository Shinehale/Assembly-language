#include<bits/stdc++.h>
using namespace std;
string replace(string s,string t,string str){
	string ans=s;
	while  (0<=ans.find(t)&&ans.find(t)<ans.length()){
		int pos=ans.find(t);
		string tmp=ans;
		tmp.replace(pos,t.length(),str);
		ans=tmp;
	}
	return ans;
}
int main(){
	cout<<"Please input the string you want to function:\n";
	string s,t,str;cin>>s;
	cout<<"Please input the string you want to replace:\n";
	cin>>t;
	cout<<"Please input the string you want to replace with:\n";
	cin>>str;
	string ans=replace(s,t,str);
	cout<<"the final string you want is:\n"<<ans<<endl;
	return 0;
}
// use the kown function of String to rewrite the function we want