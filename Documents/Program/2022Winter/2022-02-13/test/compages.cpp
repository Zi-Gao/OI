/***
 * @Author: Zi_Gao
 * @Date: 2022-02-13 08:31:12
 * @LastEditTime: 2022-02-13 08:53:09
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;
inline int read();
void DFS(int step);
bool flag[100]={0};
int num[100]={0};
int N,R;
int main(){
    freopen("compages.in","r",stdin);
    freopen("compages.out","w",stdout);
    N=read();R=read();
    DFS(1);

    return 0;
}
void DFS(int step){
    if(step==R+1){
        for(int i=1;i<=R;i++){
            printf("%d",num[i]);
        }
        printf("\n");
        return;
    }else{
        for(int i=num[step-1]+1; i<=N; i++){
            num[step]=i;
            DFS(step+1);
        }
        return;
    }
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