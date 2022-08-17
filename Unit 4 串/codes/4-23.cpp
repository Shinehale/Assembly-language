#include<stdio.h>
#include<stdlib.h>
#define Size 4
typedef struct node{

    int a[Size],top;

}sqstack;

void init(sqstack & L){

   int x;  L.top=-1;
   if(L.top==Size-1) return ;
   for(int i=0;i<Size;i++){
      printf("请输入要储存的数据：");
      scanf("%d", &x);
      L.a[++L.top]=x;  
   }
}

void output(sqstack & L){
   if(L.top==-1) return;
   while(L.top!=-1){  
   int x=L.a[L.top--];  
   printf("该链表的数据有：%d",x);
   printf("\n");  }
} //出栈  

void trans(sqstack & L){   
   if(L.top==-1) return;
   int p=1,o=0,y=0; //o是余数
   for(int i=0;i<Size;i++){
      while(L.a[i]>=1){  
      o=L.a[i]%2;
      y=p*o+y;
      p=p*10;
      L.a[i]=L.a[i]/2;
      }        
   printf("转换后为：%d\n",y);
   o=y=0;p=1;  
   }
}

void trans1 (sqstack & L) {
   int num2, p=1,o=0,y=0; //o是余数
   for(int i=0;i<Size;i++){   
      while(L.a[i]>=1){
         o=L.a[i]%8;
         y=p*o+y;  
         p=p*10;
         L.a[i]=L.a[i]/8;      
      }  
      printf("转换后为：%d\n",y);     y=0; p=1;o=0;  
   }
}  

int main(){  
   sqstack L;int num1,b;
   init(L);
   printf("请输入要转换的进制：");
   scanf("%d",&b) ;
   switch(b){     
      case 2: trans(L);break;
      case 8:trans1 (L);break;   
   }    
   return 0;
}