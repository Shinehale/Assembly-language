#include<bits/stdc++.h>
using namespace std;
const int Maxsize=1e5+7;
class Stack{
private:
	int size;//栈的大小
	int a[Maxsize];//栈的元素存储地
	int top;//top表示栈顶元素的位置，1默认栈底
public:
	void init_stack(int n){//创建一个空栈，大小为n
		memset(a,0,sizeof(a));
		top=1;size=n;
	}
	void push(int data){//向栈中压入一个元素data
		a[top++]=data;
	}
	int pop(){//弹出栈顶元素
		int data=a[--top];
		return data;
	}
	int stack_size(){//返回栈内元素数
		return size;
	}
	bool stack_empty(){//判断栈内是否为空
		return size==0?1:0;
	}
	void clear_stack(){//将栈内元素清空
		memset(a,0,sizeof(a));
		top=1;
	}
	int get(){//获取栈顶元素但不弹出
		int data=a[top-1];
		return data;
	}
};
Stack S;
int main(){
	S.init_stack(10);
	for (int i=0;i<10;i++){
		int data=rand();
		S.push(data);
		cout<<data<<endl;
	}
	int data=S.pop();
	cout<<data<<endl;
	return 0;
}