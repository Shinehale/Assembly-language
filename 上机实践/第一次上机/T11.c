#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 1003
typedef long long LL;
typedef struct Stack{
	char *elem;
	int top;
	int MAXSIZE;
} Stack;
void init(Stack *S,int size){
	S->MAXSIZE=size;
	S->elem=(char*)malloc(S->MAXSIZE * sizeof(char));
	S->top=0;
}
void push(Stack *S,char c){
	S->elem[S->top]=c;
	S->top++;
}
char pop(Stack *S){
	char c=S->elem[S->top-1];
	S->top--;
	return c;
}
int size(Stack *S){
	return S->top;
}
bool judge(Stack *S,char s[]){
	for (int i=0;i<int(strlen(s));i++){
		switch(s[i]){
			case '[':push(S,s[i]);break;
			case '{':push(S,s[i]);break;
			case '(':push(S,s[i]);break;
			case ')':if (pop(S)!='(') return 0;break;
			case '}':if (pop(S)!='{') return 0;break;
			case ']':if (pop(S)!='[') return 0;break;
		}
	}
	if (size(S)) return 0;
	else return 1;
}
int main(){
	printf("%s\n", "Please input the expression you want to judge:");
	char s[MAX_LENGTH];scanf("%s",s);
	Stack S;
	init(&S,MAX_LENGTH);
	if (judge(&S,s)){
		printf("this expression is absolutely right!");
	}else{
		printf("this expression has something wrong!");
	}
	return 0;
}