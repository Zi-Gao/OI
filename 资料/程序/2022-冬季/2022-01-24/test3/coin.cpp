/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 19:16:23
 * @LastEditTime: 2022-01-24 20:23:00
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cmath>
unsigned long long list[200000000]={0};
int main(){
    freopen("coin.in", "r", stdin);
    freopen("coin.out", "w", stdout);
    unsigned long long a,b,c=0;
    scanf("%llu %llu",&a,&b);
    unsigned long long MAX=a*b;
    for(unsigned long long i=0;i<=MAX;i++){
        for(unsigned long long j=0;j<=MAX;j++){
            list[a*i+b*j]=1;
        }
    }
    for(unsigned long long i=MAX;i>=1;i--){
        if(list[i]==0){
            printf("%llu\n",i);
            break;
        }
    }
}