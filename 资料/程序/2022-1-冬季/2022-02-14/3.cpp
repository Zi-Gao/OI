/***
 * @Author: Zi_Gao
 * @Date: 2022-02-14 10:55:56
 * @LastEditTime: 2022-02-14 11:19:01
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;
inline int read();
int N=8;
int arr[100];
void DFS(int step,int plus);
int main(){
    DFS(0,1);
    return 0;
}
void DFS(int step,int plus){
    int flag = 0;
    for(int i=0;i<step;i++){
        flag+=arr[i];
        if(flag==N){
            printf("%d=%d",N,arr[0]);
            for(int i=1;i<step;i++){
                printf("+%d",arr[i]);
            }
            printf("\n");
            return;
        }
    }

    if(step==N){
        return;
    }
    for(int i=plus;i<N;i++){
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