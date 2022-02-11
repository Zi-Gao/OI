/***
 * @Author: Zi_Gao
 * @Date: 2022-01-18 14:38:53
 * @LastEditTime: 2022-01-18 14:45:21
 * @LastEditors: Zi_Gao
 * @Description: 1-100的素数
 */
#include <cstdio>
#include <cmath>
int main(){
    for(int i=3;i<100;i+=2){
        bool flag = true;
        int jMax = sqrt(i);
        for(int j=2;j<=jMax;j++){
            if(i%j==0){
                flag = false;
                break;
            }
        }
        if(flag){
            printf("%d\n",i);
        }
    }
}
