/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 09:45:24
 * @LastEditTime: 2022-01-24 11:02:58
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
inline unsigned long long mod;
inline unsigned long long read (){
    //quick read
    unsigned long long x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch&'-') f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9'){
        x = x*10 + ch - '0';
        ch = getchar();
    }
    return x*f;
}
unsigned long long qpow(unsigned long long a,unsigned long long b){
    unsigned long long ans = 1;
    while (b){
        if (b&1) ans = ans*a%mod;
        a = a*a%mod;
        b >>= 1;
    }
    return ans;
}
int main(){
    freopen("circle.in","r",stdin);
    freopen("circle.out","w",stdout);
    mod=read();//人
    unsigned long long m=read();//移动
    unsigned long long k=read();//10^k
    unsigned long long x=read();//a人
    unsigned long long ans=(x+(m%mod)*(qpow(10,k)%mod))%mod;
    printf("%llu",ans);
}