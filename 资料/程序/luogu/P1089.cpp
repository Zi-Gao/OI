/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 21:12:37
 * @LastEditTime: 2022-01-21 21:23:18
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    int money=0;
    int cun=0;
    for(int i=1;i<=12;i++){
        money+=300;
        int n;
        scanf("%d",&n);
        money-=n;
        if(money<0){
            printf("-%d",i);
            return 0;
        }
        if(money>100){
            cun+=money/100;
            money=money%100;
        }
    }
    printf("%d",cun*120+money);
}