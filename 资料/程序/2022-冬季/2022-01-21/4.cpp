/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 10:13:56
 * @LastEditTime: 2022-01-21 11:17:01
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    char in[100]={' '};
    int i=1;
    while(true){
        in[i]=getchar();
        if(in[i]=='\n'){
            in[i]=' ';
            i--;
            break;
        }
        i++;
    }
    for(;i>=0;i--){
        int j=i;
        for(;in[j]!=' ';j--){
        }
        for(int k=j+1;k<=i;k++){
            putchar(in[k]);
        }
        putchar(' ');
        i=j;
    }
}