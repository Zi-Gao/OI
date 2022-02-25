/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 11:46:54
 * @LastEditTime: 2022-01-21 11:54:21
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    char t;
    int a;
    scanf("%d\n",&a);
    while(true){
        scanf("%c",&t);
        if(t == EOF){
            break;
        }
        if(t+a=='z'){
            putchar('a');
        }else{
            putchar(t+a);
        }

    }
}