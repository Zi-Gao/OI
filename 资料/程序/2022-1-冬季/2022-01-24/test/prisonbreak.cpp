/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 09:54:58
 * @LastEditTime: 2022-01-24 11:37:26
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstring>
#define mod 100003
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
    // freopen("prisonbreak.in","r",stdin);
    // freopen("prisonbreak.out","w",stdout);
    unsigned long long m=read();
    unsigned long long n=read();
    unsigned long long out = 0;
    out=qpow(m,n-2)*(n-1)*m;
    // out%=mod;
    printf("%llu\n",out);
}