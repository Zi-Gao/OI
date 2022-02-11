/***
 * @Author: Zi_Gao
 * @Date: 2022-01-18 10:27:27
 * @LastEditTime: 2022-01-18 10:36:04
 * @LastEditors: Zi_Gao
 * @Description: 成绩等级
 */
#include <cstdio>
int main(){
    double a;
    scanf("%lf",&a);
    int b = (int)a/10;
    switch(b){
        case 10:printf("A");break;
        case 9:printf("A");break;
        case 8:printf("B");break;
        case 7:printf("C");break;
        default:printf("D");
    }
    return 0;
}