/***
 * @Author: Zi_Gao
 * @Date: 2022-02-20 14:52:11
 * @LastEditTime: 2022-02-20 14:54:48
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <algorithm>
using namespace std;
inline int read();
int main(){
    int n=read(),m=read();
    int arr[m]={0};
    for(int i=0;i<m;i++){
        arr[i]=read();
    }
    sort(arr,arr+m);
    //output
    for(int i=0;i<m;i++){
        printf("%d ",arr[i]);
    }

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