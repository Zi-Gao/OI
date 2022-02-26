/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 08:03:00
 * @LastEditTime: 2022-02-13 20:41:43
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
unsigned long long mod;
unsigned long long qpow(unsigned long long a, unsigned long long b, unsigned long long mod) {
    unsigned long long ans = 1;
    if(b==0){
        return 1;
    }
    if(b%2==0){
        ans=qpow(a,b/2,mod);
        ans=ans*ans%mod;
    }else{
        ans=qpow(a,b-1,mod);
        ans=ans*a%mod;
    }
    return ans;
}
int main(){
    // freopen("mod.in","r",stdin);
    // freopen("mod.out","w",stdout);
    unsigned long long n,m;
    scanf("%llu %llu %llu",&n,&m,&mod);
    printf("%llu\n",qpow(n,m,mod));
    return 0;
}