/***
 * @Author: Zi_Gao
 * @Date: 2022-02-20 14:34:26
 * @LastEditTime: 2022-02-26 21:13:43
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
void DFS(int hang);
void doflag(int x,int y);
int flagout=0;
int N;
int queen[100];
bool flag[100][100]={0};
inline int read();
int main(){
    // freopen("queen.in","r",stdin);
    // freopen("queen.out","w",stdout);
    N=read();
    memset(queen,-1,sizeof(queen));
    DFS(0);
    printf("%d\n",flagout);
    return 0;
}
void DFS(int hang){
    if(hang==N){
        if(flagout<3&&queen[N]!=-1){
            for(int i=0;i<N;i++){
                printf("%d ",queen[i]);
            }
            printf("\n");
        }
    }
    for(int i=0;i<N;i++){
        if(flag[hang][i]==false){
            flag[hang][i]=true;
            queen[hang]=i;
            doflag(hang,i);

            DFS(hang+1);

            doflag(hang,i);
            queen[hang]=-1;
            flag[hang][i]=false;
        }
    }
}
void doflag(int x,int y){
    int i=x,j=y;
    while(i>=0){
        flag[i][j]^=1;
        i--;
    }

    i=x,j=y;
    while(j>=0){
        flag[i][j]^=1;
        j--;
    }

    i=x,j=y;
    while(i<N){
        flag[i][j]^=1;
        i++;
    }

    i=x,j=y;
    while(j<N){
        flag[i][j]^=1;
        j++;
    }

    i=x,j=y;
    while(i>=0&&j<N){
        flag[i][j]^=1;
        i--;
        j++;
    }

    i=x,j=y;
    while(i<N&&j<N){
        flag[i][j]^=1;
        i++;
        j++;
    }

    i=x,j=y;
    while(i>=0&&j>=0){
        flag[i][j]^=1;
        i--;
        j--;
    }

    i=x,j=y;
    while(i<N&&j>=0){
        flag[i][j]^=1;
        i++;
        j--;
    }

    return;
}
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}