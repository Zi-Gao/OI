/***
 * @Author: Zi_Gao
 * @Date: 2022-01-26 11:08:50
 * @LastEditTime: 2022-01-26 11:39:28
 * @LastEditors: Zi_Gao
 * @Description: 
 */

const unsigned long long mod = 1234567;
#include <cstdio>
inline unsigned long long read(){
    unsigned long long x=0,f=1;char c=getchar();
    while(c<'0'||c>'9')c=='-'?f=-1:f,c=getchar();//?=if,:=else
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c&15);
        c=getchar();
    }
    return x*f;
}
long long qpowmod(long long a,long long n){//快速幂递归-取模
    if(n==0){
        return 1LL;
    }else if(n%2==1){
        return a*qpowmod(a,n-1)%mod;
    }else{
        unsigned long long t=qpowmod(a,n/2)%mod;
        return t*t%mod;
    }
}
int main(){
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);

    unsigned long long N=read();
    unsigned long long out=0;
    for(unsigned long long i=0;i<N/2;i++){
        unsigned long long t=1;
        for(unsigned long long j=1;j<=i;j++){
            t=(t*(N-j))%mod;
        }
        out+=t;
    }
    out=(out*2)%mod;
    if(N%2==0){
        unsigned long long t=1;
        for(unsigned long long j=1;j<=N/2;j++){
            t=(t*(N/2-j))%mod;
        }
        out+=t*2;
    }else{
        out+=qpowmod(2,N/2);
    }
    printf("%d\n",out%mod);
    return 0;
}