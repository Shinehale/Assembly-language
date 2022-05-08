#include<bits/stdc++.h>
using namespace std;

const int N = 103;
int s[N],fst[N],lst[N];
int vised[N];

bool dfs(int s[],int fst[],int lst[],int v){
    if( !vised[ v ] ){
        vised[ v ] = 1;
        int h,l;
        h = fst[ v ];l = lst[ v ];
        if( h > l ) return true;
        else{
            for(; h<=l; h++){
                return dfs(s, fst, lst, s[h]);
            }
        }

    }else 
        return false;   

}

void judge(int s[],int fst[],int lst[],int n){     
    for(int i = 1;i <= n; i++){
        for(int j = 1;j <= n; j++) vised[j]=0;
        if( dfs(s,fst,lst,i) == false ){
            printf("It has ring"); 
            return ;
        }
    }
    printf("it does't have ring"); 
    
}



int main(){
    s[1]=2;s[2]=3;s[3]=4;s[4]=2;s[5]=6;s[6]=4;
    fst[1]=1;fst[2]=2;fst[3]=3;fst[4]=1;fst[5]=4;fst[6]=6;
    lst[1]=1;lst[2]=2;lst[3]=3;lst[4]=0;lst[5]=5;lst[6]=6;
    judge(s,fst,lst,6);
    
    return 0;
}