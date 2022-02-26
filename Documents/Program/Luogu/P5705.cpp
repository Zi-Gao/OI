/***
 * @Author: Zi_Gao
 * @Date: 2022-02-01 21:29:12
 * @LastEditTime: 2022-02-01 21:41:39
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
char arr[100000];
int main(){
    int i=0;
    while(~scanf("%c",&arr[i])){
        // if(arr[i]=='\n'){
        //     break;
        // }
        i++;
    }
    while(i>=0){
        if((arr[i]>='0'&&arr[i]<='9')||(arr[i]=='.')){
            printf("%c",arr[i]);
        }
        i--;
    }
}