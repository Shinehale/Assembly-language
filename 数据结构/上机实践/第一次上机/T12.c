#include<stdlib.h>
#include<stdio.h>
typedef long long LL;
typedef struct Stack{
	int *elem;
	int top;
	int MAXSIZE;
} Stack;
void init(Stack *S,int size){
	S->MAXSIZE=size;
	S->elem=(int*)malloc(S->MAXSIZE * sizeof(int));
	S->top=0;
}
void push(Stack *S,int value){
	S->elem[S->top++]=value;
}
int pop(Stack *S){
	int value=S->elem[--S->top];
	return value;
}
int empty(Stack *S){
	return S->top==0?1:0;
}
void calc(Stack *S,LL value){
	while (value){
		int newvalue=value%2;
		push(S,newvalue);
		value>>=1;
	}
	printf("%s\n","the converted value is:");
	while (!empty(S)){
		int topValue=pop(S);
		printf("%d",topValue);
	}

}
int main(){
	printf("%s\n", "Please input the number you want to convert:");
	LL value;scanf("%lld",&value);
	Stack S;
	init(&S,64);// the max number of long long is 2^63-1
	calc(&S,value);
	return 0;
}