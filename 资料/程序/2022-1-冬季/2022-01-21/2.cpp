/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 08:42:06
 * @LastEditTime: 2022-01-21 08:47:00
 * @LastEditors: Zi_Gao
 * @Description: 交换
 */
#include <cstdio>
void SWAP(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
int main() {
    int a,b;
    scanf("%d %d", &a, &b);
    SWAP(a,b);
    printf("%d %d",a,b);
}