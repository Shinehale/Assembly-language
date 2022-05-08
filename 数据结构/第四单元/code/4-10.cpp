#include<bits/stdc++.h>
using namespace std;
string reverse(string s){
	string ansString="";
	for (int i=s.length()-1;i>=0;i--)
		ansString+=s[i];
	return ansString;
}
int main(){
	string s;cin>>s;
	cout<<reverse(s) ;
	return 0;
}


 
//string inner function are as follows:
//substr(start,size) from start position cut a string whose length is size.
//find(str) in the S check the str  if so return the position 
//empty() check whether the string is empty?
//replace(start,size,str2)  in the S from the start postion count the number of size string replace it with str2
//reverse(str.begin(),str.end()) reverse the string just from the begin to the end 
//length()  return the string's length
//insert(start,str,size) in the S string,from the start postion count the number of size string insert the str
//c_str() string convert to char[] 