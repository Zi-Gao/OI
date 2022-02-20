/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 16:51:17
 * @LastEditTime: 2022-01-19 16:53:46
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
using namespace std;
void jz(int a){

    if(a==1){
        printf("1");
        return;
    }
    jz(a/2);
    printf("%d",a%2);
}
int main(){
    jz(8);
	return 0;
}