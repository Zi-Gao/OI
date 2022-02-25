/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 15:16:22
 * @LastEditTime: 2022-01-21 21:02:23
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    int N=0;
    bool flag=true;
    int h=1;
    scanf("%d",&N);
    for(;h<N*N;){
        int t;
        scanf(" %d",&t);
        for(int i=0;i<t;i++){
            if(flag){
                putchar('0');
            }else{
                putchar('1');
            }
            if(h%N==0){
                putchar('\n');
            }
            h++;
        }
        if(flag){
            flag=false;
        }else{
            flag=true;
        }
    }
}