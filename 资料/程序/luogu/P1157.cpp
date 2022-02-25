/***
 * @Author: Zi_Gao
 * @Date: 2022-02-14 11:40:20
 * @LastEditTime: 2022-02-20 14:50:04
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;
inline int read();
int N=6;
int K=3;
int arr[100];
void DFS(int step,int plus);
int main(){
    // freopen("1.txt","w",stdout);
    N=read();
    K=read();
    DFS(0,0);
    return 0;
}
void DFS(int step,int plus){
    if(step==K){
        if(arr[K-1]!=0){
            for(int i=0;i<K;i++){
                printf("%3d",arr[i]);
            }
            printf("\n");
        }
        return;
    }

    for(int i=plus+1;i<=N;i++){
        arr[step]=i;
        DFS(step+1,i);
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