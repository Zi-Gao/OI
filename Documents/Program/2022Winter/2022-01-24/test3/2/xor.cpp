/***
 * @Author: Zi_Gao
 * @Date: 2022-01-25 21:07:44
 * @LastEditTime: 2022-01-25 21:15:00
 * @LastEditors: Zi_Gao
 * @Description: 
 */

#include <cstdio>
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
int main(){
    // freopen("xor.in", "r", stdin);
    // freopen("xor.out", "w", stdout);
    int ans=0;
    int n=read();
    for(int i=0;i<n;i++){
        ans^=read();
    }
    printf("%d",ans);
}