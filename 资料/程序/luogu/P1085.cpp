/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 08:29:39
 * @LastEditTime: 2022-01-21 08:34:23
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    int MAX=8;
    int day=0;
    for (int i = 0; i < 7; i++)
    {
        int t1,t2;
        scanf("%d %d",&t1,&t2);
        if(t1+t2>MAX){
            MAX=t1+t2;
            day=i+1;
        }
    }
    printf("%d",day);
}