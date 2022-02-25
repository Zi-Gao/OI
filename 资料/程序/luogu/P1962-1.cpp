/***
 * @Author: Zi_Gao
 * @Date: 2022-01-23 20:16:35
 * @LastEditTime: 2022-01-23 20:24:23
 * @LastEditors: Zi_Gao
 * @Description: fibonacci
 */
#include <cstdio>
int main(){
    int in;
    scanf("%d",&in);
    unsigned long long int a=1,b=1;
    unsigned long long int out=0;
    for(unsigned long long int i=3;i<=in;i++){
        out=(a+b)%1000000007;
        a=b;
        b=out;
    }
    printf("%lld",out%1000000007);
}