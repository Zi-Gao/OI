/***
 * @Author: Zi_Gao
 * @Date: 2022-01-18 08:27:05
 * @LastEditTime: 2022-01-18 08:36:13
 * @LastEditors: Zi_Gao
 * @Description: 位运算
 */
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    int a=-3&5;
    cout << a << endl;//与运算
    cout << ~(-1) << endl;//取反
    // /*
    // while(~scanf("%d",&a)){//在读不到时停止 读不到时scanf()返回-1 ~(-1)=0停止
    //     //code
    // }
    // */
    a=15;
    a=a<<2;
    cout << a << endl;

	return 0;
}