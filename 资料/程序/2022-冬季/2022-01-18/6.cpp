/***
 * @Author: Zi_Gao
 * @Date: 2022-01-18 10:54:39
 * @LastEditTime: 2022-01-18 11:18:22
 * @LastEditors: Zi_Gao
 * @Description: go to
 */
#include <cstdio>
#include <iostream>
using namespace std;
int fib(int n);
int main(){
    int i=0,sum=0;
    i=1;
    loop:
    sum+=i;
    i++;
    if(i<=100){
        goto loop;
    }
    cout<<sum<<endl;
	return 0;
}