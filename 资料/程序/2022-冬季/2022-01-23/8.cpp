/***
 * @Author: Zi_Gao
 * @Date: 2022-01-23 19:15:52
 * @LastEditTime: 2022-01-23 19:24:02
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#define MOD 1000000007
int qpow(int a,int n){//快速幂递归
    if(n==0){
        return 1;
    }else if(n%2==1){
        return a*qpow(a,n-1);
    }else{
        int t=qpow(a,n/2);
        return t*t;
    }
}
long long qpow(long long a,long long n){//快速幂非递归
    long long ans=1;
    while(n){
        if(n&1){
            ans=ans*a;
        }
        a=a*a;
        n>>=1;
    }
    return ans;
}
long long qpowmod(long long a,long long n){//快速幂递归-取模
    if(n==0){
        return 1LL;
    }else if(n%2==1){
        return a*qpow(a,n-1)%MOD;
    }else{
        int t=qpow(a,n/2)%MOD;
        return t*t%MOD;
    }
}
int pow(int a,int n){//经典幂
    if(n==0){
        return 1;
    }else if(n%2==1){
        return a*pow(a,n-1);
    }else{
        int t=pow(a,n/2);
        return t*t;
    }
}
int main(){
    
}