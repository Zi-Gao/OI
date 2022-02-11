/***
 * @Author: Zi_Gao
 * @Date: 2022-01-18 08:03:32
 * @LastEditTime: 2022-01-18 10:10:07
 * @LastEditors: Zi_Gao
 * @Description: 运算符
 */
#include <cstdio>
#include <iostream>
using namespace std;
int main(){
    cout << ('a'=='b'&&!'c') << endl;
    int a;
    a=3*5,a*4;
    cout << a << endl;
    int x;
    x=(a=3,6*3);
    cout << x;

	return 0;
}