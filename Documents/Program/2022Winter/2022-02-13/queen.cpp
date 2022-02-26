/***
 * @Author: Zi_Gao
 * @Date: 2022-02-13 16:29:58
 * @LastEditTime: 2022-02-13 17:12:53
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cmath>
using namespace std;
void DFS(int hang);
bool check();
int flagout=false;
int N;
int queen[100];
int flag[100]={0};
inline int read();
int main(){
    // freopen("queen.in","r",stdin);
    // freopen("queen.out","w",stdout);
    N=read();
    DFS(0);
    if(!flagout){
        printf("no solute!");
    }
    printf("%d\n",flagout);
    return 0;
}
void DFS(int hang){
    if(hang==N){
        if(check()){
            flagout++;
            for(int i=0;i<N;i++){
                printf("%d ",queen[i]+1);
            }
            printf("\n");
        }
        return;
    }
    for(int lie=0;lie<N;lie++){
        if(flag[lie]==0){
            queen[hang]=lie;
            flag[lie]=1;
            DFS(hang+1);
            flag[lie]=0;
        }
    }
    return;
}
bool check(){
    bool out=true;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(i==j){
                continue;
            }
            if(abs(i-j)==abs(queen[i]-queen[j])){
                out=false;
                break;
            }
        }
    }
    return out;
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