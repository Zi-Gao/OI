/***
 * @Author: Zi_Gao
 * @Date: 2022-01-21 08:22:42
 * @LastEditTime: 2022-01-21 08:30:48
 * @LastEditors: Zi_Gao
 * @Description: 
 */
#include <iostream>
using namespace std;
int c;
int main(){

    cout << &c << endl;
    cout << c << endl;
    cout << *&c << endl;
    cout << sizeof(&c) << endl;
    return 0;
}