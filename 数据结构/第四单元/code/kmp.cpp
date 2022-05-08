#include<bits/stdc++.h>
using namespace std;
class Hstring{
private:
	char *ch;
	int length;
	int *next;
	int *nextVal;
public:
	Hstring(string s);
	~Hstring();
	friend int kmp(Hstring S,Hstring T,int pos);
	void getnext();
	void setString(string s);
	void output_next();
	void getNextVal();
};
void Hstring::getnext(){
	int i=1,j=0;
	while (i<length){
		if (j==0||ch[i]==ch[j]) {++i;++j;next[i]=j;}
		else j=next[j];
	}
}
void Hstring::output_next(){
	for (int i=0;i<length;i++) printf("%d ",next[i+1]);
	cout<<endl;
}
Hstring::Hstring(string s){
	length=s.length();
	ch=(char*)malloc(sizeof(char)*(length+1));
	next=(int*)malloc(sizeof(int)*(length+1));
	nextVal=(int*)malloc(sizeof(int)*(length+1));
	for (int i=0;i<length;i++){
		ch[i+1]=s[i];
		next[i+1]=0;
		nextVal[i+1]=0;
	}
}
Hstring::~Hstring(){
	free(ch);
	free(next);
	free(nextVal);
	ch=NULL;
	next=NULL;
	nextVal=NULL;
	length=0;
}
void Hstring::getNextVal(){
	int i=1,j=0;nextVal[1]=0;
	while (i<length){
		if (j==0||ch[i]==ch[j]){
			++i;++j;
			if (ch[i]!=ch[j]) nextVal[i]=j;
			else nextVal[i]=nextVal[j];
		}
		else j=nextVal[j];
	}
	for (int i=1;i<length+1;i++) printf("%d ",nextVal[i]);
	printf("\n");
}
int kmp(Hstring S,Hstring T,int pos){
	int i=pos,j=1;
	while (i<=S.length&&j<=T.length){
		if (j==0||S.ch[i]==T.ch[j]) {i++;j++;}
		else j=T.next[j];
	}
	if (j>T.length) return i-T.length;
	else return 0;
}
int main(){
	printf("Please input the string you want to find:\n");
	string s;cin>>s;
	Hstring S(s);
	printf("Please input the string you want to check:\n");
	string t;cin>>t;
	Hstring T(t);
	T.getnext();
	T.getNextVal();
	T.output_next();
	int ans=kmp(S,T,1);
	printf("the ans is %d",ans);
	return 0;
}