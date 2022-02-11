/***
 * @Author: Zi_Gao
 * @Date: 2022-01-19 19:17:00
 * @LastEditTime: 2022-01-19 19:41:56
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <cstdio>
#include <iostream>
using namespace std;
int f(int m,int n){
    if(m<=1||n<=0){
        return 1;
    }
    if(n>m){
        return f(m,m);
    }else{
        return f(m,n-1)+f(m-n,n);//f(m,n)=f(m,n-1)空盘子 f(m,n)=f(m-n,n)不空盘子
    }
    return 1;
}
int main(){
    printf("%d",f(7,3));
	return 0;
}