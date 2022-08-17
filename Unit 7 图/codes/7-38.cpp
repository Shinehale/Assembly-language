#include<bits/stdc++.h>

const int MAX = 2000;

typedef struct node{
    int tag;
    char elem;
    int prio;
}Node;

typedef struct binTreeNode{
    Node data;
    struct binTreeNode *left,*right;
}BinTreeNode;

typedef struct newString{
    Node data[MAX];
    int length;
}NewString;

void InitString(NewString *S){
    char str[MAX];
    int len,baselevel = 0;
    scanf("%s",str);
    len = strlen(str);
    for(int i=0;i<len;i++){
        S->data[i].elem = str[i];
		if (str[i]=='+'||str[i]=='-'){
			S->data[i].tag = 1;
			S->data[i].prio = baselevel+1;
		}
		else if (str[i] == '*' || str[i] == '/'){
			S->data[i].tag = 1;
			S->data[i].prio = baselevel+2;
		}
		else if (str[i] == '('){
			S->data[i].tag = 0;
			baselevel = baselevel + 2;
		}
		else if (str[i] == ')'){
			S->data[i].tag = 0;
			baselevel = baselevel - 2;
		}
		else{
			S->data[i].tag = 0;
		}
    }
    S->length = len;
}

void RemoveExtraBrackets(NewString *S){
    int level = 0;
    if(S->data[0].elem=='('&&S->data[S->length-1].elem==')'){
        for(int i=0;i<S->length-1;i++){
            if(S->data[i].elem=='('){
            level++;
            }
            else if(S->data[i].elem==')'){
            level--;
            }
            if(level==0){
            return;
            }
        }
        for(int i=1;i<S->length-1;i++){
            S->data[i-1] = S->data[i];
        }
        S->length = S->length - 2;
    }
}

int FIndMinPositive(NewString *S){
    int positive=0,min=MAX;
    for(int i=0;i<S->length;i++){
        if(S->data[i].prio<=min&&S->data[i].tag==1){
            min = S->data[i].prio;
            positive = i;
        }
    }
    return positive;
}

void CreatTree(BinTreeNode *T, NewString *S){
    NewString *left,*right;
    left = (NewString*)malloc(sizeof(NewString));
    right = (NewString*)malloc(sizeof(NewString));
    int midpositive,len;
    len = S->length;
    if(len==1){
        T->data = S->data[len-1];
        T->left = NULL;
        T->right = NULL;
    }
    else if(len>1){
        midpositive = FIndMinPositive(S);
        left->length = midpositive;
        for(int i = 0;i < midpositive;i++){
            left->data[i] = S->data[i];
        }
        right->length = S->length-midpositive-1;
        for(int i=0;i<right->length;i++){
            right->data[i] = S->data[i+midpositive+1];
        }
        RemoveExtraBrackets(left);
        RemoveExtraBrackets(right);
        T->data = S->data[midpositive];
        T->left = (BinTreeNode*)malloc(sizeof(BinTreeNode));
        T->right = (BinTreeNode*)malloc(sizeof(BinTreeNode));
        CreatTree(T->left,left);
        CreatTree(T->right,right);
    }
}

void Output(BinTreeNode* T){
    if(T->left==NULL&&T->right==NULL){
        printf("%c",T->data.elem);
    }
    else{
        Output(T->left);
        Output(T->right);
        printf("%c",T->data.elem);
    }
}

int main(){
    NewString *S;
    S = (NewString*)malloc(sizeof(NewString));
    S->length = 0;
    InitString(S);
    RemoveExtraBrackets(S);
    BinTreeNode *T;
    T = (BinTreeNode*)malloc(sizeof(BinTreeNode));
    CreatTree(T,S);
    Output(T);
    return 0;
}

