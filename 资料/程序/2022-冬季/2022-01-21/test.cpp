/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 14:38:34
 * @LastEditTime: 2022-01-21 14:52:45
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <cstdlib>
int main(){
    int a[1]={0};
    int *p=a-3;
    int b[10]={0,1,2,3,4,5,6,7,8,9};
    for(int i=0;i<=20;p--){
        *p=0;
        i++;
    }
    for(int i=0;i<10;i++){
        printf("%d\n",b[i]);
    }
    system("pause");
}