/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 09:54:58
 * @LastEditTime: 2022-01-24 15:01:45
 * @LastEditors: Zi_Gao
 * @Description: 
 */

#include <cstdio>
#include <cstring>
unsigned long long mod=100003;
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
    // unsigned long long m=read();
    // unsigned long long n=read();
    // //output m^n-m(m-1)^(n-1)
    // printf("%llu",(qpow(m,n)-m*qpow(m-1,n-1))%mod);
    for(int i=100000; i<100010; i++){
        for(int j=100000; j<100010; j++){
            if((i%mod-j%mod)%mod==(j-i)%mod){
                printf("%d %d ture\n",i,j);
            }else{
                printf("%d %d false\n",i,j);
            }
        }
    }
}