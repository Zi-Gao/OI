/***
 * @Author: Zi_Gao
 * @Date: 2022-02-14 14:32:59
 * @LastEditTime: 2022-02-14 14:55:39
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define int unsigned long long
inline int read();
char in[1100000]={0};
int arr[1100000];
signed main(){
    int N;
    int M;
    int total=0;

    N=read();
    M=read();

    for(int i=0;i<N;i++){
        arr[i]=read();
    }
    for(int i=0;i<N;i++){
        int tmp=0;
        for(int j=i;j<N;j++){
            tmp=(tmp%M+arr[j]%M)%M;
            if(tmp==0){
                total=total+1;
            }
        }
    }
    printf("%d",total);

    return 0;
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