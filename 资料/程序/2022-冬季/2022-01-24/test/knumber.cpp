/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 09:08:07
 * @LastEditTime: 2022-01-24 10:52:32
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define mod 200907
//quick read
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
    freopen("knumber.in","r",stdin);
    freopen("knumber.out","w",stdout);
    unsigned long long n=read();
    while(n){
        unsigned long long a = read();
        unsigned long long b = read();
        unsigned long long c = read();
        unsigned long long d = read();
        unsigned long long out;
        if(a-b==b-c){
            unsigned long long gc=b-a;
            unsigned long long out=(a%mod+((d-1)%mod)*(gc%mod))%mod;
            printf("%llu\n",out);
        }else{
            long double gb=b/a;
            unsigned long long out=qpow(gb,d-1)*a%mod;
            printf("%llu\n",out);
        }
        n--;
    }
}