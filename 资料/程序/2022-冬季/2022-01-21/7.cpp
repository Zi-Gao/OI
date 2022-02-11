/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 14:28:27
 * @LastEditTime: 2022-01-21 14:37:14
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int sum(int array[],int n){
    for(int i=0;i<10-1;i++){
        *(array+1)=*array+*(array+1);
        array++;
    }
    return *array;
}
int main(){
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    printf("%d\n",sum(a,10));
}