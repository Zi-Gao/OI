/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 14:37:18
 * @LastEditTime: 2022-01-21 14:38:21
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
using namespace std;
int main(){
    int a =256;
    const int *p=&a;
    *p=257;
    printf("%d\n",*p);
}