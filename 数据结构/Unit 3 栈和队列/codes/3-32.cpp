#include <stdio.h>
#include <stdlib.h>
#define maxsize 100
typedef struct
{
    int base[maxsize];
    int head,rear;
}qunue;
/*初始化队列*/
init_qunue(qunue &q)
{
    q.head=q.rear=0;
    return 1;
}

int Fib(int k,int n)
{
    int i,sum,j;
    qunue q;
    int m;
    init_qunue(q);
    for(i=0;i<k-1;i++)q.base[i]=0;
    q.base[k-1]=1;
    for(i=k;i<=n;i++)
    {
        m=i%k;        sum=0;
        for(j=0;j<k;j++)
            sum+=q.base[(m+j)%k];
        q.base[m]=sum;

    }
    return sum;
}
 int main()
 {
     int x,k,n;
     printf("输入max：");
     scanf("%d",&x);
     printf("输入Fib数列阶数：");
     scanf("%d",&k);
     for(n=1;;n++)
     {
         if(Fib(k,n)<=x&&Fib(k,n+1)>x)break;
     }
     printf("n值为:%d\n",n);
     return 0;
 }