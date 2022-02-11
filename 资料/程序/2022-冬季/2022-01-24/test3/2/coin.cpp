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
    unsigned long long a,b;
    scanf("%llu %llu",&a,&b);
    printf("%llu",a*b-a-b);
}