/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 08:35:07
 * @LastEditTime: 2022-01-21 08:36:45
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    int n;
    scanf("%d",&n);
    long double S=0;
    for(int i=1;true;i++){
        S+=1.0/i;
        if(S>n){
            printf("%d",i);
            break;
        }
    }
}