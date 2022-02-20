/***
 * @Author: Zi_Gao
 * @Date: 2022-01-24 20:11:43
 * @LastEditTime: 2022-01-24 20:44:37
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <ctime>
#include <cstdlib>
#include <cstdio>
int main(){
    freopen("xor.in", "r", stdin);
    freopen("xor.out", "w", stdout);
    srand(time(NULL));
    printf("%d",rand()%20);
}