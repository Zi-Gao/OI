/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 09:28:16
 * @LastEditTime: 2022-01-21 09:28:17
 * @LastEditors: Zi_Gao
 * @Description: 数字反转
 */
#include <cstdio>
int main(){
    int in;
    scanf("%d",&in);
    int out=0;
    while(in){
        out=out*10+in%10;
        in/=10;
    }
    printf("%d",out);
    return 0;
}