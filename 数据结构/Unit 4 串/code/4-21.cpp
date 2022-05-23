#include<bits/stdc++.h>
using namespace std;
const int MAXLENGTH=1e3+7;
typedef struct Chunk{
	char c;
	struct Chunk *next;
}Chunk;
typedef struct{
	Chunk *head,*tail;
	int curlen;
}LString;
void clear(Chunk *p){
	p->c='\0';
	p->next=NULL;
}
void Output(LString *str){
	Chunk *p=str->head;
	while (p!=str->tail){
		printf("%c",p->c);
		p=p->next;
	}
}
void strAssign(char s[],LString *str){
	str->head=(Chunk*)malloc(sizeof(Chunk));clear(str->head);
	Chunk *p=str->head;
	for (int i=0;i<int(strlen(s));i++){
		p->c=s[i];
		Chunk* newChunk=(Chunk*)malloc(sizeof(Chunk));clear(newChunk);
		p->next=newChunk;
		p=p->next;
	}
	str->tail=p;
	p->c='\0';
	str->curlen=strlen(s);
	printf("strAssign API shows:\n");
	Output(str);
}
void strCopy(LString *s1,LString *s2){
	s1->head=(Chunk*)malloc(sizeof(Chunk));clear(s1->head);
	Chunk *p=s2->head,*pp=s1->head;
	while (p!=s2->tail){
		pp->c=p->c;
		Chunk* newChunk=(Chunk*)malloc(sizeof(Chunk));clear(newChunk);
		pp->next=newChunk;
		pp=pp->next;
		p=p->next;
	}
	s1->tail=pp;
	pp->c='\0';
	s1->curlen=s2->curlen;
	printf("\nstrCopy API shows:\n");
	Output(s1);
}
void strCompare(LString *s1,LString *s2){
	bool ans=false;
	Chunk *p1=s1->head,*p2=s2->head;
	while (p1!=s1->tail&&p2!=s2->tail){
		if (p1->c>p2->c) {ans=true;break;}
		if (p1->c>p2->c) {ans=false;break;}
		p1=p1->next;
		p2=p2->next;
	}
	printf("strCompare API shows:\n");
	if (ans) {
		Output(s1);cout<<">";Output(s2);
	}
	else{
		Output(s1);cout<<"<";Output(s2);
	}
}
void strLength(LString *s1){
	printf("\n%s\n","strLength API shows:");
	Output(s1);
	printf("  length is %d\n",s1->curlen);
}
void strConcat(LString *s,LString *s1,LString *s2){
	s->head=(Chunk*)malloc(sizeof(Chunk));clear(s->head);
	Chunk *p1=s1->head,*p2=s2->head,*p=s->head;
	while (p1!=s1->tail){
		p->c=p1->c;
		Chunk* newChunk=(Chunk*)malloc(sizeof(Chunk));clear(newChunk);
		p->next=newChunk;
		p=p->next;
		p1=p1->next;
	}
	while (p2!=s2->tail){
		p->c=p2->c;
		Chunk* newChunk=(Chunk*)malloc(sizeof(Chunk));clear(newChunk);
		p->next=newChunk;
		p=p->next;
		p2=p2->next;
	}
	s->tail=p;
	p->c='\0';
	s->curlen=s1->curlen+s2->curlen;
	printf("%s\n","strConcat API is:");
	Output(s);
}
void strSubstring(LString *s,LString *s1,int pos,int size){
	s->head=(Chunk*)malloc(sizeof(Chunk));clear(s->head);
	Chunk *p1=s1->head,*p=s->head;
	int cnt=0;
	while (p1!=s1->tail){
		if (cnt==pos) break;
		p1=p1->next;
		cnt++;
	}
	cnt=0;
	while (p1!=s1->tail){
		p->c=p1->c;
		Chunk* newChunk=(Chunk*)malloc(sizeof(Chunk));clear(newChunk);
		p->next=newChunk;
		p=p->next;
		p1=p1->next;
		cnt++;
		if (cnt==size) break;
	}
	printf("\n%s\n","strSubstring API shows:");
	Output(s);

}
int main(){
	char s[MAXLENGTH],t[MAXLENGTH];printf("%s\n","Please input the string:");
	scanf("%s",s);LString str,str1,str2,str3;
	strAssign(s,&str);
	strCopy(&str1,&str);
	printf("\n%s\n","Please input the string you want to compare:");
	scanf("%s",t);strAssign(t,&str1);
	strCompare(&str,&str1);
	strLength(&str);
	strConcat(&str2,&str,&str1);
	strSubstring(&str3,&str2,3,10);
	return 0;
}