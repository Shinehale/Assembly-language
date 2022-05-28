#include <stdio.h>
#include <stdlib.h>
#define initsize 100
#define addsize 10

typedef struct
{
    char *base;
    int top,stacksize;
}sqstack;

int init_stack(sqstack &s)
{
    s.base=(char*)malloc(initsize*sizeof(char));
    if(!s.base)exit(-1);
    s.top=0;
    s.stacksize=initsize;
    return 1;
}

int push(sqstack &s,char e)
{
    char *newbase;
    if(s.top==s.stacksize)
    {
        newbase=(char*)realloc(s.base,(s.stacksize+addsize)*sizeof(char));
        s.base=newbase;
        s.stacksize+=addsize;
    }
    s.base[s.top++]=e;
    return 1;
}
int pop(sqstack &s,char &e)
{
    if(!s.top)return 0;
    e=s.base[--s.top];
    return 1;
}

int stackempty(sqstack s)
{
        return !s.top;
}

typedef struct
{
    char data[initsize];
    int rear,head;

}sqqunue;

void init_qunue(sqqunue &q)
{
    q.rear=q.head=0;
}

int ensqunue(sqqunue &q,char e)
{
     if ((q.rear + 1) % initsize == q.head)
        {
                return 0;
        }
        q.data[q.rear] = e;
        q.rear = (q.rear + 1) % initsize;
        return 1;
}

int delsqunue(sqqunue &q,char &e)
{
    if(q.head==q.rear)return 0;
    e=q.data[q.head];
    q.head=(q.head+1)%initsize;
    return 1;

}

int sanshiyi(char *p)
{
    sqqunue q;
    sqstack s;
    char e1,e2;
    init_qunue(q);
    init_stack(s);
    while(*p)
    {
        push(s,*p);
        ensqunue(q,*p);
        p++;
    }
    while(!stackempty(s))
    {
        pop(s,e1);
        delsqunue(q,e2);
        if(e1!=e2)return 0;
    }
    return 1;
}

int main()
{
    char p[100];
    int k;
    gets(p);
    k=sanshiyi(p);
    if(k==1)printf("YES");
    else printf("NO");
    return 0;

}
