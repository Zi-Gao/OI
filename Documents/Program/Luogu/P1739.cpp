/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 09:50:05
 * @LastEditTime: 2022-01-21 10:04:59
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
int main(){
    char in;
    int a=0;
    while(true){
        scanf("%c",&in);
        if(in=='('){
            a++;
        }else if(in==')'){
            a--;
        }
        if(a<0){
            break;
        }
        if(in=='@'){
            break;
        }
    }
    if(a==0){
        printf("YES");
    }
    else {
        printf("NO");
    }
    return 0;
}