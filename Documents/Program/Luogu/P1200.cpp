/***
 * @Author: Zi_Gao
 * @Date: 2022-01-27 13:17:01
 * @LastEditTime: 2022-01-27 13:22:04
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    int ch=getchar();
    int a=1,b=1;
    while(ch!='\n'){
        a*=ch-'A'+1;
        ch=getchar();
    }
    ch=getchar();
    while(ch!='\n'){
        b*=ch-'A'+1;
        ch=getchar();
    }
    if(a%47==b%47){
        printf("GO");
    }else{
        printf("STAY");
    }
}