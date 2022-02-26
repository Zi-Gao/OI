/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 18:37:07
 * @LastEditTime: 2022-01-24 20:53:41
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int gcd(int a,int b){
    if(a%b==0) return b;
    return gcd(b,a%b);
}
//quick read
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
    freopen("gcd.in", "r", stdin);
    freopen("gcd.out", "w", stdout);
    int n=read();
    int in;
    int cnt=0;
    for(int i=0;i<n;i++) {
        in=read();
        cnt=0;
        for(int j=1;j<=in;j++){
            for(int k=j;k<=in;k++){
                if(gcd(k,j)==(k^j)){
                    cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
}
