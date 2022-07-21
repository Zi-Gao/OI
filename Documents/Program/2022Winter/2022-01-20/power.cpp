/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 08:03:00
 * @LastEditTime: 2022-02-13 20:41:43
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;

int qpow(int base,int exponential,int mod);

int main(){

}

int qpow(int base,int exponential,int mod){
    int res = 1;
    base%=mod;
    while(exponential){
        if(exponential&1)
            res=(res*base)%mod;
        base=(base*base)%mod;
        exponential>>=1;
    }
    return res;
}