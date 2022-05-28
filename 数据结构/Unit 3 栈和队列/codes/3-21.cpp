//[5+(6-3)]-(2+3)
#include <iostream>
#include <stack>
#include <string> 

using namespace std;

bool match(char left, char right){
	if((left == '(' && right == ')' ) || (left == '[' && right == ']') || (left == '{' && right == '}' )){//这里不能用双引号！！！
		return true;
	}
	return false;
}

int main(int argc, char** argv) {
	int flag = 0;
	stack<char> s;	
	string str;
	getline(cin, str);	
	for(int i=0; i<str.length(); i++){
		char tmp = str[i];
		switch(tmp){	 
			case '(':
			case '[':
			case '{':
				s.push(tmp);	
				break;
			case ')':
			case ']':
			case '}':
				{
					if(s.empty()){
						cout << "no" << endl;
						flag = 1;
						break;
					}
					else{
						char t = s.top();
						if(!match(t, tmp)){
							cout << "no" << endl;
							flag = 1;
							break;
						}
						else{
							s.pop();
							break; 
						}
					}
				}
			default: ;
		}
		if(flag == 1){
			break;
		}
	}
	if(flag != 1){
		if(!s.empty()){	
			cout << "no" << endl;
		}
		else{ 
			cout << "yes" << endl; 
		}
	} 
	return 0;
}
