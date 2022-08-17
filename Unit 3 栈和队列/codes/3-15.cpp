#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define OVERFLOW -1
#define ERROR 1
typedef int Status;
 
typedef struct
{
 int *base[2];
 int *top[2];
}BDStack;
 
Status InitStack(BDStack &s,int m)
{
  s.base[0]=(int*)malloc(m*sizeof(int));
  s.base[1]=s.base[0]+m;
  s.top[0]=s.base[0];
  s.top[1]=s.base[1];
  return OK;
}
 
Status push(BDStack &s,int i,int x)
{
     if(s.top[0]>s.top[1]) return OVERFLOW;
     if(i==0)  *s.top[0]++=x;
     else if(i==1) *s.top[1]--=x;
     else return ERROR;
     return OK;
}
 
Status pop(BDStack &s,int i,int x)
{
     if(i==0)
     {
          if(s.top[0]==s.base[0]) return OVERFLOW;
          x=*--s.top[0];
        }
        else if(i==1)
        {
             if(s.top[1]==s.base[1]) return OVERFLOW;
             x=*++s.top[1];
        }
     else return ERROR;
     return OK;
}
 
void PrintfStack(BDStack &s)
{
     while(s.base[0]<=s.top[0])
     {
          printf("%d ",*s.top[0]);
          s.top[0]--;
        }
        while(s.top[1]<=s.base[1])
        {
             printf("%d ",*s.top[1]);
             s.top[1]++;
        }
}
 
int main()
{
     int m,i;
     BDStack s;
     printf("please input the length of the stack: ");
     scanf("%d",&m);
     InitStack(s,m);
     for(i=0; i<(m-2)/2; i++)
     {
          push(s,0,i);
     }
     for(i=0; i<(m-2)/2 ; i++)
     {
          push(s,1,i);
        }
        s.top[0]--;
     s.top[1]++;
        PrintfStack(s);
        return 0;
}
